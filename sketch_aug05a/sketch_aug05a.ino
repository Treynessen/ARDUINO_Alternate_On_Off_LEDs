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
const byte LED_NUM = 5;
byte LED_COUNT = 0;

void LEDControl(){
  if (LED_COUNT == LED_NUM){
    if(ON) ON = false;
    else ON = true;
    LED_COUNT = 0;
  }
  if(ON) digitalWrite((LED_COUNT++)+8,HIGH);
  else digitalWrite((LED_COUNT++)+8,LOW);
}

void loop() {
  if((millis()-time)>=50 && !digitalRead(7)){
    LEDControl();
    while(!digitalRead(7));
    time = millis();
  }
}
