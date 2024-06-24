# STM32 USART Communication with ESP32

This project demonstrates how to set up USART communication between an STM32 microcontroller and an ESP32. The STM32 microcontroller sends a "Hello ESP32!" message to the ESP32 periodically.

## Project Structure
The main components of this project are:
- RCC_Configuration: Configures the Reset and Clock Control.
- GPIO_Configuration: Configures the General-Purpose Input/Output ports.
- USART_Configuration: Configures the Universal Synchronous/Asynchronous Receiver/Transmitter (USART).
- USART1_SendChar: Sends a single character via USART1.
- USART1_SendString: Sends a string of characters via USART1.
- USART1_ReceiveChar: Receives a single character via USART1.
## Hardware Requirements
STM32 microcontroller (e.g., STM32F103C8T6)
ESP32 development board
USB-to-Serial adapter for programming the STM32
Software Requirements
STM32CubeMX (for configuration)
Keil uVision or any other suitable IDE for STM32 development
ST-Link V2 (for programming and debugging the STM32)
## Connections
Connect the USART1 TX pin (PA9) of the STM32 to the RX pin of the ESP32.
Connect the USART1 RX pin (PA10) of the STM32 to the TX pin of the ESP32.
Connect the ground (GND) pins of both devices together.
