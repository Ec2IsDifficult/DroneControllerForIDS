#include <Arduino.h>
#include <string.h>
#include <drone.h>
#include <joystick.h>

String ssid = "TELLO-FE2F93";
String password = "";

Drone drone(ssid, password);
Joystick joystick(5, 34, 35); // pins: btn, x, y

void setup()
{
  Serial.begin(9600);

  drone.joystick = &joystick; 

  for (size_t i = 0; i < 5; i++)
  {
    Serial.println(i);
    delay(1000);
  }

  joystick.addButtonListener(&drone);
  drone.setIp ("192.168.10.1");
  drone.connect();
  

  
}

void loop()
{
  joystick.loop();
  drone.loop();;
} 