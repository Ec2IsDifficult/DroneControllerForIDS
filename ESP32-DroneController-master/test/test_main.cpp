#include <Arduino.h>
#include <unity.h>

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

void stupidTest(void)
{
    
    TEST_ASSERT_EQUAL(true, true);
}

void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);
    
    UNITY_BEGIN();    // IMPORTANT LINE!

    RUN_TEST(stupidTest);

    UNITY_END();
    
}