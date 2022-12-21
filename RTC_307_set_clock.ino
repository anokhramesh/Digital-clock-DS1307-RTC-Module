//code for checking time & date

#include<Wire.h> # note change syntax for Include 

#include "RTClib.h"

RTC_DS1307 RTC;

#define buz 11
void setup ()

{

Serial.begin(9600);

Wire.begin();

RTC.begin(); // load the time from your computer.

if (! RTC.isrunning())

{

Serial.println("RTC is NOT running!");// This will reflect the time that your sketch was compiled

RTC.adjust(DateTime(__DATE__, __TIME__));

}

}

void loop ()

{

DateTime now = RTC.now();
if(now.hour()==23 && now.minute()==40 && now.second()==10)
{

Buzzer();

}


Serial.println();
Serial.print("  Time: ");

Serial.print(now.hour(), DEC);

Serial.print(':');

Serial.print(now.minute(), DEC);

Serial.print(':');

Serial.print(now.second(), DEC);

Serial.println();
Serial.print("-------------------------------------");
Serial.println();

delay(1000);

}
void Buzzer()
{
     tone(buz, 1000, 10000);

}
