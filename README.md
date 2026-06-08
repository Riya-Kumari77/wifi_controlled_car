# WiFi Controlled Robot using XIAO ESP32-C6 and L298N

## Overview

This project demonstrates a simple WiFi-controlled robot built using the Seeed Studio XIAO ESP32-C6 and an L298N motor driver. The robot creates its own WiFi access point and hosts a web-based control panel that can be accessed from any smartphone or computer browser.

No mobile application is required. Users can connect directly to the robot's WiFi network and control movement through a web interface.

---

## Features

* WiFi Access Point Mode
* Browser-Based Control Interface
* Forward Movement
* Backward Movement
* Left Turn
* Right Turn
* Stop Function
* No External App Required
* Beginner Friendly

---

## Hardware Requirements

* Seeed Studio XIAO ESP32-C6
* L298N Motor Driver Module
* 2 DC Gear Motors
* Robot Chassis
* Battery Pack (7.4V Recommended)
* Jumper Wires
* Smartphone or Laptop

---

## Wiring Diagram

### XIAO ESP32-C6 → L298N

| XIAO ESP32-C6 | L298N |
| ------------- | ----- |
| D0            | IN1   |
| D1            | IN2   |
| D2            | IN3   |
| D3            | IN4   |
| D4            | ENA   |
| D5            | ENB   |
| GND           | GND   |

### Motors

| L298N       | Motor       |
| ----------- | ----------- |
| OUT1 & OUT2 | Left Motor  |
| OUT3 & OUT4 | Right Motor |

### Power

Battery Positive → L298N 12V

Battery Negative → L298N GND

L298N GND → XIAO GND

---

## Software Requirements

* Arduino IDE
* ESP32 Board Package by Espressif

### Install ESP32 Board Package

Open Arduino IDE

File → Preferences

Add:

https://espressif.github.io/arduino-esp32/package_esp32_index.json

Then:

Tools → Board Manager

Search:

ESP32

Install:

esp32 by Espressif Systems

---

## Libraries Used

```cpp
#include <WiFi.h>
#include <WebServer.h>
```

These libraries are included automatically with the ESP32 board package.

---

## Upload Instructions

1. Connect XIAO ESP32-C6 via USB.
2. Select the correct COM port.
3. Select "XIAO ESP32C6" board.
4. Upload the code.
5. Open Serial Monitor at 115200 baud.

---

## Connecting to the Robot

After powering the robot:

1. Open WiFi settings on your phone.
2. Connect to the ESP32 WiFi network.
3. Enter the configured password.
4. Open a browser.
5. Navigate to:

http://192.168.4.1

---

## Control Interface

The webpage provides the following controls:

* Forward
* Backward
* Left
* Right
* Stop

---

## Future Improvements

* PWM Speed Control
* Mobile Joystick Interface
* Obstacle Avoidance Mode
* Line Following Mode
* Battery Monitoring
* Autonomous Navigation
* Camera Streaming
* IoT Dashboard Integration

---

## Learning Outcomes

This project helps beginners learn:

* ESP32 WiFi Programming
* Web Server Development
* Motor Control using L298N
* Embedded Systems
* Robotics Fundamentals
* IoT Concepts

---

## Author

Riya Kumari

Built as a beginner robotics and IoT project using XIAO ESP32-C6.
