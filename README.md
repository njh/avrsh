# AVR Shell

Uploaded by nevdull on 2010-11-23 07:27:00 (rating 0 out of 5)

## Summary

This is a shell, like a traditional UNIX shell, that allows you to enter commands and it will respond in real-time, showing status of registers, ports, fuses, signature, calibrations, etc while allowing you to easily change the status of any pin or register in the system while the system is running.


Connection is 57600 8N1 via a serial terminal. I use AVR Terminal for communication. There are still more features to be added but this is the set for release 1. It currently is made for an AVR ATmega328P with a serial connection or FTDI connection to a COM port on the PC. The arduino works out of the box and any other m328p will with the additional requirements.


See the step-by-step setup and code at my instructable:  

 [http://www.instructables.com/id/AVRSH-A-Command-Interpreter-Shell-for-ArduinoAVR/](http://www.instructables.com/id/AVRSH-A-Command-Interpreter-Shell-for-ArduinoAVR)

## Building

This project is an Arduino sketch. Open `avrsh.ino` in the Arduino IDE, select
an ATmega328P board (e.g. **Arduino Uno** or **Arduino Nano**), and upload.

Then open the Serial Monitor at **57600 baud**, with the line ending set to
"Newline", "Carriage return" or "Both NL & CR", and type `help`.

From the command line:

    arduino-cli compile -b arduino:avr:uno .
    arduino-cli upload -b arduino:avr:uno -p <port> .

The code talks directly to ATmega328P registers, so other boards are not supported.

## Tags

- Complete code
- Arduino
