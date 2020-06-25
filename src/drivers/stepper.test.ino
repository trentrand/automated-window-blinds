/**************************************************************************
 * 
 * ESP8266 NodeMCU stepper motor control with rotary encoder.
 * This is a free software with NO WARRANTY.
 * https://simple-circuit.com/
 *
 *************************************************************************/
 
// include Arduino stepper motor library
#include <Stepper.h>
 
// number of steps per one revolution is 2048 ( = 4096 half steps)
#define STEPS  2048
 
// stepper motor control pins
#define IN1   8   // IN1 is connected to NodeMCU pin D1 (GPIO5)
#define IN2   7    // IN2 is connected to NodeMCU pin D2 (GPIO4)
#define IN3   6    // IN3 is connected to NodeMCU pin D3 (GPIO0)
#define IN4   5    // IN4 is connected to NodeMCU pin D4 (GPIO2)
 
// initialize stepper library
Stepper stepper(STEPS, IN4, IN2, IN3, IN1);
 
void ICACHE_RAM_ATTR enc_read();
void setup(void) {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  stepper.setSpeed(10); // rpm
}
 
void loop() {
  stepper.step(20 * dir);
 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
 
  delay(100);
}
