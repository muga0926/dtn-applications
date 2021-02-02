# dtn-applications

This is code based on ibrdtn for studying.


# installation guide

> libraries:

    sudo apt-get update
    sudo apt-get install devscripts build-essential libtool cdbs pkg-config debhelper autotools-dev \
    libnl-3-dev libnl-genl-3-dev libnl-route-3-dev libnl-nf-3-dev libnl-cli-3-dev libssl-dev libssl-dev \
    zlib1g-dev libsqlite3-dev libcurl4-openssl-dev libdaemon-dev libvmime-dev libarchive-dev
    
end code block.

> ibrdtn and applications:

    git clone https://github.com/ibrdtn/ibrdtn.git ~/dtn-src
    git clone https://github.com/muga0926/dtn-applications.git ~/dtn-test
    
end code block.

> source code change:

    mv ~/dtn-src/ibrdtn/tools/Makefile.am ~/dtn-test/backup/
    cp ~/dtn-test/tools/* ~/dtn/ibrdtn/tools/
    
end code block.

> configuration:

    cd ~/dtn/ibrdtn
    bash autogen.sh
    ./configure
    make
    sudo make install
    sudo ldconfig
    
end code block.

> excutable files:

    cd ~/dtn-test/excutable
    chmod u+x dtnd.sh
    chmod u+x setconf.sh
    
end code block.



