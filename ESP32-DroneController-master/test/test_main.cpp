/*
Documentation:
https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/unit-tests.html
https://docs.platformio.org/en/latest/tutorials/core/unit_testing_blink.html#tutorial-unit-testing-blink
https://docs.platformio.org/page/plus/unit-testing.html
*/

#include <Arduino.h>
#include <unity.h>
#include <drone.cpp>
#include <joystick.cpp>
int pin1 = 5;
int pin2 = 34;
int pin3 = 35;
bool joystickActivated = false;
Joystick joystick(pin1, pin2, pin3);
Position joystickPosition = joystick.getPosition();

void test_flip_button_number(void) {
    TEST_ASSERT_EQUAL(23, BUTTON_FLIP);
}
void test_up_button_number(void){
    TEST_ASSERT_EQUAL(22, BUTTON_UP);
}
void test_down_button_number(void){
    TEST_ASSERT_EQUAL(4, BUTTON_DOWN);
}
void test_joystick_origo_position(void){
    TEST_ASSERT_EQUAL(0,joystick.getX());
}
void test_button_flip_pushDown(void){
    //The outer most button must be activated for this test to pass.
    TEST_ASSERT_EQUAL(LOW,digitalRead(BUTTON_FLIP));
}
void test_button_up_pushDown(void){
    //The middle button must be activated for this test to pass.
    TEST_ASSERT_EQUAL(LOW,digitalRead(BUTTON_UP));
}
void test_button_down_pushDown(void){
    //The inner button must be activated for this test to pass.
    TEST_ASSERT_EQUAL(LOW,digitalRead(BUTTON_DOWN));
}
void test_joystick_activated_forX(void){
    //Checks if the joystick is engaged in any way
    if(analogRead(pin2) < 2500 || analogRead(pin2) > 2900){
        joystickActivated = true;
    }
    TEST_ASSERT_TRUE(joystickActivated);
}
void test_joystick_activated_forY(void){
    //Checks if joystick is engaged in any way
    if(analogRead(pin3) < 2500 || analogRead(pin3) > 2900){
        joystickActivated = true;
    }
    TEST_ASSERT_TRUE(joystickActivated);
}


// void tearDown(void) {
// // clean stuff up here
// }

void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN();    // Start unittesting
    RUN_TEST(test_flip_button_number);
    RUN_TEST(test_up_button_number);
    RUN_TEST(test_down_button_number);
    RUN_TEST(test_joystick_origo_position);
    RUN_TEST(test_button_flip_pushDown);
    RUN_TEST(test_button_up_pushDown);
    RUN_TEST(test_button_down_pushDown);
    RUN_TEST(test_joystick_activated_forX);
    RUN_TEST(test_joystick_activated_forY);
    UNITY_END(); // Stop unittesting
    
}

void loop()
{
    
}