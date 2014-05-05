/*
  Simple example for receiving
  
  http://code.google.com/p/rc-switch/
  
  Need help? http://forum.ardumote.com
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int swtichPin = 13;
void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on inerrupt 0 => that is pin #2
  
  pinMode(swtichPin, OUTPUT);
  
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  digitalWrite(swtichPin, HIGH);
}

void loop() {
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
    
    if (value == 0) {
      Serial.print("Unknown encoding");
    } 
    else if (mySwitch.getReceivedValue() == 10) {
      digitalWrite(swtichPin, LOW); 
      Serial.println("0");
    }
    else if (mySwitch.getReceivedValue() == 11) {
      digitalWrite(swtichPin, HIGH); 
      Serial.println("1");
    }
    else {   

    }
  }
}
