# dtn-applications

This is code based on ibrdtn for studying.


# installation guide

> install libraries...
> * command line:

    ~$ sudo apt-get update
    ~$ sudo apt-get install devscripts build-essential libtool cdbs pkg-config debhelper autotools-dev \
    libnl-3-dev libnl-genl-3-dev libnl-route-3-dev libnl-nf-3-dev libnl-cli-3-dev libssl-dev libssl-dev \
    zlib1g-dev libsqlite3-dev libcurl4-openssl-dev libdaemon-dev libvmime-dev libarchive-dev

> download source code (ibrdtn and dtn-applications)
> * command line:

    ~$ git clone https://github.com/ibrdtn/ibrdtn.git ~/dtn-src
    ~$ git clone https://github.com/muga0926/dtn-applications.git ~/dtn-test

> copy dtnfile.cpp in ibrdtn source code
> * command line:

    ~$ mv ~/dtn-src/ibrdtn/tools/src/Makefile.am ~/dtn-test/backup/
    ~$ cp ~/dtn-test/tools/* ~/dtn-src/ibrdtn/tools/src/
 
> installation ibrdtn
> * command line:

    ~$ cd ~/dtn-src/ibrdtn
    ~$ bash autogen.sh
    ~$ ./configure
    ~$ make
    ~$ sudo make install
    ~$ sudo ldconfig

> excutable files permission
> * command line:

    ~$ cd ~/dtn-test/executable
    ~$ chmod u+x dtnd.sh
    ~$ chmod u+x setconf.sh

> input host and interface name
> * ex) Input host name: 2001:14:126:564:30:ae:8d52:aedc:66a7
> * ex) Input interface name: wlan0
> * command line:

    ~$ setconf.sh

> excute ibrdtn daemon
> * dtnd.sh [option]
> * ex) dtnd.sh start
> * command line:

    ~$ dtnd.sh start

