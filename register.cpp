////////////////////////////////////////////////////////////////////////////
// Name: register.cpp
// Author: B. Gian James <gian@BattleDroids.net>
// Description: This file declares the scripting components that allow
//              the user to check registers in real-time.
//
// $Id: register.cpp,v 1.5 2009/09/02 12:55:17 gian Exp $
////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>
#include <string.h>
#include "common.h"
#include "register.h"


static const char pmPORTB[] PROGMEM = "PORTB";
static const char pmPORTC[] PROGMEM = "PORTC";
static const char pmPORTD[] PROGMEM = "PORTD";
static const char pmDDRD[] PROGMEM = "DDRD";
static const char pmDDRB[] PROGMEM = "DDRB";
static const char pmDDRC[] PROGMEM = "DDRC";
static const char pmPINB[] PROGMEM = "PINB";
static const char pmPINC[] PROGMEM = "PINC";
static const char pmPIND[] PROGMEM = "PIND";
static const char pmSREG[] PROGMEM = "SREG";
static const char pmGPIOR0[] PROGMEM = "GPIOR0";
static const char pmGPIOR1[] PROGMEM = "GPIOR1";
static const char pmGPIOR2[] PROGMEM = "GPIOR2";
static const char pmTCCR0B[] PROGMEM = "TCCR0B";
static const char pmOCR0A[] PROGMEM = "OCR0A";
static const char pmSPCR[] PROGMEM = "SPCR";
static const char pmACSR[] PROGMEM = "ACSR";
static const char pmMCUSR[] PROGMEM = "MCUSR";
static const char pmSPMCSR[] PROGMEM = "SPMCSR";
static const char pmCLKPR[] PROGMEM = "CLKPR";
static const char pmOSCCAL[] PROGMEM = "OSCCAL";
static const char pmEICRA[] PROGMEM = "EICRA";
static const char pmPCMSK1[] PROGMEM = "PCMSK1";
static const char pmTIMSK1[] PROGMEM = "TIMSK1";
static const char pmADCL[] PROGMEM = "ADCL";
static const char pmADCSRA[] PROGMEM = "ADCSRA";
static const char pmADMUX[] PROGMEM = "ADMUX";
static const char pmDIDR1[] PROGMEM = "DIDR1";
static const char pmTCCR1B[] PROGMEM = "TCCR1B";
static const char pmTCNT1L[] PROGMEM = "TCNT1L";
static const char pmTCNT1H[] PROGMEM = "TCNT1H";
static const char pmICR1L[] PROGMEM = "ICR1L";
static const char pmOCR1AL[] PROGMEM = "OCR1AL";
static const char pmOCR1AH[] PROGMEM = "OCR1AH";
static const char pmOCR1BL[] PROGMEM = "OCR1BL";
static const char pmTCCR2A[] PROGMEM = "TCCR2A";
static const char pmTCNT2[] PROGMEM = "TCNT2";
static const char pmOCR2B[] PROGMEM = "OCR2B";
static const char pmTWBR[] PROGMEM = "TWBR";
static const char pmTWAR[] PROGMEM = "TWAR";
static const char pmTWCR[] PROGMEM = "TWCR";
static const char pmUCSR0A[] PROGMEM = "UCSR0A";
static const char pmUCSR0C[] PROGMEM = "UCSR0C";
static const char pmUBRR0L[] PROGMEM = "UBRR0L";
static const char pmUDR0[] PROGMEM = "UDR0";
static const char pmTIFR0[] PROGMEM = "TIFR0";
static const char pmTIFR1[] PROGMEM = "TIFR1";
static const char pmTIFR2[] PROGMEM = "TIFR2";
static const char pmPCIFR[] PROGMEM = "PCIFR";
static const char pmEIFR[] PROGMEM = "EIFR";
static const char pmEIMSK[] PROGMEM = "EIMSK";
static const char pmEECR[] PROGMEM = "EECR";
static const char pmEEDR[] PROGMEM = "EEDR";
static const char pmEEARL[] PROGMEM = "EEARL";
static const char pmEEARH[] PROGMEM = "EEARH";
static const char pmGTCCR[] PROGMEM = "GTCCR";
static const char pmTCCR0A[] PROGMEM = "TCCR0A";
static const char pmTCNT0[] PROGMEM = "TCNT0";
static const char pmOCR0B[] PROGMEM = "OCR0B";
static const char pmSPDR[] PROGMEM = "SPDR";
static const char pmSMCR[] PROGMEM = "SMCR";
static const char pmMCUCR[] PROGMEM = "MCUCR";
static const char pmWDTCSR[] PROGMEM = "WDTCSR";
static const char pmPRR[] PROGMEM = "PRR";
static const char pmPCICR[] PROGMEM = "PCICR";
static const char pmPCMSK0[] PROGMEM = "PCMSK0";
static const char pmTIMSK0[] PROGMEM = "TIMSK0";
static const char pmTIMSK2[] PROGMEM = "TIMSK2";
static const char pmADCH[] PROGMEM = "ADCH";
static const char pmADCSRB[] PROGMEM = "ADCSRB";
static const char pmDIDR0[] PROGMEM = "DIDR0";
static const char pmTCCR1A[] PROGMEM = "TCCR1A";
static const char pmTCCR1C[] PROGMEM = "TCCR1C";
static const char pmICR1H[] PROGMEM = "ICR1H";
static const char pmOCR1BH[] PROGMEM = "OCR1BH";
static const char pmTCCR2B[] PROGMEM = "TCCR2B";
static const char pmOCR2A[] PROGMEM = "OCR2A";
static const char pmASSR[] PROGMEM = "ASSR";
static const char pmTWSR[] PROGMEM = "TWSR";
static const char pmTWDR[] PROGMEM = "TWDR";
static const char pmTWAMR[] PROGMEM = "TWAMR";
static const char pmUCSR0B[] PROGMEM = "UCSR0B";
static const char pmUBRR0H[] PROGMEM = "UBRR0H";

// If you really need to conserve RAM, you can put each of these strings
// individually into program memory and then put the array there, too.
// Entered strings and struct array into PROGMEM 8.30.09 -gian
const RegisterVars
Register::Registers[] PROGMEM =
{
    { &PORTB, pmPORTB }, { &TIFR0, pmTIFR0 },
    { &PORTC, pmPORTC }, { &TIFR1, pmTIFR1 },
    { &PORTD, pmPORTD }, { &TIFR2, pmTIFR2 },
    { &DDRD,  pmDDRD},   { &PCIFR, pmPCIFR },
    { &DDRB,  pmDDRB},   { &EIFR,  pmEIFR},
    { &DDRC,  pmDDRC},   { &EIMSK, pmEIMSK },
    { &PINB,  pmPINB},   { &EECR,  pmEECR},
    { &PINC,  pmPINC},   { &EEDR, pmEEDR },
    { &PIND,  pmPIND},
    { &SREG,  pmSREG},   { &EEARL, pmEEARL },
    { &GPIOR0, pmGPIOR0 }, { &EEARH, pmEEARH },
    { &GPIOR1,  pmGPIOR1}, { &GTCCR, pmGTCCR },
    { &GPIOR2,  pmGPIOR2}, { &TCCR0A, pmTCCR0A },
    { &TCCR0B, pmTCCR0B}, { &TCNT0, pmTCNT0 },
    { &OCR0A, pmOCR0A }, { &OCR0B, pmOCR0B },
    { &SPCR, pmSPCR }, { &SPDR, pmSPDR },
    { &ACSR, pmACSR }, { &SMCR, pmSMCR },
    { &MCUSR, pmMCUSR }, { &MCUCR, pmMCUCR },
    { &SPMCSR,pmSPMCSR  }, { &WDTCSR, pmWDTCSR },
    { &CLKPR, pmCLKPR }, { &PRR, pmPRR },
    { &OSCCAL,pmOSCCAL  }, { &PCICR, pmPCICR },
    { &EICRA, pmEICRA }, { &PCMSK0, pmPCMSK0 },
    { &PCMSK1, pmPCMSK1 }, { &TIMSK0, pmTIMSK0 },
    { &TIMSK1, pmTIMSK1 }, { &TIMSK2, pmTIMSK2 },
    { &ADCL, pmADCL }, { &ADCH, pmADCH },
    { &ADCSRA, pmADCSRA }, { &ADCSRB, pmADCSRB },
    { &ADMUX,  pmADMUX}, { &DIDR0, pmDIDR0 },
    { &DIDR1, pmDIDR1 }, { &TCCR1A, pmTCCR1A },
    { &TCCR1B, pmTCCR1B }, { &TCCR1C, pmTCCR1C },
    { &TCNT1L, pmTCNT1L },
    { &TCNT1H, pmTCNT1H },
    { &ICR1L, pmICR1L }, { &ICR1H, pmICR1H },
    { &OCR1AL, pmOCR1AL },
    { &OCR1AH, pmOCR1AH },
    { &OCR1BL, pmOCR1BL }, { &OCR1BH, pmOCR1BH },
    { &TCCR2A, pmTCCR2A }, { &TCCR2B, pmTCCR2B },
    { &TCNT2, pmTCNT2 }, { &OCR2A, pmOCR2A },
    { &OCR2B, pmOCR2B }, { &ASSR, pmASSR },
    { &TWBR, pmTWBR }, { &TWSR, pmTWSR },
    { &TWAR, pmTWAR }, { &TWDR, pmTWDR },
    { &TWCR, pmTWCR}, { &TWAMR, pmTWAMR },
    { &UCSR0A, pmUCSR0A }, { &UCSR0B, pmUCSR0B },
    { &UCSR0C, pmUCSR0C },
    { &UBRR0L, pmUBRR0L }, { &UBRR0H, pmUBRR0H },
    { &UDR0, pmUDR0 },
    { NULL, NULL }
};

void
Register::WriteRegister(uint8 * reg)
{
    char buff[30];
    uint8 byte[8];
    for(uint8 x = 0; x < 8; x++) {
        if (BCHK(*reg,x))
            byte[(7-x)] = 1;
        else
            byte[(7-x)] = 0;
    }
    sprintf_P(buff,PSTR("(0x%x) set to [%d%d%d%d%d%d%d%d]"),
              *reg,byte[0],byte[1],byte[2],byte[3],byte[4],byte[5],byte[6],byte[7]);
    WriteRAM(buff,0);

}

char *
Register::getRegNameFromPgmSpace(uint8 idx)
{
    const RegisterVars * reg = &Registers[idx];
    char * rname = (char*)pgm_read_word(&reg->name);
    return rname;
}

void
Register::PrintRegisters()
{
    uint8 x = 1;
    char buff[60];
    WriteLine(PSTR("I know about the following registers:\r\n"),0);
    char * rname = getRegNameFromPgmSpace(x);
    char crname[7];
    while(rname != NULL) {
        strcpy_P(crname,rname);
        sprintf_P(buff,PSTR("%-7s    "),crname);
        WriteRAM(buff,0);
        if (!(x % 6))
            WriteLine(PSTR("\r\n"),0);
        ++x;
        rname = getRegNameFromPgmSpace(x);
    }
    sprintf_P(buff,PSTR("%-7s     \r\n"),crname);
    WriteRAM(buff);
}

uint8 *
Register::GetRegisterByName(const char * n)
{
    uint8 x = 0;
    char * rname = getRegNameFromPgmSpace(x);

    while(rname != NULL) {
        const RegisterVars * reg = &Registers[x];
        if (!strcmp_P(n,rname))
            return (uint8*)pgm_read_byte(&reg->reg);
        ++x;
        rname = getRegNameFromPgmSpace(x);
    }
    return (uint8*)NULL;

}


