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
| TFT_eSPI | Display initialization and graphics |
| AnimatedGIF | GIF decoding and playback |
| LittleFS | On-device animation storage |
| NTP | Network time synchronization |

The software is designed to support expressive animations, time-aware experiences, and future interactive features while remaining lightweight enough for embedded hardware.

---

## 🎞️ Bringing Animations to Life

Animation is at the heart of Snoopy's Little World.

GIF assets are prepared for the display, stored in the ESP32's internal flash memory, and decoded directly on the device.

The animation pipeline focuses on:

- **Color accuracy** — Preserving the intended colors on the TFT display.
- **Transparency handling** — Rendering animated elements without unwanted artifacts.
- **Smooth playback** — Maintaining natural movement and consistent frame timing.
- **Efficient storage** — Keeping animation assets within the constraints of embedded flash memory.
- **Extensibility** — Supporting a growing collection of animations and visual experiences.

The objective isn't simply to play an animation — it's to make the tiny world feel alive.

---

## 🚀 Getting Started

### Prerequisites

- A compatible ESP32 TFT development board
- Visual Studio Code with PlatformIO, or the PlatformIO CLI
- A USB data cable

### 1. Clone the Repository

```bash
git clone <your-repository-url>
cd SnoopyLittleWorld
```

### 2. Build the Firmware

```bash
pio run
```

PlatformIO will install the configured framework and dependencies.

### 3. Upload the Firmware

```bash
pio run --target upload
```

If automatic port detection fails, specify the serial port:

```bash
pio run --target upload --upload-port /dev/cu.usbserial-1420
```

Replace the example port with the one detected on your machine.

### 4. Upload Animation Assets

Place processed GIF files inside the `data/` directory and upload the LittleFS filesystem:

```bash
pio run --target uploadfs
```

### 5. Open the Serial Monitor

```bash
pio device monitor --baud 115200
```

---

## 🌱 Design Philosophy

### Small Hardware. Big Personality.

Snoopy's Little World is guided by a few simple principles:

**Personality over complexity**

The experience should feel charming and expressive, without requiring complicated interactions.

**Technology should disappear**

The electronics are there to support the experience, not dominate it. The finished device should feel like a miniature world rather than a development board.

**Little moments matter**

A familiar animation, a personalized message, or a small surprise can be more meaningful than a long list of features.

**Built to evolve**

The project is designed to grow with new animations, interactions, and ideas over time.

---

## ❤️ The Story Behind It

Snoopy's Little World started with a simple idea: **create something special for my daughter.**

Not another screen. Not another electronic toy.

Something handmade, personal, and a little magical.

A tiny companion that could make her smile, deliver unexpected messages, celebrate little moments, and bring a bit of imagination to her desk.

It's a combination of software engineering, electronics, creativity, and the joy of building something for someone you love.

And perhaps that's the best part of the project — the technology is only a means to create something meaningful.

---

*Made with ❤️, C++, and a little imagination.*

### Disclaimer

Snoopy's Little World is an independent, personal fan project. It is not affiliated with, sponsored by, or endorsed by Peanuts Worldwide or its rights holders.

Snoopy, Woodstock, and related characters are the property of their respective owners.