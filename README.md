
# EMG Controlled Prosthetic Hand

Electromyography-controlled prosthetic hand for transradial amputees aims to produce an electrically powered prosthesis with custom machine learning system. Machine learning integration intend to predict the actions that the user might do, this considerably helps when a user is doing their usual activities. 3D-printed prosthesis is a way for the proponents to cut the price of the expensive prosthesis without sacrificing its quality such as sturdiness and ability to handle material stress.


## Objectives

- To design a more affordable upper limb prosthesis
prostheses
- To design a lightweight myoelectric prosthetic hand
- To improve the feedback and control system of existing upper limb 3D-printed
- To implement reliable EMG sensors to detect muscle signals accurately.

## Scopes 

- **Surface Electromyography (sEMG):** The proponents decided to use the MyoWare Muscle Sensor. This is a silicon electrode sensor that measures the potential difference electromyography signals (EMG) that trigger when the body flexes and moves. It provides a more natural way of controlling a prosthetic hand with as, these sensors provide good enough results, and they are affordable.

- **Sensor Feedback:** These sensors provide information to the microcontroller about how much force is being applied at each fingertip. This provides some basic sensory feedback to the user letting them know if they are grasping an object and how much force they are applying.

- **3D-Printed Prosthetics:** 3D-printed prosthetics can be manufactured rapidly, compared to traditional ones. Traditional prosthetics can take several weeks, even months to produce and can be costly. But with 3D printing, it can be an affordable alternative. Designs can be easily altered and 3D printing is a low-cost production method.

- **Machine Learning:** The proponents used custom machine learning to improve the functionality and user experience. By utilizing a machine learning algorithm, the prosthetic hand can learn from user input and adapt to individual needs and preferences. This algorithm can adjust the prosthetic hand behavior and movements to better match the user’s intention.

- **Hand Gestures:** The five (5) grasping hand gestures are designed to test the myoelectric control system and the hand design, which include fist, hook, point, rest, and tip. These hand gestures can complete most grasp tasks in activities of daily living.

## Demo

https://github.com/jaymzmnrd/myoelectric-prosthetic-hand/assets/138496409/c092599a-3ad5-4420-96b6-6acefebec770


## Prototype Mechanical Design

**Final Prototype**

![Final Prototype](https://github.com/jaymzmnrd/myoelectric-prosthetic-hand/assets/138496409/1247a9a5-0b9e-4ddc-ad83-d7df15424be1)

**Isometric View with Phantom Tangent Lines and Fingers Articulated**

![Isometric view with phantom tangent lines and fingers articulated](https://github.com/jaymzmnrd/myoelectric-prosthetic-hand/assets/138496409/84c32282-3cde-4bc8-899f-6c96c899197e)

**Front and Back View**

![Front and back view](https://github.com/jaymzmnrd/myoelectric-prosthetic-hand/assets/138496409/a756ab28-ecb3-4460-8c73-9b532040ecc7)

**Exploded View of the Device**

![Exploded view of the device](https://github.com/jaymzmnrd/myoelectric-prosthetic-hand/assets/138496409/94fed80d-481d-4ff3-96da-b90e93d338ab)

**Semi-Open View of the Power Supply Section**

![Semi-open view of the power supply section](https://github.com/jaymzmnrd/myoelectric-prosthetic-hand/assets/138496409/359592a3-a284-4c18-9930-efee12722977)

## Source Code

This file provides outlines the specifications and requirements for the project.
```bash
  docs
```

Code for data collection and processing EMG data on the Arduino.

```bash
  data_collection.py
```
Code for controlling the prosthetic arm
```bash
  main.ino
```

Code for reading data from the EMG sensor.
```bash
  test_emg_sensor.ino
```
code for sensory feedback from fingertip.
```bash
  test_force_sensor.ino
```

Code for controlling the prosthetic hand's motors.
```bash
  test_motor_control.ino
```

## Authors

- **jamescenina**
- **astrostaana**
- **rolansanchez**
- **vincentponong**
