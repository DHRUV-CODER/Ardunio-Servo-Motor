/*CIRCUIT-
 *POTENTIOMETER(10K)  ARDUINO UNO /  ARDUINO NANO /ARDUINO MINI 
 *    GROUND        ->            GROUND
 *    WIPER         ->            A0 TO A5 
 *     VCC          ->             VCC 5V
 *_________________
 *     SERVO-
 *  GROUND (BROWN)    ->            GROUND
 *    VCC (RED)       ->            VCC 5V
 *  SIGNAL(ORANGE)    ->      3, 5, 6, 9, 10 OR 11
*/
//NOTE- IF THE SERVO IS A 360* VARIANT,THIS CODE WILL MODIFY THE SPEED OF THE SERVO
#include <Servo.h>
#define servoPin 3 // define the pin of servo signal line(make sure to change 3 to the pin number in your circuit)
#define potPin   0 //analog pin used to connect the potentiometer
//(make sure to change it to the pin number in your circuit(without using the "A"prefix))
int potVal; // variable to read the potValue from the analog pin
Servo myservo; // create servo object to control a servo
void setup() {
 myservo.attach(servoPin); // attaches the servo on servoPin to the servo object
}
void loop() {
 potVal = analogRead(potPin); // reads the potValue of the potentiometer
 potVal = map(potVal, 0, 1023, 0, 180);// scale it to use it with the servo
 myservo.write(potVal); // sets the servo position
 delay(15); // waits for the servo to get there
}
