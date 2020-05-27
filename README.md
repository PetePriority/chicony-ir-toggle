# chicony-ir-toggle
This project aims to control the IR emitters of windows hello enabled IR cameras under Linux. See https://github.com/boltgolt/howdy/issues/269 for a discussion and background about the methods used.

## Installation

Using cmake
```
mkdir -p build
cd build
cmake ..
make
sudo make install
```

Using gcc
```
gcc main.c -o chicony-ir-toggle
```

Automatic install with ansible playbook on Fedora 31 on Lenovo X1 Gen 2
```
cd ./ansible
ansible-playbook enable_ir.yml
```

## Usage

```
chicony-ir-toggle [-d DEVICE] <on|off>
```
Default for DEVICE is `/dev/video2`. If this differs on your system, supply the `-d` command line parameter pointing to your video device.

## Confirmed devices 
Multiple newer lenovo laptops with windows hello e.g.
* Thinkpad T490s
* Yoga S740
* Thinkpad X1 Extreme Gen 2
* Thinkpad X1 Yoga (4th generation)
* XinPro (for alternative frame mode, see https://github.com/hillyu/chicony-ir-toggle.git)

