# Car-controller


A project used to remotely control car.

  

## Table of Contents

  

- [Components](#Components)

- [Connect](#Connect)

- [Usage](#usage)

- [License](#license)

- [Contact](#contact)

  

## Components

- 2x ESP32-WROOM-DA MODULE
- Arduino Nano
- Joystick HW-504
- SSD1306 128x64 using I2C communication
- Shield for Arduino Nano
- L298N circuit
- 2x battery 3.7V 

## Connect

#### Transfer Part
Connent ESP32 with these pins:
- VRx: GPIO 34
- VRy: GPIO 35
- SW(Switch): GPIO 32
- SCL: GPIO 22 
- SDA: GPIO 21
#### Receiver part
- RX, TX: connect with Arduino Nano
#### Arduino Nano (core)
- EN/A: GPIO 5
- IN1: GPIO 3
- IN2: GPIO 4
- IN3: GPIO 6
- IN4 GPIO 7
- EN/B: GPIO 9 
## Usage
*Upload the main.ino file to the Arduino Nano and enjoy.*
## License
This project is licensed under the GPL-3.0 License - see the [LICENSE](LICENSE) file for details.
## Contact

If you have any questions, suggestions, or issues, feel free to contact me:

- **Email**: [Huu Quy](mailto:huuquyk09@gmail.com)
- **Facebook**: [Huu Quy](https://www.facebook.com/profile.HuuQuy09)
- **Github**: [Hquy](https://github.com/hquy09)

