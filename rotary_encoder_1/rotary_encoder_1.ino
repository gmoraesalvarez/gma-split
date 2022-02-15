//#include <DigiMouse.h>
#include "DigiKeyboard.h"

#define LATCHSTATE 3
/*#define KEYPAD_1                (  89  | 0xF000 )
#define KEYPAD_2                (  90  | 0xF000 )
#define KEYPAD_3                (  91  | 0xF000 )
#define KEYPAD_4                (  92  | 0xF000 )
#define KEYPAD_5                (  93  | 0xF000 )
#define KEYPAD_6                (  94  | 0xF000 )
#define KEYPAD_7                (  95  | 0xF000 )
#define KEYPAD_8                (  96  | 0xF000 )
#define KEYPAD_9                (  97  | 0xF000 )
#define KEYPAD_0                (  98  | 0xF000 ) 
#define KEY_COMMA 0x33
#define KEY_PERIOD 0x34 */
#define KEY_ARROW_LEFT 0x50
#define KEY_ARROW_RIGHT 0x4F  

int DT = 11;
int CLK = 12;
int SW = 10;
int B[10] = { 0 };
int last_hit_B[10];
int last_hit_SW;
int BS_[10] = { 0 };
int BS_SW = 0;
int KEY_[10];

int clockwise = KEY_ARROW_LEFT;
int counterclockwise = KEY_ARROW_RIGHT;
int current_mode = 0;

int buttonState = LOW, lastButtonState = LOW;
long lastDebounceTime = 0, debounceDelay = 200;
int _position = 0, _positionExt = 0;
int8_t _oldState; bool btnPressed=false, btnReleased=false, pressedRotary=false;

const int8_t encoderStates[] = {
  0, -1, 1, 0,
  1, 0, 0, -1,
  -1, 0, 0, 1,
  0, 1, -1, 0
};

int switch_mode(){
  if (current_mode == 1){
    clockwise = KEY_ARROW_LEFT;
    counterclockwise = KEY_ARROW_RIGHT;
    current_mode = 0;
  } else {
    clockwise = KEY_J;
    counterclockwise = KEY_L;
    current_mode = 1;
  }
  
}

void setup() {
  //DigiMouse.begin();
  //pinMode(1, OUTPUT);
  B[1] = 0; //ok
  B[2] = 2;
  B[3] = 5; //ok
  B[4] = 6; //ok
  B[5] = 7;
  B[6] = 8; //ok
  B[7] = 9; //ok

  KEY_[1] = KEY_Q; //ok
  KEY_[2] = KEY_W;
  KEY_[3] = KEY_E; // ok 
  KEY_[4] = KEY_R; // ok
  KEY_[5] = KEY_T;
  KEY_[6] = KEY_Y; // ok
  KEY_[7] = KEY_U; // ok
  
  pinMode(DT, INPUT);
  digitalWrite(DT, HIGH);
  pinMode(CLK, INPUT);
  digitalWrite(CLK, HIGH);
  
  for (int i = 1; i < 10; i++) {
    pinMode(B[i], INPUT);
    digitalWrite(B[i], HIGH);
    last_hit_B[i] = millis();
  }

  pinMode(SW, INPUT);
  digitalWrite(SW, HIGH);
  last_hit_SW = millis();
}

void loop() {
  //DigiMouse.update();
  static int pos = 0;
  tick();
  int newPos = getPosition();
  if (pos != newPos) {
    //digitalWrite(1, HIGH);
    if (newPos < pos) {
      //digitalWrite(1, HIGH);
      movedCounterClockwise();
    }else if (newPos > pos){
      movedClockwise();
      //digitalWrite(1, LOW);    
    }
    pos = newPos;
  }
  for (int i = 1; i < 8; i++) {
    if (digitalRead(B[i]) == LOW && BS_[i] == 0 && (millis() - last_hit_B[i]) > debounceDelay){
      DigiKeyboard.sendKeyPress(KEY_[i]);
      BS_[i] = 1;
      last_hit_B[i] = millis();
    }
    if (digitalRead(B[i]) == HIGH && BS_[i] == 1 && (millis() - last_hit_B[i]) > debounceDelay){
      DigiKeyboard.sendKeyPress(0,0);
      BS_[i] = 0;
      last_hit_B[i] = millis();
    }
  } // LOOP SEM MATRIZ
    
  if (digitalRead(SW) == LOW && BS_SW == 0 && (millis() - last_hit_SW) > debounceDelay){
    //DigiMouse.setButtons(1<<1);
    //DigiKeyboard.sendKeyPress(KEY_SPACE);
    switch_mode();
    BS_SW= 1;
    last_hit_SW = millis();
  }
  if (digitalRead(SW) == HIGH && BS_SW == 1 && (millis() - last_hit_SW) > debounceDelay){
    //DigiMouse.setButtons(1<<1);
    //DigiKeyboard.sendKeyPress(0,0);
    BS_SW = 0;
    last_hit_SW = millis();
  }
  DigiKeyboard.update();
}

int  getPosition() {
  return _positionExt;
}

void setPosition(int newPosition) {
  _position = ((newPosition<<2) | (_position & 0x03));
  _positionExt = newPosition;
}

void tick(void) {
  int sig1 = digitalRead(CLK);
  int sig2 = digitalRead(DT);
  int8_t thisState = sig1 | (sig2 << 1);
  if (_oldState != thisState) {
    _position += encoderStates[thisState | (_oldState<<2)];
    if (thisState == LATCHSTATE)
      _positionExt = _position >> 2;
    _oldState = thisState;
  }
}

void movedClockwise() {
  //DigiMouse.scroll(1);
  DigiKeyboard.sendKeyStroke(clockwise);
}

void movedCounterClockwise() {
  //DigiMouse.scroll(-1);
  DigiKeyboard.sendKeyStroke(counterclockwise);
}
