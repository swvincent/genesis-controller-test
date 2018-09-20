/*
  Sega Genesis Controller Test

  Written in 2013 by Scott W. Vincent
  http://www.swvincent.com
  https://github.com/swvincent/genesis-controller-test

  Video demonstration: https://www.youtube.com/watch?v=PmDlX7lPET8

  The following webpages were helpful in writing this:
  http://pinouts.ru/Game/genesiscontroller_pinout.shtml
  http://arduino.cc/forum/index.php/topic,21263.0.html
  http://arduino.cc/forum/index.php/topic,49070.0.html
*/

//Constants
const int UP_PIN = 7;
const int DOWN_PIN = 3;
const int LEFT_PIN = 4;
const int RIGHT_PIN = 5;
const int AB_PIN = 8;
const int SELECT_PIN = 2;
const int STARTC_PIN = 6;
const int LED1_PIN = 9;
const int LED2_PIN = 10;
const int LED3_PIN = 11;
const int LED4_PIN = 12;
const int LED5_PIN = 13;

void setup()
{
  //Set Pin modes
  pinMode(UP_PIN, INPUT);
  pinMode(DOWN_PIN, INPUT);
  pinMode(LEFT_PIN, INPUT);
  pinMode(RIGHT_PIN, INPUT);
  pinMode(AB_PIN, INPUT);
  pinMode(SELECT_PIN, OUTPUT);
  pinMode(STARTC_PIN, INPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  pinMode(LED5_PIN, OUTPUT);
}

void loop()
{
  //SELECT=GND
  digitalWrite(SELECT_PIN, LOW);
  digitalWrite(LED2_PIN, !digitalRead(UP_PIN) || !digitalRead(DOWN_PIN));
  digitalWrite(LED4_PIN, !digitalRead(AB_PIN) || !digitalRead(STARTC_PIN));  //A/Start

  //SELECT=+5V
  digitalWrite(SELECT_PIN, HIGH);
  digitalWrite(LED1_PIN, !digitalRead(LEFT_PIN));
  digitalWrite(LED3_PIN, !digitalRead(RIGHT_PIN));
  digitalWrite(LED5_PIN, !digitalRead(AB_PIN) || !digitalRead(STARTC_PIN));  //B/C
}
