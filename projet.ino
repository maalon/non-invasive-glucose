#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define IR_receiver A8
int receiver = 0;
float A , C = 0;

int buttom = 0;
LiquidCrystal_I2C lcd(0x27,20,4); 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init(); 
  lcd.backlight();
  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  receiver = analogRead(IR_receiver);
  A = log(1023/receiver);
  C = A /(0.001*29.6);
  buttom = digitalRead(10);
  Serial.print("receiver = ");
  Serial.print(receiver);
  Serial.print("  |  ");
  Serial.print("A = ");
  Serial.print(A);
  Serial.print("  |  ");
  Serial.print("C = ");
  Serial.print(C);
  Serial.print("  |  ");
  Serial.print("B = ");
  Serial.println(buttom);
  delay(50);
  lcd.setCursor(0,0);
  lcd.print("lumi:");
  lcd.setCursor(5,0);
  lcd.print(receiver);
  lcd.setCursor(0,1);
  lcd.print("C:");
  lcd.setCursor(3,1);
  lcd.print(C);
}
