void setup() {
  pinMode(7, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

bool low_signal = true; 
byte count_low_signal = 0;
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
  if (!low_signal && digitalRead(7) && count_low_signal++ >= 100) low_signal = true; 
  if (low_signal && !digitalRead(7)) {
    LEDControl();
    low_signal = false; 
    count_low_signal = 0; 
  } 
}
