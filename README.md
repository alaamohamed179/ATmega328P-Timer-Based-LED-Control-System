# ATmega328P-Timer-Based-LED-Control-System

## 📌 Project Overview

This project demonstrates the use of the three hardware timers (Timer0, Timer1, and Timer2) of the ATmega328P microcontroller to control LEDs and push buttons.

Each timer is configured in a different operating mode to perform a specific task, including LED blinking, PWM brightness control, and button debouncing.

## 🎯 Objectives

- Use Timer0 in CTC mode to control LED blinking speed.
- Use Timer1 in Fast PWM mode to control LED brightness.
- Use Timer2 in Normal mode to generate a delay for button debouncing.
- Control LED behavior using two push buttons.
- Understand hardware timers, interrupts, and PWM techniques.

## 🛠️ Components Used

- ATmega328P microcontroller (Arduino Uno).
- 3 LEDs.
- 3 resistors (100Ω).
- 2 push buttons.
- Connecting wires.
- SimulIDE for circuit simulation.

## 🔌 Pin Configuration

Component| Arduino Pin| ATmega328P Pin
Blinking LED| D8| PB0
Fading LED| D9| PB1 (OC1A)
Extra LED| D10| PB2
Button 1| D2| PD2
Button 2| D3| PD3

## ⚙️ Timer Configurations

1. Timer0 – CTC Mode

- Used to control the blinking LED connected to PB0.
- Generates periodic Compare Match interrupts.
- The LED blinking speed is adjusted by changing the compare interval.

2. Timer1 – Fast PWM Mode

- Configured in 8-bit Fast PWM mode.
- Uses the OC1A output pin (PB1).
- Controls the brightness of the second LED by changing the PWM duty cycle.

3. Timer2 – Normal Mode

- Configured with a prescaler of 1024.
- Used to generate a delay for button debouncing.
- Helps prevent multiple activations caused by a single button press.

## 🎮 System Operation

Button 1 – Blinking Speed Control

Each press changes the blinking speed of the LED connected to PB0 through three different speed levels:

- Slow
- Medium
- Fast

Button 2 – Brightness Control

Each press increases the brightness of the LED connected to PB1 through four levels:

- 0 (OFF)
- 80
- 160
- 255 (Maximum brightness)

Extra LED

The LED connected to PB2 remains ON to indicate that the system is running.

## 💻 Software and Tools

- Arduino IDE / AVR C++.
- SimulIDE.
- ATmega328P Microcontroller.

## 📚 Key Concepts

- AVR Registers and Bit Manipulation.
- Timer and Counter Configuration.
- CTC Mode.
- Fast PWM Mode.
- Normal Mode.
- Hardware Interrupts (ISR).
- Prescalers.
- PWM Duty Cycle.
- Button Debouncing.

## 🚀 Expected Results

The system successfully demonstrates how three hardware timers can work together to perform different tasks:

- Adjustable LED blinking speed.
- Adjustable LED brightness.
- Reliable push-button operation using debouncing.
- Independent timer-based operations.

## 👩‍💻 Author

Alaa Mohamed

Computer and Systems Engineering Student

## 📖 Conclusion

This project provides practical experience with the ATmega328P hardware timers and demonstrates how different timer modes can be used to control external components efficiently.
