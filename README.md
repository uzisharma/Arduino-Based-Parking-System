# Arduino-Based-Parking-System

## Overview
This project showcases an automated car parking system using Arduino Uno, featuring 2 IR sensors for vehicle detection, a display showing available slots, and indicators for parking status.

## Hardware Requirements
- Arduino Uno
- 2 IR sensors
- Servo motor
- Display (LCD with I2C Driver)
- Green and red (Indicator Light)
- Buzzer

###  Connect the Hardware Components
Refer to the circuit diagram provided below and connect the components accordingly:
## Circuit Diagram
![Coming_Soon](coming-soon)

###  Upload the Arduino Code
1. Open the Arduino IDE (Integrated Development Environment) on your computer.
 1. Download the "LiquidCrystal_I2C-1.1.2.zip" file from [Here](https://www.arduinolibraries.info/libraries/liquid-crystal-i2-c).
 2. In Arduino IDE, goto, 'SKETCH'--> 'INCLUDE LIBRARY'--> 'ADD ZIP LIBRARY'--> Select the above downloaded ZIP file and Click--> OPEN.

3. Copy the provided Arduino code and paste it into a new Arduino sketch.
4. Save the sketch with a descriptive name (e.g., "Car_Parking_System.ino").
5. Connect your Arduino Uno to your computer via USB.
6. Select the appropriate board (Arduino Uno) and port from the "Tools" menu in the Arduino IDE.
7. Click the "Upload" button to upload the code to the Arduino Uno.

###  Power Up the System
1. Make sure all connections are secure and correct.
2. Power up the Arduino Uno by connecting it to an appropriate power source.
3. Verify that the display, IR sensors, green light, and red light are operational.
4. Test the system by simulating car arrivals and departures to ensure accurate slot count and status indicators.

That's it! Your Automated Car Parking System should now be set up and running.



## Code Explanation
```cpp
// coming soon
```

## Functionality
The automated car parking system offers the following features:

1. **Vehicle Detection**: Two IR sensors efficiently detect incoming and outgoing vehicles.
2. **Display**: The system provides real-time information on available parking slots.
3. **Parking Status Indicators**: A green light signifies an empty parking space.
4. **Full Parking Alert**: When all slots are occupied, the light turns red, and a buzzer sounds if a car attempts to enter.

Additionally, when a car is detected by the IR sensor during entry or exit, a **servo motor** smoothly opens the gate, allowing seamless movement.

This comprehensive functionality ensures efficient parking management and enhances user experience.

## Limitations
- When the "Entring Vehicle and the Exiting Vehicle" both comes at the gate at the same time, program shows unaccepted behaviour.
- Future improvements could include expanding parking capacity and code optimization.

## Contributing
Contributions are welcome! Please follow the guidelines in [CONTRIBUTING.md](CONTRIBUTING.md) for details on how to contribute.

## Troubleshooting
If you encounter issues during setup or usage, refer to [TROUBLESHOOTING.md](TROUBLESHOOTING.md) for solutions.

## License
This project is licensed under the [Coming_Soon](LICENSE).

## Credits
- IR sensor library by [Comming_Soon](link-to-library)
- Inspired by [Coming_Soon](link-to-inspiration)

## Contact Information
For questions or feedback, feel free to reach out via email at
[sujanadhikary.ece@gmail.com](mailto:sujanadhikary.ece@gmail.com)
[ujjwalsharma.ece@gmail.com](mailto:ujjwalsharma.ece@gmail.com)

## Demo
[Link to Video Demo(Coming_soon](link-to-your-demo-video-or-images)

