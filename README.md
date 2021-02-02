# dtn-applications

This is code based on ibrdtn for studying.


# installation guide

> library
This is a normal paragraph:

    sudo apt-get update
    sudo apt-get install devscripts build-essential libtool cdbs pkg-config debhelper autotools-dev \
    libnl-3-dev libnl-genl-3-dev libnl-route-3-dev libnl-nf-3-dev libnl-cli-3-dev libssl-dev libssl-dev \
    zlib1g-dev libsqlite3-dev libcurl4-openssl-dev libdaemon-dev libvmime-dev libarchive-dev
    
end code block.



git clone https://github.com/ibrdtn/ibrdtn.git ~/dtn-src
git clone https://github.com/muga0926/dtn-applications.git ~/dtn-test

mv ~/dtn-src/ibrdtn/tools/Makefile.am ~/dtn-test/backup/
cp ~/dtn-test/tools/* ~/dtn/ibrdtn/tools/

cd ~/dtn/ibrdtn
bash autogen.sh
./configure
make
sudo make install
sudo ldconfig

cd ~/dtn-test/excutable
chmod u+x dtnd.sh
chmod u+x setconf.sh
