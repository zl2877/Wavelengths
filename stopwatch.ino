#include <LiquidCrystal.h>

#include <LiquidCrystal_I2C.h>
// Module connection pins (Digital Pins)
const int bouton = 4;
const int bouton2 = 3;
const int bouton3 = 5;
const int bouton4 = 6;
const int bouton5 = 10;
const int bouton6 = 11;
//const int pauseButtonPin = 3;
int etatBouton, etatBouton2, etatBouton3, etatBouton4, etatBouton5, etatBouton6;

int switchReed = 6;


int cp, test, minute, hour;
int offset = 0;
int displayCharLength = 8;
int msg = 5;
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  Serial.begin(9600);
  lcd.init();
  pinMode(bouton, INPUT);
  //  etatBouton = 1;
  pinMode(bouton2, INPUT);
  //  etatBouton2 = 2;
  pinMode(bouton3, INPUT);
  pinMode(bouton4, INPUT);
  pinMode(bouton5, INPUT);
  pinMode(bouton6, INPUT);

  pinMode(switchReed, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("---STOPWATCH----");

  cp = 0; // initialize the timer to 0
  hour = 00;
  minute = 00;
}

void loop() {
  lcd.backlight();
  etatBouton = digitalRead(bouton);
  etatBouton2 = digitalRead(bouton2);
  etatBouton3 = digitalRead(bouton3);
  etatBouton4 = digitalRead(bouton4);
  etatBouton5 = digitalRead(bouton5);
  etatBouton6 = digitalRead(bouton6);
 
  if (etatBouton == HIGH && etatBouton2 && etatBouton3 && etatBouton4 && etatBouton5 && etatBouton6) {
    Serial.println(digitalRead(bouton));
    Serial.println(digitalRead(bouton3));
    //    test = 1;

    //    while (test == 1) {
    lcd.clear();
    lcd.setCursor(0, 0);

    //lcd.setCursor(0,1);
    int wid = 16; //for 16x2 display
    int row = 1;  //always 2nd row
    int len = msg;
    lcd.setCursor((wid - len - 3) / 2, row);
    //lcd.print(msg);

    if (cp > 59) {
      minute += 1;
      cp = 0;
    }
    if (minute > 59) {
      hour++;
      minute = 0;

    }
    if (hour < 10) {
      lcd.print(0);
    }

    lcd.print(hour);
    lcd.print(":");
    if (minute < 10) {
      lcd.print(0);
    }

    lcd.print(minute);
    lcd.print(":");
    if (cp < 10) {
      lcd.print(0);
    }
    lcd.print(cp);
    cp++; // increment the counter
    //cp+=100;//for testing

    etatBouton = digitalRead(bouton);
    etatBouton2 = digitalRead(bouton2);
    etatBouton3 = digitalRead(bouton3);
    etatBouton4 = digitalRead(bouton4);
    etatBouton5 = digitalRead(bouton5);
    etatBouton6 = digitalRead(bouton6);
    delay(1000);

    //if(digitalRead(switchReed)==HIGH){


    //    }
  }
  else {
    //if ((etatBouton == 0)||(etatBouton2 == 0)) { //if the button is pressed a second time
    //        test = 0; // stop the clock
    etatBouton = digitalRead(bouton);
    etatBouton2 = digitalRead(bouton2);
    etatBouton3 = digitalRead(bouton3);
    etatBouton4 = digitalRead(bouton4);
    etatBouton5 = digitalRead(bouton5);
    etatBouton6 = digitalRead(bouton6);
    delay(1000);
  }
}
