# AT Tiny Exploration Project
Messing with drivers and peripherals of the attiny85

- Required Software
    - [Arduino IDE](https://www.arduino.cc/en/software)
    - [AVR GCC Compiler and Debugger]( https://www.microchip.com/en-us/tools-resources/develop/microchip-studio/gcc-compilers)
    - [dw-link](https://github.com/felias-fogg/dw-link)

- Required Hardware
    - [ATtiny85 Development Board](https://www.amazon.com/gp/product/B0836WXQQR/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&th=1)
    - [Arduino Uno](https://store.arduino.cc/products/arduino-uno-rev3)
    - USB-A to USB-B cable
    - MCU jumper wires

## Build
To get the toolchain to work on this repo, you need to install the Arduino IDE and add the following to your path:
- C:\Program Files (x86)\Arduino\hardware\tools\avr\bin
- C:\Program Files (x86)\Arduino\hardware\tools\avr\etc
OS equivalent also applies

```
> cmake -DCMAKE_BUILD_TYPE:STRING=Debug -Bbuild -G Ninja
> cd build
> ninja
```

## Load / Debug
Download the AVR 8 bit toolchain for windows (or your OS). Extract the zip somewhere and add the following to your PATH variable (path here may differ depending on where you download it.)

- C:\dev\avr8-gnu-toolchain-win32_x86_64\bin

This gives you access to the `avr-gdb` executable , which is no longer packaged with the Arduino IDE install.

Next, in your clone of `dw-link`, you will want to upload the file `dwlink/dwlink.ino` to your Arduino Uno using the IDE. 

Next, make the following connections from the Arduino Uno to your ATTiny85 dev board using the jumper wires:

| Signal | Arduino Pin | ATtiny85 Pin |
|--------|-------------|--------------|
|Ground  |GND          |GND           |
|SDK     |D13          |P2            |
|MISO    |D12          |P1            |
|MOSI    |D11          |P0            |
|VCC     |D9           |VIN           |
|Reset   |D8           |P5            |

Now, when plugging in your Arduino, it should show up as a COM port on your device manager, and you should connect to it like so from the command line:

```
> avr-gdb -b 115200 build/main.elf
(gdb) target remote COM[X]
(gdb) load
(gdb) break main
(gdb) c
```

**NOTE**: Make sure that the "X" above is a COM number below 10, `avr-gdb` has had issues finding the COM number when it is above 10.

- [**dw-link Reference**](https://github.com/felias-fogg/dw-link/blob/master/docs/manual.md#dw-link)
- [**avr-gdb Reference**](https://github.com/felias-fogg/dw-link/blob/master/docs/manual.md#56-gdb-commands)

# Old Notes

## Traditional Bootloader Method
- Drivers for dev board
    - https://github.com/digistump/DigistumpArduino/releases
    - Digistump.drivers
    - Dpinst64.exe
    - Shows up as “microchip tools” -> digispark bootloader!
    - In Arduino, download digispark boards
        - http://digistump.com/wiki/digispark/tutorials/connecting
        - https://www.youtube.com/watch?v=MmDBvgrYGZs

## AVR Dude and ATTiny ISP Programmer
https://learn.sparkfun.com/tutorials/tiny-avr-programmer-hookup-guide/all
https://learn.sparkfun.com/tutorials/pocket-avr-programmer-hookup-guide#using-avrdude-via-command-line
https://shallowsky.com/blog/hardware/attiny85-c.html
 
Connect to the tiny board with the command
```
> avrdude -c usbtiny -p attiny85
```

Loading and flashing with ATtiny ISP programmer:
https://electronut.in/getting-started-with-attiny85-avr-programming/