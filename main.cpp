
// Arduino AVR utils
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

/* Register map */

// When addressing I/O Registers as data space using LD and ST instructions, 0x20 must be added to these addresses.
const uint8_t register_offset = 0x20U;

// Direction register
uint8_t ddrb_register = 0x17U + register_offset;

// Output register
uint8_t portb_register = 0x18U + register_offset;

// Pin direction value
const uint8_t p1_led_pin = 0b00000010U;

// General timer register
uint8_t gtccr_register = 0x2CU + register_offset;

uint8_t tccr0a_register = 0x2AU + register_offset; 

// Timer register
uint8_t tcnt0_register = 0x32U + register_offset;

// General timer values
const uint8_t tcm_mask = 0b10000000U;
const uint8_t psr0_mask = 0b00000001U;

static inline uint8_t register_read(uint8_t reg)
{
    return *reinterpret_cast<uint8_t *>(reg);
}

static inline void register_write(uint8_t reg, uint8_t val)
{
    *reinterpret_cast<uint8_t *>(reg) = val;
}

int main (void)
{
    // Set digital I/O on port B to output
    register_write(ddrb_register, p1_led_pin);

    // Create a timer
    register_write(gtccr_register, register_read(gtccr_register) | tcm_mask | psr0_mask);

    // Bring timer out of reset
    register_write(gtccr_register, register_read(gtccr_register) & ~psr0_mask);

    register_write(tccr0a_register, 0);

    // What is our timer at?
    uint8_t volatile timer_val = register_read(tcnt0_register);

    // TODO: create a timer like so: https://www.gadgetronicx.com/attiny85-timer-tutorial-generating-time-delay-interrupts/

    for (;;)
    {
        // Toggle High
        register_write(portb_register, register_read(portb_register) | p1_led_pin);

        // Delay with timer
        timer_val = register_read(tcnt0_register); // What is our timer at

        // Toggle Low 
        register_write(portb_register, register_read(portb_register) & ~p1_led_pin);
    }
#endif
    printf("Print something!");

    return 0;
}