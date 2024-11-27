# zakki_driver

```sh
# compile
$ make

# install device driver
$ make install
$ sudo mknod -m 666 /dev/zakki c $(cat /proc/devices | grep zakki | cut -d ' ' -f 1) 0

# test
$ echo 0 > /dev/zakki
$ sudo dmesg | tail

# uninstall device driver
$ make uninstall
$ sudo rm /dev/zakki

```
