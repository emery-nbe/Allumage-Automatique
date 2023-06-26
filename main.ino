#include <RTClib.h>


const int LED_1 = 2;
const int LED_2 = 3;

const int HEURE_ALLUMAGE = 18;
const int HEURE_EXTINCTION = 6;

RTC_DS1307 rtc;

void setup(){
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop(){
  DateTime maintenant = rtc.now();
  int heure = maintenant.hour();

  if (heure >= HEURE_ALLUMAGE || heure < HEURE_EXTINCTION){
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH); 
  } else {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
  }

  delay(1000);
}
