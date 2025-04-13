#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void) {
    DDRD = _BV(DDD2) | _BV(DDD3) | _BV(DDD4) | _BV(DDD5);

    /**
     * 0000 <- 
     * 0001
     * 0010
     * 0011
     * ...
     * current num start at 0
     * maintain the current number
     * in program loop, 
     * display number, 
     * if (current num == 1111 then break) set it to 0, else increment by 1
     * delay by 1 sec
     * 
     * How to display all at once
     * PORTD = currentNum
     * 
     * 00000000 0
     * 00000100 4
     * 00001000 8
     * 00001100 12
     * 00010000 16
     * 00010100 20
     * ...
     * 00111000
     * 00111100
     */

    uint8_t currentNum = 0;
    while(1) {
        PORTD = currentNum;
        _delay_ms(1000);
        if(currentNum == 60) {
            currentNum = 0;
        } else {
            currentNum += 4;
        }
    }
    return 0;
}