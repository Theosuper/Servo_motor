// bibliotecas são códigos prontos q nós só usamos
#include <Servo.h>
Servo servo;
int angle = 0;
int buttonPin = 7 ; 
int servoPin = 8;
int buttonState = 0;
int lastButtonState = 0;
bool servoPosition = false; // false é 0 true 90
void setup() {
  servo.attach(servoPin);
  servo.write(angle);
  pinMode(buttonPin,INPUT);
}
void loop() {
  buttonState = digitalRead(buttonPin); // checando se o botão ta apertado
  if (buttonState == HIGH && lastButtonState == LOW) {
    // se o botão estiver apertado eu troco o valor do servo
    servoPosition = !servoPosition;
    if (servoPosition) {
      servo.write(90);
    } else {
      servo.write(0);
    }
    delay(200);
  }
  lastButtonState = buttonState;
}
