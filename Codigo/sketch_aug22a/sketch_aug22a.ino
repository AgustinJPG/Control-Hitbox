#include <Keyboard.h>

const int Arbutton = 4;
const int Abbutton = 6;
const int Debutton = 7;
const int Izbutton = 5;
const int Exbutton = 8;
const int Sabutton = 9;
const int Start = 2;
const int Select = 3;
const int Abutton = 21;
const int Bbutton = 20;
const int Cbutton = 19;
const int Dbutton = 18;
const int Ebutton = 15;
const int Fbutton = 14;
const int Gbutton = 16;
const int Hbutton = 10;
const int FPS = 120;

unsigned long lastTime = 5;

//Control de las "flechas" del mando 
void MoveButtonsControl(int arbutton, int izbutton, int abbutton, int debutton);
//Control de los botones Accion
void ButtonsAcc1(int Ab, int Bb, int Cb, int Db);
//Control de los botones Accion
void ButtonsAcc2(int Eb, int Fb, int Gb, int Hb);
//Control de los botones EX
void ButtonsEX(int start, int select, int exbutton, int sabutton); 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(Arbutton, INPUT_PULLUP);
  pinMode(Izbutton, INPUT_PULLUP);
  pinMode(Abbutton, INPUT_PULLUP);
  pinMode(Debutton, INPUT_PULLUP);
  pinMode(Sabutton, INPUT_PULLUP);
  pinMode(Exbutton, INPUT_PULLUP);
  pinMode(Start, INPUT_PULLUP);
  pinMode(Select, INPUT_PULLUP);
  pinMode(Abutton, INPUT_PULLUP);
  pinMode(Bbutton, INPUT_PULLUP);
  pinMode(Cbutton, INPUT_PULLUP);
  pinMode(Dbutton, INPUT_PULLUP);
  pinMode(Ebutton, INPUT_PULLUP);
  pinMode(Fbutton, INPUT_PULLUP);
  pinMode(Gbutton, INPUT_PULLUP);
  pinMode(Hbutton, INPUT_PULLUP);

  Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if((millis()-lastTime) > 5){
    MoveButtonsControl(Arbutton, Izbutton, Abbutton, Debutton);
    ButtonsAcc1(Abutton, Bbutton, Cbutton, Dbutton);
    ButtonsAcc2(Ebutton, Fbutton, Gbutton, Hbutton);  
    ButtonsEX(Start, Select, Exbutton, Sabutton);
  
    lastTime = millis();
  }
}

void MoveButtonsControl(int arbutton, int izbutton, int abbutton, int debutton){
  if(!digitalRead(arbutton)){
    Keyboard.press(KEY_UP_ARROW);
    Serial.println("arriba");
  }else{
    Keyboard.release(KEY_UP_ARROW);
  }

  if(!digitalRead(izbutton)){
    Keyboard.press(KEY_LEFT_ARROW);
    Serial.println("izquierda");
  }else{
    Keyboard.release(KEY_LEFT_ARROW);
  }
  
  if(!digitalRead(abbutton)){
    Keyboard.press(KEY_DOWN_ARROW);
    Serial.println("abajo");
  }else{
    Keyboard.release(KEY_DOWN_ARROW);
  }

  if(!digitalRead(debutton)){
    Keyboard.press(KEY_RIGHT_ARROW);
    Serial.println("derecha");
  }else{
    Keyboard.release(KEY_RIGHT_ARROW);
  }
}

void ButtonsAcc1(int Ab, int Bb, int Cb, int Db){
  if(!digitalRead(Ab)){
    Keyboard.press('y');
    Serial.println("y");
  }else{
    Keyboard.release('y');
  }

  if(!digitalRead(Bb)){
    Keyboard.press('u');
    Serial.println("u");
  }else{
    Keyboard.release('u');
  }

  if(!digitalRead(Cb)){
    Keyboard.press('h');
    Serial.println("h");
  }else{
    Keyboard.release('h');
  }

  if(!digitalRead(Db)){
    Keyboard.press('j');
    Serial.println("j");
  }else{
    Keyboard.release('j');
  }
}

void ButtonsAcc2(int Eb, int Fb, int Gb, int Hb){
  if(!digitalRead(Eb)){
    Keyboard.press('i');
    Serial.println("i");
  }else{
    Keyboard.release('i');
  }

  if(!digitalRead(Fb)){
    Keyboard.press('o');
    Serial.println("o");
  }else{
    Keyboard.release('o');
  }
  
  if(!digitalRead(Gb)){
    Keyboard.press('k');
    Serial.println("k");
  }else{
    Keyboard.release('k');
  }

  if(!digitalRead(Hb)){
    Keyboard.press('l');
    Serial.println("l");
  }else{
    Keyboard.release('l');
  }
}

void ButtonsEX(int start, int select, int exbutton, int sabutton){
  if(!digitalRead(start)){
    Keyboard.press('n');
    Serial.println("n");
  }else{
    Keyboard.release('n');
  }

  if(!digitalRead(select)){
    Keyboard.press('m');
    Serial.println("m");
  }else{
    Keyboard.release('m');
  }
  
  if(!digitalRead(exbutton)){
    Keyboard.press('e');
    Serial.println("e");
  }else{
    Keyboard.release('e');
  }
      
if (!digitalRead(sabutton)) {
    Keyboard.press(' ');      // ← barra espaciadora
    Serial.println("espacio");
} else {
    Keyboard.release(' ');    // ← liberar barra espaciadora
}

}


