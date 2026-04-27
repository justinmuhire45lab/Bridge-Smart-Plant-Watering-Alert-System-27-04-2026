# Bridge-Smart-Plant-Watering-Alert-System-27-04-2026
component used:

resistor, soilmoisture sensor, led(2), breadboard, jumper wire, arduino uno, 

description:

1) What Is This Project?

An automatic soil moisture detection system that monitors soil water levels and alerts using two LEDs — one blinks when soil is dry, one glows steadily when soil is wet enough!

3) Purpose:

To automatically detect when a plant needs water and give a visual alert using LEDs without any manual checking!

block diagram:

┌─────────────┐
│  USB POWER  │
└──────┬──────┘
       │
       ▼
┌─────────────┐
│ ARDUINO UNO │
│             │
│  A0  ◄──────┼──────────────────┐
│             │                  │
│  Pin 6 ─────┼──────────────┐   │
│             │              │   │
│  Pin 8 ─────┼──────────┐   │   │
│             │          │   │   │
│  5V ────────┼───────┐  │   │   │
│  GND ───────┼────┐  │  │   │   │
└─────────────┘    │  │  │   │   │
                   │  │  │   │   │
                   ▼  ▼  │   │   │
              ┌─────────┐│   │   │
              │BREADBOARD││   │   │
              │          ││   │   │
              │  🔴LED1◄─┘│   │   │
              │  (Blink)  │   │   │
              │           │   │   │
              │  🟢LED2◄──┘   │   │
              │  (Normal)     │   │
              └───────────────┘   │
                                  │
                        ┌─────────┴──────┐
                        │ SOIL MOISTURE  │
                        │    SENSOR      │
                        │                │
                        │ VCC → 5V       │
                        │ GND → GND      │


logic digram
                        START
  │
  ▼
Read Soil Sensor (A0)
  │
  ▼
Is value > 500?
  │
  ├── YES (DRY) ──►  🔴 Red LED BLINKS
  │                  🟢 Green LED OFF
  │                  ⚠️ Plant needs water!
  │
  └── NO (WET) ───►  🟢 Green LED ON steady
                     🔴 Red LED OFF
                     ✅ Plant is fine!
  │
  ▼
Wait 500ms
  │
  ▼
REPEAT FOREVER
                        │ AOUT → A0      │
                        └────────────────┘
