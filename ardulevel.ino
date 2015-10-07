/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * This software can be used with an Arduino Board (tested with Arduino UNO)
 * to detect the logic levels connected to A0 port. Useful if you don't
 * know if you have a 5V or 3.3V I/O device. The result is send to the serial 
 * port ten times a second at 9600 baud.
 * 
 * Written by Mirko Denecke
 *
 */

unsigned long time;
int val;
int max;
int min;


void setup() {
  Serial.begin(9600);
}

void loop() {
  time = millis();
  max = 0;
  min = 1024;

  /* Check high and low level (100ms) */
  while((time + 100) > millis()) {
    val = analogRead(0);
    
    if(val < min) {
      min = val;  
    }

    if(val > max) {
      max = val;
    }
  }

  /* Print result to serial port and start again */
  Serial.print("Min: ");
  Serial.print((5.0f / 1024.0f) * (float)min);
  Serial.print(" Volt  Max: ");
  Serial.print((5.0f / 1024.0f) * (float)max);
  Serial.println(" Volt");
}
