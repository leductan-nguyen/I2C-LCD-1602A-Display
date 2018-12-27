#include <Arduino.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define DHTPIN 8      // what digital pin we're connected to DHT sensor
#define DHTTYPE DHT22 // DHT 22  (AM2302), AM2321

// Initialize LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.init();                   // initialize the lcd
  lcd.backlight();              //To Power ON the back light
  lcd.setCursor(0, 0);          //Defining positon to write from first row,first column .
  lcd.print("Raion I2C 1602A"); //You can write 16 Characters per line .
  dht.begin();
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("T:      H:      ");

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    return;
  }

  lcd.setCursor(0, 1); //Defining positon to write from second row,first column .
  lcd.print("T:");
  lcd.print(t);
  lcd.print(" H:");
  lcd.print(h);
  // Wait a few seconds between measurements.
  delay(2000);
}
