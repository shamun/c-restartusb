/**
  Restart - usb interfaces
  $ apt-get install libusb-dev 
  $ yum install libusb1-devel
  $ gcc -o kickusb /var/tmp/kickusb.c -lusb; chmod +x /var/tmp/kickusb
  $ ls /dev/video*; /var/tmp/kickusb ; ls /dev/video*
  /dev/video0  /dev/video2  /dev/video99
  reset 0x1c250c0 0 (USB Multimedia Keyboard)
  reset 0x1c262d0 0 (HD Pro Webcam C920)
  reset 0x1c294e0 0 (Elo TouchSystems 2216 AccuTouch� USB Touchmonitor Interface)
  reset 0x1c2a540 0 (Elo TouchSystems 2216 AccuTouch� USB Touchmonitor Interface)
  reset 0x1c2b5a0 -21 (EHCI Host Controller)
  reset 0x1c2c600 0 (EHCI Host Controller)
  reset 0x1c2d660 -21 (EHCI Host Controller)
  /dev/video0  /dev/video99

*/
#include <stdio.h>
#include <usb.h>

int main(void) {
  struct usb_bus *busses;
  usb_init();
  usb_find_busses();
  usb_find_devices();
  busses = usb_get_busses();
  struct usb_bus *bus;
  int c, i, a;
  for (bus = busses; bus; bus = bus->next) {
    struct usb_device *dev;
    int val;
    usb_dev_handle *junk;
    for (dev = bus->devices; dev; dev = dev->next) {
      char buf[1024];
      junk = usb_open ( dev );
      usb_get_string_simple(junk,2,buf,1023);
      if ( junk == NULL ){
        printf("Can't open %p (%s)\n", dev, buf );
      } else {
        val = usb_reset(junk);
        printf( "reset %p %d (%s)\n", dev, val, buf );
      }
      usb_close(junk);
    }
  }
}

