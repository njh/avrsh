////////////////////////////////////////////////////////////////////////////////
/// Name: common.cpp
/// Author: B. Gian James  <gian@BattleDroids.net>
/// Description: Definitions for common things.
///
// $Id: common.cpp,v 1.4 2009/09/02 12:55:17 gian Exp $
////////////////////////////////////////////////////////////////////////////////
#include "common.h"
#include <string.h>
#include <stdlib.h>

static const char pmPB0[] PROGMEM = "PB0";
static const char pmPB1[] PROGMEM = "PB1";
static const char pmPB2[] PROGMEM = "PB2";
static const char pmPB3[] PROGMEM = "PB3";
static const char pmPB4[] PROGMEM = "PB4";
static const char pmPB5[] PROGMEM = "PB5";
static const char pmPB6[] PROGMEM = "PB6";
static const char pmPB7[] PROGMEM = "PB7";
static const char pmPC0[] PROGMEM = "PC0";
static const char pmPC1[] PROGMEM = "PC1";
static const char pmPC2[] PROGMEM = "PC2";
static const char pmPC3[] PROGMEM = "PC3";
static const char pmPC4[] PROGMEM = "PC4";
static const char pmPC5[] PROGMEM = "PC5";
static const char pmPC6[] PROGMEM = "PC6";
static const char pmPD0[] PROGMEM = "PD0";
static const char pmPD1[] PROGMEM = "PD1";
static const char pmPD2[] PROGMEM = "PD2";
static const char pmPD3[] PROGMEM = "PD3";
static const char pmPD4[] PROGMEM = "PD4";
static const char pmPD5[] PROGMEM = "PD5";
static const char pmPD6[] PROGMEM = "PD6";
static const char pmPD7[] PROGMEM = "PD7";

const PortPin PortPins[] = {
    { &PORTB, &DDRB, PINB0, pmPB0},
    { &PORTB, &DDRB, PINB1, pmPB1},
    { &PORTB, &DDRB, PINB2, pmPB2},
    { &PORTB, &DDRB, PINB3, pmPB3},
    { &PORTB, &DDRB, PINB4, pmPB4},
    { &PORTB, &DDRB, PINB5, pmPB5},
    { &PORTB, &DDRB, PINB6, pmPB6},
    { &PORTB, &DDRB, PINB7, pmPB7},
    { &PORTC, &DDRC, PINC0, pmPC0},
    { &PORTC, &DDRC, PINC1, pmPC1},
    { &PORTC, &DDRC, PINC2, pmPC2},
    { &PORTC, &DDRC, PINC3, pmPC3},
    { &PORTC, &DDRC, PINC4, pmPC4},
    { &PORTC, &DDRC, PINC5, pmPC5},
    { &PORTC, &DDRC, PINC6, pmPC6},
    { &PORTD, &DDRD, PIND0, pmPD0},
    { &PORTD, &DDRD, PIND1, pmPD1},
    { &PORTD, &DDRD, PIND2, pmPD2},
    { &PORTD, &DDRD, PIND3, pmPD3},
    { &PORTD, &DDRD, PIND4, pmPD4},
    { &PORTD, &DDRD, PIND5, pmPD5},
    { &PORTD, &DDRD, PIND6, pmPD6},
    { &PORTD, &DDRD, PIND7, pmPD7}
};

uint8_t
StringCopy(char * dest, const char * source)
{
    uint8_t x;
    for (x = 0; x < strlen(source); x++)
        dest[x] = source[x];
    dest[x] = '\0';
    return x;
}

