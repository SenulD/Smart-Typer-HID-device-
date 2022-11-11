#include "DigiKeyboard.h"

const int StatusLed = 2;
const int Function1 = 1;
const int Function2 = 0;

int Button1,Button2,timecount1 = 0,timecount2 = 0;
void setup() {
  pinMode (StatusLed, OUTPUT);
  pinMode (Function1, INPUT);
  pinMode (Function2, INPUT);
  blinkL();
}


void loop() {
  Button1  = digitalRead(Function1);
  Button2  = digitalRead(Function2);
 
  buttons();
  
  delay(500);
}

void buttons()
{

  if (Button1 == LOW){
    
    timecount1 += 1;
  }
  else if(Button2 == LOW)
  {
    timecount2 += 1;
  }
  else{
    
    timecount1 =  0; 
    timecount2 =  0; 
    
    }
  //Gmail

  if (timecount1 == 1){
    blinkL();
    DigiKeyboard.delay(1000);
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(200);
  
    DigiKeyboard.print("resmon");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(4000);
  }

  if (timecount1 >= 2){
  blinkL();blinkL();
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(600);
  DigiKeyboard.print("https://accounts.google.com/AccountChooser/identifier?service=mail&cont…");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  DigiKeyboard.print("My Email");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.print("Email Password");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);

  }

  //Windows

  if (timecount2 == 1){
    blinkL();
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(600);
    DigiKeyboard.print("cmd");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("start C:\\Users\\Senul\\Music\\PlayLists\\Favourite_Songs.zpl");
     DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(2000);

   }
     if (timecount2 >= 2){
    blinkL();blinkL();
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(600);
    DigiKeyboard.delay(2000);
    DigiKeyboard.print("D:\\sample\\CoD4\\GmaeCOD4\\iw3mp.exe");
     DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(2000);

   }

}
void blinkL()
{
  digitalWrite(2,HIGH);
  delay(200);
  digitalWrite(2,LOW);
  delay(200);
}
