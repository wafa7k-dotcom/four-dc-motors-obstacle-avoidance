# four-dc-motors-obstacle-avoidance
Complete Tinkercad Arduino simulation using four DC motors, dual L293D drivers, an ultrasonic sensor, and a servo motor for obstacle avoidance.

# Four DC Motors Obstacle Avoidance
![Uploading image.png…]()

## Project Description

This project combines two Arduino simulation tasks into one complete Tinkercad circuit.

The first part controls four DC motors using two L293D motor driver ICs.  
The second part adds an HC-SR04 ultrasonic sensor and an SG90 servo motor for obstacle detection and direction scanning.

## Project Operation

The system performs the following sequence:

1. The four DC motors move forward for 30 seconds.
2. The four DC motors move backward for 60 seconds.
3. The motors alternate between turning right and left for 60 seconds.

The HC-SR04 ultrasonic sensor continuously measures the distance in front of the system.

When an obstacle is detected at a distance of 10 cm or less:

- All DC motors stop immediately.
- The servo motor rotates right and left to scan the surrounding area.
- The motors move backward for a short time.
- The system changes direction to avoid the obstacle.

## Components

- Arduino Uno
- 4 × DC Motors
- 2 × L293D Motor Driver ICs
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- Breadboard
- Jumper Wires

## Connections

### First L293D

- Pin 16 → 5V
- Pin 8 → 5V
- Pin 1 → 5V
- Pin 9 → 5V
- Pin 4 → GND
- Pin 5 → GND
- Pin 12 → GND
- Pin 13 → GND
- Pin 2 → Arduino D2
- Pin 7 → Arduino D3
- Pin 10 → Arduino D4
- Pin 15 → Arduino D5

Motor 1:
- Terminal 1 → Pin 3
- Terminal 2 → Pin 6

Motor 2:
- Terminal 1 → Pin 11
- Terminal 2 → Pin 14

### Second L293D

- Pin 16 → 5V
- Pin 8 → 5V
- Pin 1 → 5V
- Pin 9 → 5V
- Pin 4 → GND
- Pin 5 → GND
- Pin 12 → GND
- Pin 13 → GND
- Pin 2 → Arduino D6
- Pin 7 → Arduino D7
- Pin 10 → Arduino D8
- Pin 15 → Arduino D9

Motor 3:
- Terminal 1 → Pin 3
- Terminal 2 → Pin 6

Motor 4:
- Terminal 1 → Pin 11
- Terminal 2 → Pin 14

### Servo Motor

- Signal → Arduino D10
- VCC → 5V
- GND → GND

### HC-SR04 Ultrasonic Sensor

- Trig → Arduino D11
- Echo → Arduino D12
- VCC → 5V
- GND → GND

## Software

- Tinkercad Circuits
- Arduino IDE

## Features

- Four DC motor control
- Forward and backward movement
- Alternating right and left turns
- Ultrasonic obstacle detection
- Automatic motor stop
- Servo-based area scanning
- Automatic direction change

## Files

- FourMotorObstacleAvoidance.ino
- README.md
- circuit.png


## Author

Wafaa Aluhaidan
