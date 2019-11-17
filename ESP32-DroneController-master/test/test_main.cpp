/*
Documentation:
https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/unit-tests.html
https://docs.platformio.org/en/latest/tutorials/core/unit_testing_blink.html#tutorial-unit-testing-blink
https://docs.platformio.org/page/plus/unit-testing.html
*/

#include <Arduino.h>
#include <unity.h>


void setUp(void) {
    //set stuff up here
}

// void tearDown(void) {
// // clean stuff up here
// }


void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN();    // Start unittesting
    
    UNITY_END(); // Stop unittesting
    
}

void loop()
{
    
}