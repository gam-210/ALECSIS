**Expected List of Features:**

One vibrating wristband and one sensor clip/belt;


Reliable in terms of detection of obstacles;
Wearable and discrete : we chose to separate the sensor part and the wristband;
Easy on / off : we want our device to be easily shut on / off, for the user to adapt its use to specific situations, where detection of obstacles may not be needed or suitable (a crowd for example);
Cheap and open-source;
Easy to put on and implement.


**LIST OF COMPONENTS AND PRICE OF OUR DEVICE:**

Ultrasonic sensor LV-MaxSonar-EZ3: 29.95 €;
2 Adafruit Feather nRF52840 boards:  2 x 34,65 €;
Mini vibration motor 3,5 x 17: about 1 €;
Arduino switch: 1,33 €;
2 batteries: 2 x 9,90 €;
USB wire: 1 €;
Wires: a few cents;
Tissue: a few cents;
Inserts + screws: a few cents;
PLA for the 3D printing: a few cents.

Total cost = 125 € 
Without bluetooth the device would have cost approximately 45 € (we would have used a Arduino nano instead of Feather boards)

**Tips:**

Install Adafruit Feather nRF52840 card on Arduino: copy this link in Arduino/Files/Preferences/URL: https://www.adafruit.com/package_adafruit_index.json 
and then search Adafruit Feather nRF52840 in Tools/Board/ board manager/.

LV-MaxSonar-EZ3 ultrasonic sensor in PW mode: distance ranges from 18 cm to 320 cm. The angle of detection of the sensor is of approximately 20°.

The caps of the boxes are held by 2mm screws in 3mm screw inserts.

**Results:**
The two boards automatically connect to each other when we turn the switch on. The battery autonomy is quite short. The delay for transmitting the data is undetectable : the motor starts to vibrate as soon as the user is closer than 120 cm from the obstacle. The sensor is very sensitive and detects numerous objects and obstacles from the surrounding environment. The motor is therefore often vibrating, and the motor waggles in its capsule. This produces a loud noise which can be very annoying for the user. It takes at least 1 or 2 seconds for the motor to stop vibrating when the sensor is switched off.

**And in the future ?**

Some elements could be improved to better the current state of the project; some improvements and further analysis may not require too much time and could be easily conducted : 
We would firstly fix the circuit elements inside the cases, in order to facilitate the manipulation and to avoid any wire detachment ; 
We would also want to check the battery autonomy, to be able to inform the user on this subject and allow him or her to know when the device needs to be plugged for recharge ; 
Finally, after testing our final prototype, we realized that the movement of the motor inside the case led to a disturbing noise. By fixing the motor more tightly in its own case currently located on the bracelet cap, using tape or sticking paste for example, we could try to reduce the noise.

Other modifications that would require some more work could also be implemented :
We could first try to miniaturize the device. As the case is currently fitted to the size of the Arduino Feather card, we should conduct research on the different available arduino cards working with bluetooth, to maybe find a smaller (and maybe cheaper) one. We could also try to change the rectangular shape of the case for a more practical and comfortable use. We could for example create a “curved” box for the wristband, and try one of our previous ideas which was to create a clip mechanism for the sensor part instead of the belt, for one to be able to attach the sensor box anywhere on its clothes. 
Moreover, we should work on the sensor part. This one has a wide range of detection, and is therefore very sensitive and thus not really precise. It also had a tendency to vibrate when there were no objects in front of the user. This might come from the fact that the sensor detects the user itself. This is a big issue that needs to be fixed, maybe simply by protruding it more out of the box. We could also try to combine multiple sensors for better obstacle detection (for example, detecting objects on the sides, for the user to not hit any body part, or detecting lower body obstacles). We should however be careful about the potential interferences between the sensors. 
One interesting aspect would be to find a way to detect and differentiate non-living objects from humans in order for the device not to vibrate if the user is in a crowded place . We could for example use infrared sensors that could measure the object temperature (alive obstacles being having a higher temperature), or we could try using a camera combined to an image recognition machine learning program, trained to differentiate living animals from urban furniture. 
Finally, we could implement different modes (distance of detection, different vibration patterns…) in the device, for the user to be able to adapt its use to various contexts. 

This non-exhaustive list of ideas could be considered as starting points to continue the project. We finished the week with a satisfying prototype considering the time frame of the project. We would be pleased to see someone interested in the project trying to continue and even improve what was done, be it with the previous mentioned ideas or with all new ones !
