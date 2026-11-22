# AVR Shell

[![CI](https://github.com/njh/avrsh/actions/workflows/build.yml/badge.svg)](https://github.com/njh/avrsh/actions/workflows/build.yml)

A command shell for the ATmega328P, like a tiny UNIX shell over the serial port.
Type commands to see the state of registers, ports and fuses in real time, and
change any pin or register while the system is running.

AVR Shell was written by B. Gian James in 2009 and published on the
[AVR Freaks / Atmel community site](https://community.atmel.com/projects/avr-shell)
and as an [Instructable](https://www.instructables.com/id/AVRSH-A-Command-Interpreter-Shell-for-ArduinoAVR/).
This version has been ported to build with the Arduino IDE and Arduino core.

## Hardware

Any ATmega328P board, such as the **Arduino Uno** or **Arduino Nano**. The code
talks directly to ATmega328P registers, so other chips are not supported.

## Building

Open `avrsh.ino` in the Arduino IDE, select your board, and upload.

From the command line, using the build profiles in `sketch.yaml`:

    arduino-cli compile --profile uno .
    arduino-cli upload --profile uno -p <port> .


## Connecting

The shell runs at **57600 baud, 8N1**.

- **Arduino Serial Monitor:** set the baud rate to 57600 and the line ending to
  "Newline", "Carriage return" or "Both NL & CR".
- **minicom:** `minicom -D <port> -b 57600`. The shell doesn't echo what you type
  yet, so turn on local echo with Ctrl-A E.

Type `help` for the full list of commands.

## Commands

| Command | Description |
|---|---|
| `help` or `menu` | Show the help menu |
| `set pin <pin> input\|output` | Set a pin's direction, e.g. `set pin PB5 output` |
| `write pin <pin> high\|low` | Write to a digital pin |
| `read pin <pin>` | Read a digital pin |
| `read lfuse\|hfuse\|efuse\|lock` | Read the fuse or lock bits |
| `fcpu` | Show the CPU frequency |
| `timer start\|stop` | Time an interval in seconds |
| `powerup` / `powerdown adc\|spi\|uart\|twi\|all` | Power peripherals up or down |
| `clock ckdiv1`…`ckdiv256` | Change the CPU clock prescaler (this also changes the serial baud rate) |
| `passwd <password>` / `auth <password>` | Set, or authorise against, a root password stored in EEPROM |
| `print registers\|variables` | List the known registers or saved variables |
| `echo %REGISTER` / `echo $VARIABLE` | Show a register or variable |
| `%REGISTER[bit] = 1\|0` | Set or clear a bit in a register |
| `$VARIABLE = <value>` | Store a value in an EEPROM variable |

Pins use their AVR port names, `PB0`–`PB7`, `PC0`–`PC6` and `PD0`–`PD7`.
On an Uno, the built-in LED is `PB5`.

## Licence

BSD licence, copyright (c) 2009 Barry James. See [LICENSE.txt](LICENSE.txt).
