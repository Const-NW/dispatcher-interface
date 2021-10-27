/*
 *  Project     Dispatcher-interface
 *  @author     Konstantin Malinin
 *  @link       github.com/Const-NW/dispatcher-interface
 *  @license    MIT - Copyright (c) 2021 Konstantin Malinin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *  The project uses the library Arduino HID Project by (c) 2021 NicoHood (MIT license). Thank him for his hard work.
 *
 */

#include "HID-Project.h"

const int pin2Button = 2;
const int pin3Button = 3;
const int pin4Button = 4;
const int pin5Button = 5;
const int pin6Button = 6;
const int pin7Button = 7;
const int pin8Button = 8;

const String copyright = "SELECTOR-ADAPTER-8CH v.1.0b. Copyright (c) 2021, Neoservice LTD, Russia, Petrozavodsk, info@neocom-karelia.ru";

const int delayTime = 300;

void setup() {
  pinMode(pin2Button, INPUT_PULLUP);
  pinMode(pin3Button, INPUT_PULLUP);
  pinMode(pin4Button, INPUT_PULLUP);
  pinMode(pin5Button, INPUT_PULLUP);
  pinMode(pin6Button, INPUT_PULLUP);
  pinMode(pin7Button, INPUT_PULLUP);
  pinMode(pin8Button, INPUT_PULLUP);

  Gamepad.begin();
  Gamepad.releaseAll();
  
  Serial.begin(9600);
  
  delay(delayTime * 10);

  Serial.println(copyright);
}

void checkPinButton(int pinButton) {
  if (!digitalRead(pinButton)) {
    Gamepad.press(pinButton);
    Serial.print("Pressed:  ");
    Serial.print(pinButton);
    Serial.print("; ");
  }
  else {
    Gamepad.release(pinButton);
    Serial.print("Released: ");
    Serial.print(pinButton);
    Serial.print("; ");
  }
}

void loop() {
  
  checkPinButton(pin2Button);
  checkPinButton(pin3Button);
  checkPinButton(pin4Button);
  checkPinButton(pin5Button);
  checkPinButton(pin6Button);
  checkPinButton(pin7Button);
  checkPinButton(pin8Button);
  
  Gamepad.write();

  Serial.print("Sended information to HID. Delay: ");
  Serial.print(delayTime);
  Serial.print(". ");
  Serial.println(copyright);
  
  delay(delayTime);
}
