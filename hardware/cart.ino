#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN D3
#define SS_PIN  D4
MFRC522 mfrc522(SS_PIN, RST_PIN);

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* ssid = "SSID";
const char* password = "PASSWORD";

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Smart Cart Init");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  lcd.setCursor(0,1);
  lcd.print("WiFi Connected");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial())
    return;

  String uid = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    uid += String(mfrc522.uid.uidByte[i], HEX);
  }

  Serial.println("Item Scanned: " + uid);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Item ID: ");
  lcd.setCursor(0, 1);
  lcd.print(uid);

  delay(2000); // simulate delay
}
