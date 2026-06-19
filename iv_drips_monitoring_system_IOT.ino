#define BLYNK_TEMPLATE_ID "TMPL3200UeI_R"
#define BLYNK_TEMPLATE_NAME "IV Drip Monitor"
#define BLYNK_AUTH_TOKEN "v1cbTUc5Tnarrx8ghLjTWVzaD90OICVK"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include "HX711.h"

char ssid[] = "OPPOA785G";
char pass[] = "bala@2005";

#define DOUT 4
#define CLK 5

#define LED_PIN 18
#define BUZZER_PIN 23

HX711 scale;

float calibration_factor = 43.2;
float LOW_LEVEL = 300;   // grams

bool alertSent = false;

BlynkTimer timer;

void sendData()
{
  float weight = scale.get_units(30);

  if(weight < 0)
    weight = 0;

  Serial.print("Weight: ");
  Serial.print(weight);
  Serial.println(" g");

  Blynk.virtualWrite(V0, weight);

  if(weight < LOW_LEVEL)
  {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    Blynk.virtualWrite(V1, "LOW LEVEL");

    if(!alertSent)
    {
      Blynk.logEvent("low_drip", "⚠ IV Drip Level Low!");
      alertSent = true;
    }
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    Blynk.virtualWrite(V1, "NORMAL");

    alertSent = false;
  }
}

void setup()
{
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor);

  Serial.println("Remove all weight...");
  delay(5000);

  scale.tare();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(2000L, sendData);
}

void loop()
{
  Blynk.run();
  timer.run();
}