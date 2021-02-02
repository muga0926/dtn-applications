#!/bin/bash

cp ~/dtn-test/settings/dtnd_default.conf ~/dtn-test/settings/dtnd.conf

echo -n "Input host name: "
read hname
sed -i "s/\%hostname\%/$hname/" ~/settings/dtnd_default.conf

#echo -n "Input log path: "
#read lpath
#sed -i "s/\%logpath\%/$lpath/" ~/settings/dtnd_default.conf

#echo -n "Input bundle path: "
#read bpath
#sed -i "s/\%bundlepath\%/$bpath/" ~/settings/dtnd_default.conf

echo -n "Input interface name: "
read iname
sed -i "s/\%interfacename\%/$iname/" ~/settings/dtnd_default.conf
