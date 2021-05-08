# Fire-Detection-Alarm-Using-Arduino

TinkerCAD LINK: https://www.tinkercad.com/things/kS91Rh8O9X0

Fire alarm detection project demonstrates the use of Arduino to build a fire detection system using the sensors which measure temperature of the environment in which it is present and also measure concentration of gas that might cause fire (methane, alcohol) or is caused because of fire (carbon monoxide, carbon dioxide etc.).

The fire alarm detection system remains idle unless there is a fire outbreak. The system in idle condition glows green LED, keeps the micro servos(doors) closed, displays SAFE message on the LCD display along with the current temperature and gas concentration in the room/hall where the sensors are installed.

With a gas leak or a fire outbreak in a given room, halls or any part of the building where the sensors are installed, the Arduino will start the blinking red LED, shows warnings on the LCD display, turns on the siren, in our case a buzzer and opens the micro servos(doors) to indicate people to move out of the building into a safe area to avoid any kind of burns or injuries.

The system remains in alert mode until the fire is extinguished leading to reduction in temperature and gas concentration in the room. The system only switches back to idle mode after the fire is extinguished and the reset button is long pressed.
