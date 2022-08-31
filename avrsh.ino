#include <Arduino.h>
#include "common.h"
#include "shell.h"
#include "script.h"

static AVRShell	shell(&Serial);
static ScriptEngine	scriptEngine;

void setup()
{
    scriptEngine.Init();	// initialize EEPROM variables
    shell.SetScriptEngine(&scriptEngine);

    // initialize serial:
    Serial.begin(57600);

    sei();
}

void loop()
{
    if (Serial.available() > 0) {
        String input = Serial.readString();
        shell.Process(input.c_str());
    }
}

ScriptEngine & appGetScriptEngine()
{
    return scriptEngine;
}

void WriteLine(const char * msg, uint8 doPrompt)
{
    while (pgm_read_byte(msg) != 0x00)
        Serial.print((char)pgm_read_byte(msg++));

    if (doPrompt)
        Serial.print(shell.Prompt());
}

void WriteRAM(const char * msg, uint8 doPrompt)
{
    Serial.print(msg);
    if (doPrompt)
        Serial.print(shell.Prompt());
}
