# ⏱️ Self-Hosted 7-Segment Clock Webapp

A responsive, browser-based interface for controlling four Engineezy 7-segment display modules in HH:MM format using an ESP32. Includes real-time clock sync and visually accurate SVG digit rendering.

---

### 💡 Why This Exists

This project was built to provide a hands-on, real-time way to control 3D-printed 7-segment displays powered by servo motors. It uses an ESP32 as the driver and offers a web interface for both manual control and time-based display — fully customizable and scalable.

---

### 🤖 Project Attribution

All logic, display rendering, and interface interactions were designed with help from [ChatGPT](https://openai.com/chatgpt) by OpenAI.

---

## 📦 Features

- Real-time clock display in HH:MM format
- Works with 4 Engineezy 7-segment display moduleshttps://github.com/junderscore69/self-web-7segment_webapp_esp32/blob/main/README.md
- Fully self-hosted on an ESP32
- Digit rendering matches actual 3D-printed segments
- Scales across all screen sizes
- Optional baseplate visualization for physical alignment
- Manual digit override support (dev mode)

---

## 🚀 Setup

Get started with just a few steps:

### 1️⃣ Clone the Repository

```sh
git clone https://github.com/yourusername/self-web-7segment_webapp_esp32.git
cd self-web-7segment_webapp_esp32
```

### 2️⃣ Upload to ESP32

Use the Arduino IDE or PlatformIO to upload the server code to your ESP32. It hosts the static web UI and handles servo control via I2C.

### 3️⃣ Open the Web Interface

Once the ESP32 is running and connected to Wi-Fi, visit its IP address in your browser to access the UI.

---

## 📋 How to Use

1. Power up the ESP32 connected to your 7-segment display modules
2. Access the web interface from any device on the same network
3. The digits will sync with current time automatically
4. Customize segment positions or override manually (dev mode)

---

## ⚙️ Hardware Requirements

- ESP32 microcontroller
- PCA9685 16-channel PWM driver
- 4× Engineezy 7-segment servo display modules
- Power supply for servos
- Wi-Fi network

---

## 📁 Project Files

- `/web/`: HTML, CSS, and JavaScript frontend
- `/firmware/`: Arduino/ESP32 code to drive the display
- `7segdrawing_complete.svg`: Custom segment SVG for accurate rendering
- `Clock baseplate.svg`: Background visualization for module alignment
- `README.md`: You're reading it!

---

## 📄 License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

---
