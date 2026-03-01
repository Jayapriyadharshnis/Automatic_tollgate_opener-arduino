#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define trigPin 9
#define echoPin 8

Servo gateServo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int carCount = 0;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  gateServo.attach(3);
  gateServo.write(0); // Initial gate position: closed
  
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Cars Passed:");
  lcd.setCursor(0, 1);
  lcd.print(carCount);
}

void loop() {
  // Confirm car is really present with 3 readings
  int validCount = 0;

  for (int i = 0; i < 3; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    if (distance > 0 && distance < 10) {
      validCount++;
    }
    delay(100);
  }

  if (validCount >= 3) {
    gateServo.write(90); // Open gate
    delay(1000);         // Wait while open
    gateServo.write(0);  // Close gate
    delay(1000);         // Delay after close

    carCount++;

    lcd.setCursor(0, 1);
    lcd.print("Count: ");
    lcd.print(carCount);
    lcd.print("   ");

    // Wait until car moves away
    do {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = duration * 0.034 / 2;
      delay(200);
    } while (distance > 0 && distance < 10);
  }
}
