# Automatic_tollgate_opener-arduino
Automatic toll gate system using Arduino, ultrasonic sensor, servo motor, and LCD with vehicle detection and counting.
# Automatic Toll Gate Opener using Arduino

## Overview

This project is a simple automatic toll gate system built using Arduino, an ultrasonic sensor, a servo motor, and a 16x2 LCD display. The system detects when a vehicle approaches the gate, opens the gate automatically, and keeps track of how many vehicles have passed.

The goal of this project is to demonstrate how embedded systems can be used to automate real-world applications like toll booths and parking gates.

---

## How it works

The ultrasonic sensor continuously measures the distance in front of the gate. When a vehicle comes within a predefined distance (10 cm), the Arduino recognizes it as a valid vehicle.

Once detected:

• The servo motor opens the gate  
• The vehicle is allowed to pass  
• The system increases the vehicle count  
• The LCD displays the updated count  
• The gate closes automatically after the vehicle passes  

To avoid false detection, the system confirms the vehicle presence using multiple readings.

---

## Components Used

• Arduino Uno  
• HC-SR04 Ultrasonic Sensor  
• SG90 Servo Motor  
• 16x2 LCD Display with I2C module  
• Breadboard  
• Jumper wires  
• USB cable  

---

## Pin Connections

Ultrasonic Sensor Trigger → Pin 9  
Ultrasonic Sensor Echo → Pin 8  
Servo Motor Signal → Pin 3  
LCD SDA → A4  
LCD SCL → A5  

---

## Features

• Automatic gate control  
• Vehicle detection using ultrasonic sensor  
• Vehicle counting system  
• LCD display output  
• Fully automatic operation  

---

## Applications

This type of system can be used in:

• Toll gates  
• Parking areas  
• Private entry gates  
• Smart traffic systems  

---

## Project Files

toll_gate.ino → Arduino source code  
components.txt → List of hardware components  
circuit_diagram.png → Circuit diagram  
images/ → Project photos  

---

## Author

Jayapriyadharshni S  
ECE Student
