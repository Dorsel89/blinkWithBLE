#include "mbed.h"
#include "phyphoxBle.h"
#include <chrono>
#include <cstdint>


PinName LED = P0_17; //DISTANZ
//PinName LED = P0_4; //ELEHRE 

DigitalOut myLED(LED); 
Ticker blinkTicker;
int ledCounter=0;

void powerOn() {
    if(ledCounter==9){
        myLED=0;
        ledCounter=0;
        return;
    }
    ledCounter+=1;
    myLED=1;
}

int main() {

    myLED=1; //turn led off
    blinkTicker.attach(&powerOn,100ms);

    PhyphoxBLE::start("distanz");              // start BLE
    while (true) {                            // start loop.
        ThisThread::sleep_for(100ms);
    }
}
