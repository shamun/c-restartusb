#!/bin/bash
j=true
while $j
do
  for i in 0 1 2
  do
    tmp="/dev/video$i"
    if [ -e $tmp ]
    then
      foundon="/dev/video$i"
      j=false
    else
      echo "NO - camera found - restart the USB $i"
      echo ROOT_PASS | sudo -S /var/tmp/c-restartusb/restartusb
    fi
  done
done

echo "Camera - job is complete"

