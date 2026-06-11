# 🔥🌊 Integrated Disaster Detection System — Fire & Flood

An Arduino-based real-time disaster detection and alert system that monitors environmental conditions for **fire**, **gas leaks**, **flooding**, and **heavy rainfall** — and instantly notifies users via Bluetooth, LEDs, and an audible buzzer. No internet connection required.

> Built as part of an embedded systems project at **Amrita School of Computing, Bengaluru — Amrita Vishwa Vidyapeetham**.

---

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Pin Configuration](#pin-configuration)
- [Software Requirements](#software-requirements)
- [Project Structure](#project-structure)
- [Setup & Installation](#setup--installation)
- [Running in VS Code](#running-in-vs-code)
- [How It Works](#how-it-works)
- [Alert Reference](#alert-reference)
- [Future Improvements](#future-improvements)
- [Authors](#authors)

---

## Overview

This system integrates four sensors with an Arduino UNO to detect two classes of disaster:

| Disaster | Sensors Used |
|----------|-------------|
| **Flood** | HC-SR04 Ultrasonic (water level) + Rain Drop Sensor (rainfall) |
| **Fire / Gas** | MQ-2 Smoke Sensor + MQ-4 Methane Gas Sensor |

When a threshold is exceeded, the system:
1. Sends an alert message over **Bluetooth (HC-05)** to a paired mobile device
2. Lights a **dedicated LED** for the specific hazard
3. Plays a **unique buzzer pattern** per disaster type

All of this works **offline** — ideal for rural and low-connectivity environments.

---

## Features

- ✅ Real-time monitoring of water level, rainfall, smoke, and methane gas
- ✅ Bluetooth alerts to a mobile app (Bluetooth Terminal)
- ✅ Distinct LED indicators per hazard (pins 2–5)
- ✅ Distinct buzzer patterns per hazard type
- ✅ Serial Monitor debugging output
- ✅ No internet connection required
- ✅ Low cost and easy to deploy

---

## Hardware Requirements

| Component | Purpose | Qty |
|-----------|---------|-----|
| Arduino UNO | Central microcontroller | 1 |
| HC-SR04 Ultrasonic Sensor | Water level detection | 1 |
| Rain Drop Sensor | Rainfall detection | 1 |
| MQ-2 Smoke Sensor | Smoke / fire detection | 1 |
| MQ-4 Methane Gas Sensor | Gas leak detection | 1 |
| HC-05 Bluetooth Module | Wireless alert transmission | 1 |
| LEDs (any color) | Visual hazard indicators | 4 |
| Buzzer (active) | Audible alerts | 1 |
| Jumper wires | Connections | — |
| Breadboard | Prototyping | 1 |
| USB Cable (Type-B) | Power & programming | 1 |

---

## Pin Configuration

| Component | Arduino Pin |
|-----------|------------|
| HC-SR04 Trig | D8 |
| HC-SR04 Echo | D9 |
| HC-05 RX | D10 |
| HC-05 TX | D11 |
| LED 1 — Water Level | D2 |
| LED 2 — Smoke (MQ-2) | D3 |
| LED 3 — Gas (MQ-4) | D4 |
| LED 4 — Rain | D5 |
| Buzzer | D6 |
| MQ-2 Smoke Sensor | A0 |
| MQ-4 Methane Sensor | A1 |
| Rain Drop Sensor | A2 |

---

## Software Requirements

| Tool | Version | Purpose |
|------|---------|---------|
| [Arduino IDE](https://www.arduino.cc/en/software) | 2.x recommended | Upload code to Arduino |
| Arduino `SoftwareSerial` library | Built-in | HC-05 Bluetooth communication |
| [VS Code](https://code.visualstudio.com/) | Latest | Code editing |
| [Arduino Extension for VS Code](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-arduino) | Latest | Compile & upload from VS Code |
| Bluetooth Terminal App (Android/iOS) | Any | Receive alerts on mobile |

---

## Project Structure

```
Integrated-Disaster-Detection-System/
│
├── src/
│   └── disaster_detection_main/
│       └── disaster_detection_main.ino      ← ✅ Main production firmware (use this)
│
├── archive/
│   └── prototype_v1_ultrasonic_only.ino     ← 🗂 Early prototype (reference only)
│
├── docs/
│   ├── Integrated_Disaster_Detection_System.docx  ← 📄 Full project report (Word)
│   └── Report.pdf                                 ← 📄 Full project report (PDF)
│
├── README.md
├── .gitignore
└── LICENSE
```

> **Which `.ino` file to use?** Always use `src/disaster_detection_main/disaster_detection_main.ino`.  
> The `archive/` folder contains an earlier prototype with different pin assignments — kept for reference only, do not wire from it.

---

## Setup & Installation

### 1. Clone the Repository

```bash
git clone https://github.com/kuushalie/Integrated-Disaster-Detection-System.git
cd Integrated-Disaster-Detection-System
```

### 2. Install Arduino IDE

Download from [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software) and install for your OS.

### 3. Install Required Libraries

The only library needed is `SoftwareSerial`, which is **built into Arduino IDE** — no extra installation required.

### 4. Open the Sketch

Open `src/disaster_detection_main/disaster_detection_main.ino` in Arduino IDE.

### 5. Configure Your Board

- Go to **Tools → Board → Arduino AVR Boards → Arduino UNO**
- Go to **Tools → Port** and select the COM port your Arduino is connected to

### 6. Upload

Click the **Upload** button (→) or press `Ctrl+U`.

### 7. Pair the HC-05 Bluetooth Module

1. Power on the Arduino circuit
2. On your phone, pair with the device named `HC-05` (default PIN: `1234` or `0000`)
3. Open a **Bluetooth Terminal** app and connect to HC-05
4. Alerts will now appear as text messages in the app

---

## Running in VS Code

### Step 1 — Install VS Code

Download from [https://code.visualstudio.com/](https://code.visualstudio.com/)

### Step 2 — Install the Arduino Extension

Open VS Code, press `Ctrl+Shift+X`, search for **Arduino** by *Microsoft* and install it.

### Step 3 — Install Arduino CLI

```bash
# Windows (via winget)
winget install ArduinoSA.CLI

# macOS (Homebrew)
brew install arduino-cli

# Linux
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
```

### Step 4 — Install Arduino UNO Board Support

```bash
arduino-cli core update-index
arduino-cli core install arduino:avr
```

### Step 5 — Open the Project

```bash
code Integrated-Disaster-Detection-System/
```

Then open `src/disaster_detection_main/disaster_detection_main.ino`.

### Step 6 — Select Board & Port

Press `Ctrl+Shift+P`:
- `Arduino: Select Board` → choose **Arduino UNO**
- `Arduino: Select Serial Port` → choose your COM / ttyUSB port

### Step 7 — Verify & Upload

Press `Ctrl+Shift+P`:
- `Arduino: Verify` — compiles the sketch
- `Arduino: Upload` — flashes it to the board

### Step 8 — Open Serial Monitor

```bash
arduino-cli monitor -p YOUR_PORT --config baudrate=9600
```

Or use the built-in Serial Monitor in the VS Code Arduino extension.

---

## How It Works

1. The Arduino continuously polls all four sensors in a loop.
2. Each reading is compared against a preset threshold.
3. If any threshold is exceeded, the system simultaneously:
   - Sends a Bluetooth message via HC-05 to the paired phone
   - Activates the corresponding LED
   - Triggers the buzzer in a pattern unique to that hazard
4. After each 1-second cycle, all outputs reset.
5. Debug output is available on the Serial Monitor at **9600 baud**.

### Threshold Values (defaults)

| Sensor | Threshold | Trigger Condition |
|--------|-----------|-------------------|
| HC-SR04 Ultrasonic | `< 5 cm` | Water too close to sensor |
| MQ-2 Smoke | `> 300` (analog) | Smoke / combustible gas detected |
| MQ-4 Methane | `> 150` (analog) | Methane / gas leak detected |
| Rain Sensor | `< 450` (analog) | Rain detected on sensor surface |

> Thresholds can be tuned at the top of `disaster_detection_main.ino` under `// Threshold Constants`.

---

## Alert Reference

| Event | Bluetooth Message | Buzzer Pattern | LED Pin |
|-------|-------------------|----------------|---------|
| Water level rising | `ALERT: Water level is rising!` | Continuous tone | D2 |
| Smoke detected (MQ-2) | `ALERT: High MQ2 gas levels detected!` | 2 short beeps | D3 |
| Gas leak (MQ-4) | `ALERT: High MQ4 gas levels detected!` | 2 short beeps | D4 |
| Rain detected | `ALERT: Rain detected!` | 4 short beeps | D5 |

---

## Future Improvements

- [ ] Replace HC-05 Bluetooth with Wi-Fi (ESP8266/ESP32) or LoRa for longer range
- [ ] Add GSM (SIM800L) for SMS alerts where smartphones are unavailable
- [ ] Integrate machine learning to auto-adjust sensor thresholds
- [ ] Add solar power supply for off-grid deployment
- [ ] Build a companion Android/iOS app with push notifications and alert logging
- [ ] Design a weatherproof enclosure for outdoor installation


---

## License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.  
Please cite appropriately if used in research or academic work.
