# 🐶 Snoopy's Little World

**A tiny animated world, powered by ESP32 and a little imagination.**

Snoopy's Little World is a handcrafted desktop diorama that combines embedded electronics, animated graphics, and miniature design to bring Snoopy's world to life.

Built around an ESP32 and a TFT display, the project explores how simple hardware can create something playful, expressive, and personal.

A little world with a personality of its own.

---

## ✨ The Idea

Imagine a tiny Snoopy-inspired world sitting on your desk.

Snoopy typing away at his typewriter, the atmosphere changing throughout the day, and little surprises appearing when you least expect them.

More than just a digital display, Snoopy's Little World is designed to feel like a miniature companion.

### What Makes It Special

- 🎞️ **Animated Moments** — Charming animations that bring the miniature world to life.
- 🕒 **Time Awareness** — A clock and time-based behaviors that connect the experience to the real world.
- 🌅 **Dynamic Atmosphere** — Different moods and scenes for morning, afternoon, evening, and night.
- 💌 **Personal Messages** — Wi-Fi connectivity for sending messages and creating special moments.
- 🎛️ **Physical Interaction** — A rotary encoder for simple, tactile interactions.
- 🏡 **Miniature World** — A custom-designed enclosure that blends the electronics into a physical diorama.

The goal is simple: **make technology feel a little more magical.**

---

## 🛠️ Hardware

The project uses compact, accessible hardware to create an expressive desktop experience.

| Component | Description |
|---|---|
| Microcontroller | ESP32 |
| Development Board | ESP32-2432S032 series |
| Display | 3.2" TFT, 320 × 240 |
| Storage | Internal flash using LittleFS |
| Input | EC11 rotary encoder |
| Power | 5V USB-C |
| Enclosure | Custom 3D-printed diorama |

The integrated ESP32 display board keeps the electronics compact, making it easier to incorporate them into a miniature physical environment.

---

## 💻 Technology

The firmware is written in **C++**, using the Arduino framework and PlatformIO.

| Technology | Purpose |
|---|---|
| Arduino Framework | ESP32 firmware development |
| PlatformIO | Build and firmware management |
| TFT_eSPI | Display initialization