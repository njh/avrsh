#ifndef _AVRSH_COMMON_H_
#define _AVRSH_COMMON_H_
////////////////////////////////////////////////////////////////////////////
/// Name: common.h
/// Author: B. Gian James  <gian@BattleDroids.net>
/// Description: Commonly used things n stuff.
///
/// $Id: common.h,v 1.6 2009/09/05 04:06:17 gian Exp $
////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <stdint.h>

// from AVR035: Efficient C Coding for AVR
#define BSET(ADDRESS,BIT) (ADDRESS |= (unsigned char)(1<<BIT))
#define BCLR(ADDRESS,BIT) (ADDRESS &= (unsigned char)~(1<<BIT))
#define BTOG(ADDRESS,BIT) (ADDRESS ^= (unsigned char)(1<<BIT))
#define BCHK(ADDRESS,BIT) (ADDRESS &  (unsigned char)(1<<BIT))

#define NUM_PINS 23

// Typedefs for shorthand
// I wonder how much time programmers around the world have lost from having
// to type "_t"...
typedef uint8_t		uint8;
typedef uint16_t	uint16;
typedef uint32_t	uint32;

typedef struct
{
    volatile uint8 *	port;
    volatile uint8 *	ddr;
    uint8				pin;
    const char *		name;

} PortPin;

const extern PortPin PortPins[] PROGMEM;


// Utility functions
uint8_t StringCopy(char *, const char *);

extern void WriteLine(const char *, uint8 = 1);
extern void WriteRAM(const char *, uint8 = 1);
class ScriptEngine;
extern ScriptEngine & appGetScriptEngine();



#endif	/* _AVRSH_COMMON_H_ */
