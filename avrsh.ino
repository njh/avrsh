////////////////////////////////////////////////////////////////////////////
// Name: avrsh.ino
// Description: Arduino sketch entry point for the AVR Shell.
//              Open the Serial Monitor at 57600 baud with a line ending of
//              "Newline", "Carriage return" or "Both NL & CR".
////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include "common.h"
#include "shell.h"
#include "script.h"

#define BAUD_RATE		57600
#define MAX_LINE_LEN	64

static AVRShell	shell(&Serial);
static ScriptEngine	scriptEngine;

static char		lineBuff[MAX_LINE_LEN];
static uint8	lineLen = 0;

void setup()
{
    scriptEngine.Init();	// initialize EEPROM variables
    shell.SetScriptEngine(&scriptEngine);

    Serial.begin(BAUD_RATE);
    Serial.print(shell.Prompt());
}

void loop()
{
    while (Serial.available() > 0) {
        char c = Serial.read();

        if (c == '\r' || c == '\n') {
            if (lineLen > 0) {
                lineBuff[lineLen] = '\0';
                shell.Process(lineBuff);
                lineLen = 0;
            }
        } else if (lineLen < (MAX_LINE_LEN - 1)) {
            lineBuff[lineLen++] = c;
        }
    }
}

ScriptEngine & appGetScriptEngine()
{
    return scriptEngine;
}

void WriteLine(const char * msg, uint8 doPrompt)
{
    Serial.print((const __FlashStringHelper *)msg);

    if (doPrompt)
        Serial.print(shell.Prompt());
}

void WriteRAM(const char * msg, uint8 doPrompt)
{
    Serial.print(msg);
    if (doPrompt)
        Serial.print(shell.Prompt());
}
