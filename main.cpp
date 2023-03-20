
#include <avr/io.h>
#include <util/delay.h>

int main (void)
{
    // Set Data Direction to output on port B, pin 1:
    DDRB = 0b00000010;

    while (1) {
        // set PB3 high
        PORTB = 0b00000010;
        _delay_ms(500);
        // set PB3 low
        PORTB = 0b00000000;
        _delay_ms(500);
    }

    return 0;
}