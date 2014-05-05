/*
  Simple example for receiving
  
  http://code.google.com/p/rc-switch/
  
  Need help? http://forum.ardumote.com
*/

#include <RCSwitch.h>

#define OFF_CODE 500
#define ON_CODE  501

RCSwitch mySwitch = RCSwitch();
int swtichPin = 13;
int state, command_value;

void setup() {
  Serial.begin(9600);
  Serial.println("-BEGIN-");
  mySwitch.enableReceive(0);  // Receiver on inerrupt 0 => that is pin #2
  
  pinMode(swtichPin, OUTPUT);
  state = LOW;
  digitalWrite(swtichPin, state);
}

void loop() {
  if (mySwitch.available()) {
    command_value = mySwitch.getReceivedValue();
    Serial.print("GOT ");
    Serial.println(command_value);
  
    if (command_value == 0) {
      Serial.print("Unknown encoding");
    } 
    else if (state == HIGH && command_value == OFF_CODE) {
      state = LOW;
      digitalWrite(swtichPin, state);

    }
    else if (state == LOW && command_value == ON_CODE) {
      state = HIGH;
      digitalWrite(swtichPin, state); 
    }
    else if (command_value != ON_CODE && command_value != OFF_CODE) {
      Serial.println("INVALID CODE");
    }
    else {   
      Serial.println("NOPE");
    }
    delay(500);
  }
}
