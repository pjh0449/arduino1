#include <Servo.h>

Servo myservol; // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 90;// variable to store the servo position

 void setup () {
myservol. attach (9); // attaches the servo on pin 9 to the servo object
 }

 void loop () {
myservol.write (pos) ;// tell servo to go to position in variable 'po
delay (15) ; // waits 15 ms for the servo to reach the position
 }
