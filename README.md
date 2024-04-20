# Techno Keyboard
An arduino-based keyboard that can play techno music. 

## Introduction
The design is mainly based on the features of phototransistors. When a phototransistor is covered from light, the current it generates will decrease significantly. The input from phototransistor is analog, but with a threshold, it can be turned into two states: covered and not covered. 

If a tone is associated with the covered state, a phototransistor can act like a key on a musical keyboard. Compared to keys and buttons, phototransistors provides more flexibility in control. It allows the users to control the keyboard **contactlessly through gestures**. 

To make music, more than one tone is needed. Thus, four phototransistors are included to produce 2^4 combinations for controlling **16 different tones**. The tones are converted into frequencies, which can be played by a piezo. 

## Workflow
**setup**

Automatically calibrates each phototransistor in **real-time** according to the current state of the environment. The onboard LED will light up to indicate such process. 

**loop**

1. check the state of each phototransistor and generate the combination with **bit manipulation**; turn on LEDs that are associated with covered phototransistors
2. calculate the frequency based on the combination
3. sound the piezo with the frequency
   
## Schematic
<img width="500" alt="schematic" src="https://github.com/Zixuan-Qiao/Techno_Keyboard/assets/102449059/4f8c8cfe-6bf3-434e-8421-f424c1b7966c">

## Circuit Hardware
<img height="500" align="top" alt="hardware1" src="https://github.com/Zixuan-Qiao/Techno_Keyboard/assets/102449059/9ef64fa9-4c57-404e-ad1f-19b4c71827f5">

<img height="500" align="top" alt="hardware2" src="https://github.com/Zixuan-Qiao/Techno_Keyboard/assets/102449059/f4ee60e7-9780-4aaa-945d-2aae9c95b4e8">
