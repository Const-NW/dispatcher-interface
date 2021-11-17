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

const int pin1Button = 2;
const int pin2Button = 3;
const int pin3Button = 4;
const int pin4Button = 5;
const int pin5Button = 6;
const int pinTalkButton = 18;

const String copyright = "Dispatcher-interface v.1.3b. Copyright (c) 2021, konstantin Malinin (MIT license), Russia, Petrozavodsk, konstantine.1988@gmail.com";

const int delayTime = 300;

void setup() {
  pinMode(pin1Button, INPUT_PULLUP);
  pinMode(pin2Button, INPUT_PULLUP);
  pinMode(pin3Button, INPUT_PULLUP);
  pinMode(pin4Button, INPUT_PULLUP);
  pinMode(pin5Button, INPUT_PULLUP);
  pinMode(pinTalkButton, INPUT);

  Gamepad.begin();
  Gamepad.releaseAll();
  
  Serial.begin(9600);
  
  delay(delayTime * 10);

  Serial.println(copyright);
}

void checkPinButton(int pinButton) {

  int channelNumber = pinButton - 1;
  
  int pinVal = !digitalRead(pinButton);
  
  if (pinVal) {
    Gamepad.press(channelNumber);
  }
  else
  {
    Gamepad.release(channelNumber);
  }
  
  Serial.print(channelNumber);
  Serial.print(": ");
  Serial.print(pinVal);
  Serial.print("; ");
  
}

void checkTalkButton(int pinButton) {

  int pinVal = digitalRead(pinButton);
  
  if (pinVal) {
    Gamepad.press(pinButton);
  }
  else
  {
    Gamepad.release(pinButton);
  }

  Serial.print(pinButton);
  Serial.print(": ");
  Serial.print(pinVal);
  Serial.print("; ");

  int pinAnalogVal = analogRead(pinButton);

  Serial.print(pinButton);
  Serial.print("A: ");
  Serial.print(pinAnalogVal);
  Serial.print("; ");
}

void loop() {
  
  checkPinButton(pin1Button);
  checkPinButton(pin2Button);
  checkPinButton(pin3Button);
  checkPinButton(pin4Button);
  checkPinButton(pin5Button);
  
  checkTalkButton(pinTalkButton);
  
  Gamepad.write();

  Serial.print("sended information to HID. Delay: ");
  Serial.print(delayTime);
  Serial.println(". ");
 
  delay(delayTime);
}
