# Introduction to Robotics 2021-2022 course
Personal repo with homeworks for the Robotics Course

Professor: Andrei Dumitriu  <br />

#  Homework 1 - Light up an RGB led

## Components 
* RGB led
* potentiometers
* rezistors and wires 

## Task requirement 
Control each of the color of the RGD led using potentiometers. Control is done using digital electronics (values of the potentiometers are read by Arduino and map the values to each of the pins connected to the leds)

## Setup 
![setup1](Labs/Lab2/setup.png)

## Demo
[See drive](https://drive.google.com/drive/folders/105TRyTHTtz6iL83V6PBk72QXlePSrPj8?usp=sharing)

# Homework 2 - traffic lights

## Components
* 5 LEDs
* 1 button
* 1 buzzer
* resistors and wires

## Task requirement
Building the traffic lights for a crosswalk. You will use 2 LEDs to represent the traffic lights for people (red and green) and 3 LEDs to represent the traffic lights for cars (red, yellow and green). See the states it needs to go through. The system has the following states:  <br />
1. State 1 (default, reinstated after state 4 ends): green light for cars, red light for people, no sounds. Duration: indefinite, changed bypressing the button.  <br />
2. State 2 (initiated by counting down 10 seconds after a button press): the light should be yellow for cars, red for people and no sounds. Duration: 3 seconds.  <br />
3. State 3 (iniated after state 2 ends): red for cars, green for people and a beeping sound from the buzzer at a constant interval. Duration: 10 seconds.  <br />
4. State 4 (initiated after state 3 ends): red for cars, blinking green for people and a beeping sound from the buzzer, at a constant inter-val, faster than the beeping in state 3.

## Setup
![setup2](https://user-images.githubusercontent.com/38779396/139524678-d4aa1c74-22b8-4e1f-8fa2-507e6f4b14b7.jpeg)

## Demo
[See drive](https://drive.google.com/drive/u/0/folders/1SXXBnAHsnufreV9IFxkJL2gmYjxHxa6U)

# Homework 3 - ghost detector

## Components
* LEDs
* buzzer 
* button
* rezistors and wires

## Task requirement
Create a ghost detector. Easy, no?

## Setup 
![setup3](https://user-images.githubusercontent.com/38779396/141203243-4489a3a9-fc11-4704-9d58-fe58293c4d6e.jpeg)

## Demo 
[See drive](https://drive.google.com/drive/u/0/folders/1VWkwG3smvf_Bjzj2toNV0GQhcY-HZdSa)

# Homework 4 - change the digits

## Components
* LEDs 
* button
* rezistors and wires
* 4 - 7 segment display 
* joystick

## Task requirement
You have 4 digits, all 0. You have a point at a certain position. With the joystick you can move the point from a digit to another. Push the button of the controller and you unlock the next feature: increase or decrease the digit. When you unlock, the point should blink (we use oX and oY for these 2 operations: move point and increase/decrease).

## Setup 
![set5](https://user-images.githubusercontent.com/38779396/142248243-bdd2b7c4-abd1-425e-9ec0-84c1aa4f2157.jpeg)

## Demo 
[See drive](https://drive.google.com/drive/u/0/folders/1ZFQe1CRKplVd56DBlkVhd5qQcSFEtaqE)

