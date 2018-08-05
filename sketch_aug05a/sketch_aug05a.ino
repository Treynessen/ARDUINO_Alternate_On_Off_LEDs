void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

long time = 0;
bool ON = true;
byte LED_COUNT = 0;

void loop() {
  if((millis()-time)>=50 && !digitalRead(7)){
    switch(LED_COUNT){
      case 5:
        if(ON){
          Serial.println("ON");
          ON = false;
          LED_COUNT = 0;
        }
        else {
          Serial.println("OFF");
          ON = true;
          LED_COUNT = 0;
        }
      case 0:
        Serial.println("1");
        if(ON) digitalWrite(8,HIGH);
        else digitalWrite(8,LOW);
        ++LED_COUNT;
        break;
      case 1:
        Serial.println("2");
        if(ON) digitalWrite(9,HIGH);
        else digitalWrite(9,LOW);
        ++LED_COUNT;
        break;
      case 2:
        Serial.println("3");
        if(ON) digitalWrite(10,HIGH);
        else digitalWrite(10,LOW);
        ++LED_COUNT;
        break; 
      case 3:
        Serial.println("4");
        if(ON) digitalWrite(11,HIGH);
        else digitalWrite(11,LOW);
        ++LED_COUNT;
        break; 
      case 4:
        Serial.println("5");
        if(ON) digitalWrite(12,HIGH);
        else digitalWrite(12,LOW);
        ++LED_COUNT;
        break;
    }
    while(!digitalRead(7));
    time = millis();
  }
}
