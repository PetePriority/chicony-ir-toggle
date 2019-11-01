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

## Usage

```
chicony-ir-toggle <on|off>
```

## Confirmed devices 
Multiple newer lenovo laptops with windows hello e.g.
* Thinkpad T490s
* Yoga S740
