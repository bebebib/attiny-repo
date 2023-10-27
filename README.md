# AT Tiny Exploration Project
Messing with drivers and peripherals of the attiny85

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
Installation of avr-dude required: https://www.microchip.com/en-us/tools-resources/develop/microchip-studio/gcc-compilers
Download the AVR 8 bit toolchain for windows (or your OS). Extract the zip somewhere and add the following to your PATH variable (path here may differ depending on where you download it.)
- C:\dev\avr8-gnu-toolchain-win32_x86_64\bin
Note that this also downloads some avr build tools

# Old Notes
https://www.amazon.com/gp/product/B0836WXQQR/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&th=1
AiTrip 5pcs Digispark Kickstarter Attiny85 General Micro USB Development Board for Arduino ^^^^
-	Drivers for dev board
o	https://github.com/digistump/DigistumpArduino/releases
o	Digistump.drivers
o	Dpinst64.exe
o	Shows up as “microchip tools” -> digispark bootloader!
-	In Arduino, download digispark boards
o	http://digistump.com/wiki/digispark/tutorials/connecting
o	^^ good link
o	https://www.youtube.com/watch?v=MmDBvgrYGZs
o	^^ vid
 

In Arduino, first upload, then plug in device, should upload! Works!!!!

I wanna program this thing with a debugger! GCC !!! I do not want to use Arduino…. I can… but I DO NOT WANT TOOOOO!!!!!!
https://learn.sparkfun.com/tutorials/tiny-avr-programmer-hookup-guide/all
https://learn.sparkfun.com/tutorials/pocket-avr-programmer-hookup-guide#using-avrdude-via-command-line
Prob need avrdude….
Already have it in arduino !!!!!
C:\Program Files (x86)\Arduino\hardware\tools\avr\bin
C:\Program Files (x86)\Arduino\hardware\tools\avr\etc
^^ needed for conf
^^ add to path
I have USBtinyISP !!!! How do I hook up to attiny85 ??
https://shallowsky.com/blog/hardware/attiny85-c.html
 
With USB board

 
Connect to the tiny board with the command
> avrdude -c usbtiny -p attiny85

https://electronut.in/getting-started-with-attiny85-avr-programming/
^ c program and makefile link
With makefile and main.c …. Do “make flash” and it should flash !
Debugging AtTiny85 !!
https://github.com/felias-fogg/dw-link/blob/master/docs/manual.md
^^ need an Arduino…
Clone https://github.com/felias-fogg/dw-link and flash the sketch onto an Arduino
 
Now use avr-gdb!
https://github.com/felias-fogg/dw-link/blob/master/docs/manual.md
^^ good guide for debugging

When debugging.... target remote COM8
load
break main
c
