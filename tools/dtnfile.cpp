/*
 * dtnfile.cpp
 *
 * Copyright (C) 2021 IBR, TU Braunschweig
 * Made by: Johannes Morgenroth <morgenroth@ibr.cs.tu-bs.de>
 * 
 * DTN file creator for studying...
 * This file is modified from dtnconvert.cpp
 * Written-by: Min Wook Kang <goodlookmw@gmail.com> <muga0926@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "config.h"

#include <ibrdtn/data/Serializer.h>
#include <ibrdtn/data/PayloadBlock.h>
#include <ibrdtn/data/Bundle.h>
#include <ibrdtn/data/EID.h>

#include <ibrcommon/data/BLOB.h>
#include <ibrcommon/data/File.h>

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <unistd.h>
#include "io/TarUtils.h"

void print_help()
{
	std::cout << "-- dtnfile (DTN) --" << std::endl;
	std::cout << "Syntax: dtnfile [options]"  << std::endl << std::endl;
	std::cout << "* optional parameters *" << std::endl;
	std::cout << " -h               Display this text" << std::endl;
	std::cout << " -p               Read bundle data and print out some information" << std::endl;
	std::cout << " -c               Create a bundle" << std::endl;
	std::cout << std::endl;
	std::cout << "* options when creating a bundle *" << std::endl;
	std::cout << " -f               file path" << std::endl;
}

int main(int argc, char** argv)
{
	int opt = 0;
	int working_mode = 0;
	std::string _conf_file_path;

	while((opt = getopt(argc, argv, "hpc:l:")) != -1)
	{
		switch (opt)
		{
		case 'h':
			print_help();
			// Deleted break;
			return (EXIT_SUCCESS);

		case 'p':
			working_mode = 1;
			break;

		case 'c':
			working_mode = 2;
			break;

		case 'f':
			_conf_file_path = atoi(optarg);
			break;

		default:
			std::cout << "unknown command" << std::endl;
			return -1;
		}
	}

	if (working_mode == 0)
	{
		print_help();
		return -1;
	}

	switch (working_mode)
	{
		case 1:
		{
			dtn::data::DefaultDeserializer dd(std::cin);
			dtn::data::Bundle b;
			dd >> b;

			std::cout << "flags: " << std::hex << std::setw( 2 ) << std::setfill( '0' ) << b.procflags.toString() << std::dec << std::endl;
			std::cout << "source: " << b.source.getString() << std::endl;
			std::cout << "destination: " << b.destination.getString() << std::endl;
			std::cout << "timestamp: " << b.timestamp.toString() << std::endl;
			std::cout << "sequence number: " << b.sequencenumber.toString() << std::endl;
			std::cout << "lifetime: " << b.lifetime.toString() << std::endl;

			if (b.get(dtn::data::PrimaryBlock::FRAGMENT)) {
				std::cout << "fragment offset: " << b.fragmentoffset.toString() << std::endl;
				std::cout << "app data length: " << b.appdatalength.toString() << std::endl;
			}

			const dtn::data::PayloadBlock &pblock = b.find<dtn::data::PayloadBlock>();
			ibrcommon::BLOB::Reference ref = pblock.getBLOB();

			// this part is protected agains other threads
			std::cout << "payload size: " << ref.size() << std::endl;
			break;
		}

		case 2:
		{
			dtn::data::DefaultDeserializer dd(std::cin);
			dtn::data::Bundle b;
			dd >> b;

			const dtn::data::PayloadBlock &pblock = b.push_back<dtn::data::PayloadBlock>();
			ibrcommon::BLOB::Reference ref = pblock.getBLOB();

			// this part is protected agains other threads
			{
				ibrcommon::BLOB::iostream stream = ref.iostream();
				io::TarUtils::read(_conf_file_path, *stream);
				//(*stream) << std::cin.rdbuf();
			}
			std::cout << "Files are created in " << _conf_file_path << std::endl;
			break;
		}
	}

	return 0;
}
