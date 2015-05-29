/************************************************************************
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Version 1.0 / 2015-05-29 / DP / http://www.play-zone.ch
************************************************************************/

#include <Stepper.h>

// For the 28BYJ-48 Steppers
#define STEPS_PER_REVOLUTION 2038
#define STEPS_MOTOR 32
#define SPEED 600

// Init the stepper Object
// Connect In1 - In4 to Pins 8-11
Stepper stepper(STEPS_MOTOR, 8, 10, 9, 11);

void setup()  
{
  // Init the speed once during Arduino-Setup
   stepper.setSpeed(SPEED); 
}

void loop()  
{
  // One full revolution forward, then backward
  stepper.step(STEPS_PER_REVOLUTION);
  delay(1000);
  stepper.step(-STEPS_PER_REVOLUTION);
  delay(2000);
  
  // 1/4 revoluion (90 deg) forward, then backward
  stepper.step(STEPS_PER_REVOLUTION/4);
  delay(1000);
  stepper.step(-STEPS_PER_REVOLUTION/4);
  delay(2000);
}


