# SmartCart-IoT

## Overview
A smart shopping cart that uses RFID and IoT sensors to track items in real-time and update inventory databases.

## Tech Stack
- ESP8266 (NodeMCU) with Arduino
- RFID MFRC522
- IR Sensor, LCD I2C Display
- Python for server-side simulation
- Excel as a simulated inventory database

## Setup
1. Upload `cart.ino` to NodeMCU via Arduino IDE.
2. Connect hardware components:
   - RFID to SPI pins
   - LCD via I2C
3. Run `sync_to_excel.py` to simulate database update.

## Future Integration
- Replace Excel with Firebase/MySQL
- Add real-time UI dashboard
- Enable mobile cart checkout via QR
