#!/bin/bash

function start()
{
  pid=`ps -ef | grep -n 'dtnd -c' | grep -v grep | awk '{ print $2 }'`
  if [[ $pid ]]; then
    ps
    echo -e "\nDTN running ----------------------------------------\n" >> /home/minipc03/ibrdtn-imple/logs/dtnd.log 
  else
    dtnd -c /home/minipc03/ibrdtn-imple/settings 1> /home/minipc03/ibrdtn-imple/logs/dtnd.log 2>&1 &
    pid=`ps -ef | grep dtnd | grep -v grep | wc -l`
    if [[ $pid -ne 0 ]]; then
      sleep 2
      echo -e "\nDTN started ----------------------------------------\n" >> /home/minipc03/ibrdtn-imple/logs/dtnd.log
      sleep 2
    fi
  fi
}
function stop()
{
  pid=`ps -ef | grep -n 'dtnd -c' | grep -v grep | awk '{ print $2 }'`
  if [[ $pid ]]; then
    kill -9 $pid 2>/dev/null
    #or pkill -f dtnd 2>/dev/null
    sleep 1
    echo -e "\nDTN stopped ----------------------------------------\n" >> /home/minipc03/ibrdtn-imple/logs/dtnd.log
  fi
}

if [[ $1 == 'start' ]]; then
  start
elif [[ $1 == 'stop' ]]; then
  stop
elif [[ $1 == 'restart' ]]; then
  stop
  start
else
  echo 'Unrecognized option'
fi
