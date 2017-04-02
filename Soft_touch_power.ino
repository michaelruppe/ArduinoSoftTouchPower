/* 
 * DEMO: Soft touch power button
 *
 * Michael Ruppe, March 2014
 * http://sn63.ghost.io/
 * Demonstrates the uC controlled soft touch power circuit detailed in https://youtu.be/0IjJH3ksqfs
 *
 */ 

#define    SENSE 2       // Sense input to detect when power button is pressed. Pressed = HIGH
#define    DRIVE 7       // Controls the power FETS. HIGH = Circuit is powered. Write:LOW to turn off circuit.
#define HOLDTIME 1000 // The length, in milliseconds, the user must hold the power button to power off the circuit.

int control = 0;
void setup() {
  //All pins are input by default, so pinMode(SENSE,INPUT) is not necessary here
  pinMode(DRIVE,OUTPUT);
  digitalWrite(DRIVE,HIGH);
  
  //The LED in pin 13 will be our 'pseudo power-indicator'
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
}

void loop() {
  long unsigned int start;  // Used for timing
  long unsigned int now;    // Used for timing
 
  if(digitalRead(SENSE)){  // If power button pressed
    start = millis();      // store start time
    while(digitalRead(SENSE)){  //Loop while power button still held
      now = millis();            
      if(now > (start + HOLDTIME)){  //If button held for 1000ms
        digitalWrite(13,LOW);    //Turn off power indicator
        while(digitalRead(SENSE)){} //Hold until power button is released
        delay(150);
        digitalWrite(DRIVE,LOW); // Kill power to the whole circuit
      }
    }
  }
}


/*
#define SENSE 2
#define DRIVE 7

int control = 0;
void setup() {
  // put your setup code here, to run once:
  
  pinMode(SENSE,INPUT);
  pinMode(13,OUTPUT);
  pinMode(DRIVE,OUTPUT);
  digitalWrite(DRIVE,HIGH);
  digitalWrite(13,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly: 
  
  
  int start;
  int now;
  boolean button = 0;
  
  button = digitalRead(SENSE);
  if(button == 1){
    start = millis();
    while(button == 1){
      button = digitalRead(SENSE);
      now = millis();
      if(now > (start + 1000)){
        digitalWrite(13,LOW);
        while(button == 1){button = digitalRead(SENSE);}
        delay(150);
        digitalWrite(DRIVE,LOW);
        delay(1000);
     }
    }
  }
}
*/
