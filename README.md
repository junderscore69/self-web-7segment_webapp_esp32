# 7-Segment Web App

A modern, browser-based simulator and visualization tool for 4-digit 7-segment displays. This app features interactive modules for clock, timer, stopwatch, dice rolling, temperature display, and animated patterns—all rendered with accurate SVG graphics.

---

## ✨ Features

- **Real-time Clock**: Displays the current time in HH:MM format, with selectable 12hr/24hr modes and timezone support.
- **Timer**: Set a countdown timer (up to 99:59), with start, pause, stop, and reset controls. Includes a wave animation when the timer finishes.
- **Stopwatch**: Count up from zero, with pause, stop, and reset controls (up to 99:59).
- **Dice Simulator**: Simulate rolling two dice (d2–d99 each), with results shown on the display.
- **Temperature**: Enter a location to fetch and display the current temperature (°F or °C) using Open-Meteo APIs.
- **Animated Patterns**: Select from wave, count up, or random patterns for fun display effects.
- **Responsive UI**: Scales beautifully across devices, with visually accurate SVG digit rendering and a baseplate background for alignment.

---

## 🚀 Getting Started

### 1️⃣ Open the App

Simply open `index.html` (or any of the provided HTML files) in your web browser. No installation or server required—everything runs locally in your browser.

### 2️⃣ Explore the Modules

- **Clock**: Default view. Choose 12hr/24hr and timezone. The display updates every 2 seconds.
- **Timer**: Set minutes and seconds, then start. Pause, stop, or reset as needed. When finished, a wave animation plays.
- **Stopwatch**: Start counting up. Pause, stop, or reset at any time.
- **Dice Simulator**: Select dice types (d2–d99) for left and right, then roll. Results show as two digits each.
- **Temperature**: Enter a city or location, click search, and see the current temperature. Switch between °F and °C.
- **Animated Patterns**: Pick a pattern to animate the display.

Switch between modules by clicking their cards. The active module is highlighted.

---

## 🖥️ Project Structure

- `index.html` (and copies): Main web app with all logic and UI.
- `7segdrawing_complete.svg`: SVG for accurate 7-segment digit rendering.
- `Clock baseplate.svg`: SVG background for display alignment.

---

## ⚙️ Requirements

- Any modern web browser (Chrome, Firefox, Edge, Safari, etc.)
- No server, microcontroller, or special hardware required

---

## 📋 How to Use

1. Open the HTML file in your browser.
2. Click a module card to activate it.
3. Use the controls in each module to interact with the display.
4. The 4-digit SVG display updates in real time based on your actions.

---

## 📄 License

This project is licensed under the MIT License.

---

*Originally inspired by physical 7-segment display projects. Now a full-featured browser-based simulator and visualization tool.* 
