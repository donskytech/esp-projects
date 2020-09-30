#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600);
  Serial.println("<Arduino is ready>");

  lcd.init();
  lcd.backlight();
}

void loop() {
  if (mySerial.available()) {
    parseAndDisplay();
  }
}

void parseAndDisplay() {
  const size_t capacity = JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(8) + 467;
  DynamicJsonDocument doc(capacity);
  DeserializationError error = deserializeJson(doc, mySerial);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }
  int id = doc["id"]; // 1
  const char * name = doc["name"]; // "Leanne Graham"
  const char * username = doc["username"]; // "Bret"
  const char * email = doc["email"]; // "Sincere@april.biz"

  JsonObject company = doc["company"];
  const char * company_name = company["name"]; // "Romaguera-Crona"
  const char * company_catchPhrase = company["catchPhrase"]; // "Multi-layered client-server neural-net"
  const char * company_bs = company["bs"]; // "harness real-time e-markets"

  Serial.print("ID :: ");
  Serial.println(id);
  Serial.print("Name :: ");
  Serial.println(name);
  Serial.print("Company Name :: ");
  Serial.println(company_name);

  printToLCDScreen(id, name);
}

void printToLCDScreen(const int id,
  const char * name) {
  lcd.setCursor(0, 0);
  lcd.print("Name:");
  lcd.setCursor(0, 1);
  lcd.print(name);
}