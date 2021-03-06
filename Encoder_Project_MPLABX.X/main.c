#include <main.h>

#byte trisb = getenv("SFR:TRISB")

#define mClock PIN_D2
#define mDirectoin PIN_B7
#define mEnable PIN_B8

union uData {
    int i;
    float f;
    char str[20];
};

union myAddress {
    int8 LOWbyte;
    int8 Highbyte;
    int16 MYLocalAddress;
};

union uData Mydata;
union myAddress UseAdd;
int8 inputData;

void main() {

    setup_oscillator(OSC_INTERNAL);
    SETUP_ADC_PORTS(NO_ANALOGS);
    MYdata.i = 1;
    UseAdd.MYLocalAddress = 100;
    
    setup_timer1(TMR_INTERNAL | TMR_DIV_BY_1, 600);
    setup_timer2(TMR_INTERNAL | TMR_DIV_BY_1, 300);

    enable_interrupts(INT_TIMER1);
    enable_interrupts(INT_TIMER2);
    disable_interrupts(INT_TIMER1);
    disable_interrupts(INT_TIMER2);
    enable_interrupts(INTR_GLOBAL);

    spi_xfer(MT1, 0x08);

    while (TRUE) {
        output_toggle(PIN_E0);
        output_toggle(PIN_E1);
        output_toggle(PIN_E2);
        output_toggle(PIN_E3);
        output_toggle(PIN_B2);
                output_toggle(mClock);
                output_toggle(mDirectoin);
                output_toggle(mEnable);
        delay_us(37);
        delay_ms(100);
        
        //inputData = spi_xfer(MT1);
        if (inputData == 0x08) {
            output_high(mClock);
        }
    }
}

#INT_TIMER1

void isrTimer1() {
    clear_interrupt(INT_TIMER1);
    output_high(mClock);
    set_timer1(600);
    enable_interrupts(INT_TIMER2);
    set_timer2(300);
}
#INT_TIMER2

void Timer2() {
    clear_interrupt(INT_TIMER2);
    disable_interrupts(INT_TIMER2);
    output_low(mClock);
}