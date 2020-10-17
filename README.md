# 3D Printed Macro Keyboard

A Pro Micro board based, 3D printed, triple-layout macro keyboard with mechanical switches (Arduino IDE programmable). 

Watch a short demo video [about the keyboard in action.](https://youtu.be/DfZe0mD9_6g)

### Table of contents

<!--ts-->
   * [Specifications](#specifications)
   * [Compatibility](#compatibility)
   * [Folders](#folders)
   * [Dependencies](#dependencies)
   * [Ideal 3D printing orientations](#ideal-3d-printing-orientations)
<!--te-->

<p align="center">
<img width=80% height=80% src="/resources/github-cover.jpg">
</p>


## Specifications
Main features:
- 4 x 4 key configuration
- three different switchable layouts, which means 3 x 16 programmable shortcuts
- mechanical switches
- no additional software required after programming

**Note:** the switches used for this project are salvaged from an old mechanical keyboard. Before printing the enclosure, make sure that your switches will fit in the mounting holes.

## Compatibility
The Pro Micro board emulates an HID device which grants cross-platform and cross-device compatibility.

Tested with:
- Windows
- Linux (Ubuntu)
- Android (with OTG support)

## Folders
- **FCStd:** 3D models designed in FreeCAD.
- **STL:** 3D printable 3D models
- **firmware:** Arduino code. See the "Dependencies" for the required libraries.
- **schematic:** schematic diagram in .sch and .pdf format. The schematic was designed in Autodesk EAGLE 9.2.0

## Dependencies
To compile the project, the following libraries are required:
  - HID-Project - v3.1.1: https://github.com/NicoHood/HID
  - Keypad - v2.6.1: https://playground.arduino.cc/Code/Keypad/
  
  ## Ideal 3D printing orientations
  
<p align="center">
<img width=50% height=50% src="/resources/ideal-orientation-top.jpg">
</p>

<p align="center">
<img width=50% height=50% src="/resources/ideal-orientation-bottom.jpg">
</p>
  
  <hr>
  
  #### For more projects and research, visit my website: https://mzsoltmolnar.github.io/
