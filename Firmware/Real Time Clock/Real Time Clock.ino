#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Initializing RTC...");
  if (! rtc.begin()) {
    lcd.setCursor(0, 1);
    lcd.print("RTC failed");
    while (1);
  }
  if (! rtc.isrunning()) {
    lcd.setCursor(0, 1);
    lcd.print("RTC is NOT running");
    while (1);
  }
  lcd.clear();
}

void loop() {
  DateTime now = rtc.now();
  lcd.setCursor(0, 0);
  lcd.print(now.day(), DEC);  
  lcd.print('/');
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.year(), DEC);
  lcd.setCursor(0, 1);
  lcd.print(now.hour(), DEC);
  lcd.print(':');
  lcd.print(now.minute(), DEC);
  lcd.print(':');
  lcd.print(now.second(), DEC);
  delay(1000);
}
