# ⌨️ Dragonfly 67 Keyboard
The Dragonfly 67 is an ergonomic split mechanical keyboard inspired by the Alice layout. It integrates high-end features like audio sliders and rotary encoders into a compact, 3D-printable form factor.

Will include the circuit diagram soon, i'm working on it. until then please go through the keyboard config and keymap files.

## ✨ Custom VIAL Firmware

This keyboard uses a custom fork of [VIAL](https://get.vial.today/) with patches applied to support **[deej](https://github.com/omriharel/deej)** — an open-source, hardware-based volume mixer.

---

### 🛠 Prerequisites

Before building, make sure you have the following set up on your system:

- **VIAL repository** — clone the custom fork from this repo
- **QMK MSYS** — the recommended build environment for Windows ([download here](https://msys.qmk.fm/))

> This repository also includes the full keyboard source code, ready to drop in.

---

### 📂 File Replacements

To enable deej support, **5 files** need to be replaced in your local QMK/VIAL source tree. All 5 files are included in this repository.

Copy them into the following locations:

#### `vial/tmk_core/protocol/chibios/`

| File | Description |
|------|-------------|
| `usb_driver.c` | USB driver implementation (patched for virtual serial) |
| `usb_driver.h` | USB driver header |
| `usb_main.c` | USB main logic (patched for deej CDC communication) |
| `usb_main.h` | USB main header |

#### `vial/quantum/`

| File | Description |
|------|-------------|
| `virtser.h` | Virtual serial interface header (required for deej) |

---

### 🔌 Why These Changes?

Standard VIAL firmware does not expose a virtual serial (CDC) interface, which is required by deej to communicate with the host over USB. These patches modify the ChibiOS USB driver and the VIAL virtual serial header to enable this interface without breaking normal HID functionality.

---

> **Note:** The keyboard source code for this board is also included in this repository.

### ✨ Key Features
* **Layout:** 67-key Alice (ergonomic split).
* **Brain:** Powered by the RP2040 Zero.
* **Control:** 3x Deej-compatible audio sliders + 1x Rotary Encoder.
* **Firmware:** Native QMK/VIAL support.
* **Connectivity:** USB-C main input with TRRS interconnect between halves.

### ⚠️ Build Notes
* **Primary Side:** Always connect the Left (Primary) half to the PC.
* **Hot-Plugging:** Do not connect/disconnect the TRRS cable while the USB is plugged in to avoid shorting the controller.
* **Supports:** The case is designed to be printed without supports if oriented correctly.