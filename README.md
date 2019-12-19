# chicony-ir-toggle
This project aims to control the IR emitters of windows hello enabled IR cameras under Linux

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
chicony-ir-toggle <on|off>
```

## Confirmed devices 
Multiple newer lenovo laptops with windows hello e.g.
* Thinkpad T490s
* Yoga S740
* Thinkpad X1 Extreme Gen 2
