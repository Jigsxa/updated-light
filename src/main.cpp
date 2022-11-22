#include <Arduino.h>

// Pins entsprechen dem layout auf dem ESP8266
#define LDR A0
#define led D3
const int DELAY = 500;
const int LED_THRESHOLD = 300;

void setup() 
{
    Serial.begin(115200); // Serielle Verbindung starten
    pinMode(led,OUTPUT); // Die LED an Digital 3 als AUSGANG eingestellt
    delay(DELAY);
}

void loop() 
{
    int sensorValue = analogRead(LDR);
    if (sensorValue < LED_THRESHOLD)
    {
        digitalWrite(led, HIGH);
    }
    else
    {
        digitalWrite(led, LOW);
    }
    Serial.print("Debug: Light value is ");
    Serial.print(sensorValue);
    Serial.print("\n"); 
    delay(DELAY); 
}