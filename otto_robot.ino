#include <Otto.h>
Otto Otto; 

#define LeftLeg 2 
#define RightLeg 3
#define LeftFoot 4 
#define RightFoot 5 
#define Buzzer  6 
#define Trigger 8 // ultrasonic sensor trigger pin
#define Echo 7 // ultrasonic sensor echo pin

long ultrasound() {
   long duration, distance;
   digitalWrite(Trigger,LOW);
   delayMicroseconds(2);
   digitalWrite(Trigger, HIGH);
   delayMicroseconds(10);
   digitalWrite(Trigger, LOW);
   duration = pulseIn(Echo, HIGH);
   distance = duration/58;
   return distance;
}


void setup() {
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer); 
  pinMode(Trigger, OUTPUT); 
  pinMode(Echo, INPUT); 

}

void loop() {
    if (ultrasound() <= 15) {
      Otto.sing(S_surprise);
      Otto.playGesture(OttoConfused);
      Otto.walk(3,8000,-1); // BACKWARD x2
      Otto.turn(3,1000,1); // LEFT x3
    }
    Otto.walk(1,1000,1); // FORWARD x1

}
