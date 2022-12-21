#include "Wire.h"
#include "LCD.h"
#include "LiquidCrystal_I2C.h"
#include "RTClib.h"

RTC_DS1307 rtc;
//LiquidCrystal_I2C lcd (0x3F,2,1,0,4,5,6,7); //20x4 LCD address for I2C Configuration
LiquidCrystal_I2C lcd (0x27,2,1,0,4,5,6,7); //12x2 LCD addressfor I2C Configuration
char week [7] [4] ={"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

  void setup()

  {
    Serial.begin(9600);
    // LCD Configuration
    //lcd.begin(20,4);// use this line if using 20x4 LCD
    lcd.begin(16,2);//use this line if using 16x2 LCD
    lcd.setBacklightPin(3,POSITIVE);
    lcd.setBacklight(HIGH);
    lcd.clear();
    //RTC Configuration
    if(!rtc.begin()){
      Serial.println("ERROR");
      return;
    }

    if(!rtc.isrunning()){
      rtc.adjust(DateTime(__DATE__,__TIME__)); // set time in the rtc first time
      Serial.println("TIME-SET");
    }
    
  }



 void loop(){

  DateTime now = rtc.now();
  lcd.setCursor(4,1);// set the cursor 5th column second row
  lcd.print(now.hour(),DEC);// display Hour
  lcd.print(':');
  lcd.print(now.minute(),DEC);// display minute
  lcd.print(':');
  lcd.print(now.second(),DEC);// display second

  lcd.setCursor(1,0);// set the cursor on first column first row
  lcd.print(week[now.dayOfTheWeek()]);
  lcd.print(" ");
  lcd.print(now.day(),DEC);// display day
  lcd.print('/');
  lcd.print(now.month(),DEC);// display month
  lcd.print('/');
  lcd.print(now.year(),DEC);// display year
  Serial.println(now.second());
  
  int i = now.second();

  delay(1000);
  if(i==59){
    lcd.clear(); //Clear the display every second
    Serial.println("CLEAR");
  }
 }

 
