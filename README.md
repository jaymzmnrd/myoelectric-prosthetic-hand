
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


## Prototype Mechanical Design

Final Prototype

Isometric View with Phantom Tangent Lines and Fingers Articulated

Front and Back View

Exploded View of the Device

Semi-Open View of the Power Supply Section

## Fabrication of (3D Printing) the Prototype

3D printing calibration test

3D Printed Parts on the Printer Build Plate

Parts flat lay on cutting mat

Post processed sleeve with velcro strap attached



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
- **vincentponong**"# myoelectric-prosthetic-hand" 
