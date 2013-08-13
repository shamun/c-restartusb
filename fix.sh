#!/bin/bash
j=true
while $j
do
  full=false
  for i in 0 1 2
  do
    tmp="/dev/video$i"
    if [ -e $tmp ]
    then
      echo "/dev/video$i"
      j=false
      break
    else
      echo "[NO]: USB $i"
      full=true
    fi
  done

  if [ $full == true ]
  then
    echo r | sudo -S /var/tmp/c-restartusb/restartusb
    echo "[NO]: Camera available after scanning total camera: $full, resetting now."
    sleep 10
  fi

done

echo "Camera - job is complete"

