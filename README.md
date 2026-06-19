# IoT-Based IV Drip Monitoring System

## Overview

This project presents an IoT-Based IV Drip Monitoring System developed using ESP32, HX711 Load Cell Amplifier, and Blynk Cloud Platform. The system continuously monitors the weight of an IV fluid bag and provides real-time alerts when the fluid level falls below a predefined threshold.

## Hardware Components

- ESP32 Dev Module
- HX711 Load Cell Amplifier
- Load Cell Sensor
- Buzzer
- LED Indicator
- Breadboard
- Jumper Wires
- Wi-Fi Network

## Software Used

- Arduino IDE
- Blynk IoT Platform
- ESP32 Board Package

## Features

- Real-time IV bag monitoring
- Weight measurement using load cell
- Wireless IoT dashboard
- LED low-level indication
- Buzzer alert notification
- Blynk cloud integration
- Remote monitoring through smartphone or web dashboard

## System Workflow

1. Load Cell measures IV bag weight.
2. HX711 amplifies and converts sensor data.
3. ESP32 processes the weight readings.
4. Data is sent to Blynk Cloud via Wi-Fi.
5. Dashboard displays current IV fluid level.
6. Alert is generated when the weight drops below the threshold.

## Pin Connections

| Component | ESP32 Pin |
|------------|------------|
| HX711 DOUT | GPIO 4 |
| HX711 CLK | GPIO 5 |
| LED | GPIO 18 |
| Buzzer | GPIO 23 |

## Results

### Hardware Setup

![Hardware](Images/hardware.jpeg)

### Arduino IDE Output

![Code](Images/arduino.png)

### Blynk Dashboard

![Dashboard](Images/blynk.png)

## Applications

- Smart Hospitals
- Patient Monitoring Systems
- Healthcare IoT
- Medical Automation
- Remote Healthcare Monitoring

## Future Improvements

- Battery Backup System
- Nurse Call Integration
- SMS Alert Notifications
- Mobile App Notifications
- Multiple IV Bag Monitoring

## Author

**Panchacharam**

Electronics and Communication Engineering  
Anna University Regional Campus Madurai

## Repository Contents

- ESP32 Source Code
- Hardware Setup Images
- Blynk Dashboard Images
- Project Documentation
