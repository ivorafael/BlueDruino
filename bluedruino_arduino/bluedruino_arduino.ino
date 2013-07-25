char incomingByte;  // incoming data
int  LED_GREEN = 12;
int  LED_RED = 11;
int  LED_YELLOW = 10;
 
 
  
void setup() {
  Serial.begin(9600); // initialization
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  Serial.println("Press 1 to LED ON or 0 to LED OFF...");
}
 
 
 

void turnOn(int led) {
  turnOffAll();
  digitalWrite(led, HIGH);
}


void turnOffAll() {
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);    
}
 
 
 
void loop() {
  if (Serial.available() > 0) {  // if the data came
    incomingByte = Serial.read(); // read byte
    
    if(incomingByte == '2') {
      turnOn(LED_GREEN);
      Serial.println("LED GREEN on");  // print message
    }
    if(incomingByte == '1') {
      turnOn(LED_RED);
      Serial.println("LED RED on");  // print message
    }
    
    if(incomingByte == '0') {
      turnOn(LED_YELLOW);
      Serial.println("LED YELLOW on");  // print message
    }    
    
    if(incomingByte == 'b') {
      Serial.println("LED BLINKING. Press 1 to LED ON!");

      for (int i = 0; i < 10; i = i+1) {
        turnOn(LED_GREEN);
        delay(200);
        turnOn(LED_RED);
        delay(200);
        turnOn(LED_YELLOW);
        delay(200);
      }      
            
      
    }    
    
  }
  
  
  
  
  
  
}

