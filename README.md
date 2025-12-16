# Arduino_Code 🔌🤖

This repository contains basic Arduino projects using **Ultrasonic Sensor** and **Buzzer**.  
These programs are suitable for **beginners**, **lab experiments**, and **mini projects**.

---

## 📂 Files Description

| File Name | Description |
|----------|-------------|
| `Buzzer.ino` | Basic buzzer ON/OFF program |
| `Ultrasonic_sensor.ino` | Distance measurement using HC-SR04 |
| `ulta_buzzer.ino` | Ultrasonic sensor with buzzer alert |

---

## 🔧 Components Used
- Arduino UNO
- Ultrasonic Sensor (HC-SR04)
- Buzzer
- Jumper Wires
- Breadboard

---

## 🔌 Pin Connections

### Ultrasonic Sensor (HC-SR04)
| Sensor Pin | Arduino Pin |
|----------|-------------|
| VCC | 5V |
| GND | GND |
| TRIG | D2 |
| ECHO | D3 |

### Buzzer
| Buzzer Pin | Arduino Pin |
|-----------|-------------|
| + | D4 |
| - | GND |

---

## ⚙️ Working Principle
- Ultrasonic sensor emits sound waves
- Echo time is measured
- Distance is calculated using:  
  **Distance = (Time × 0.034) / 2**
- If distance ≤ 20 cm → **Buzzer ON**
- Else → **Buzzer OFF**

---

## 📊 Output
- Distance is displayed on **Serial Monitor**
- Buzzer alerts when an object is close

---

## 🎯 Applications
- Obstacle detection
- Parking sensor
- Safety alert system
- Elderly care assistance (fall/near object alert)

---

## 👨‍💻 Author
**Nilesh Gupta**  
Arduino Beginner | Electronics Enthusiast

---

⭐ If you like this project, give it a star!
