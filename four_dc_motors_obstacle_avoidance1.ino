#include <Servo.h>

Servo scanServo;

// الشريحة الأولى
const int motor1A = 2;
const int motor1B = 3;

const int motor2A = 4;
const int motor2B = 5;

// الشريحة الثانية
const int motor3A = 6;
const int motor3B = 7;

const int motor4A = 8;
const int motor4B = 9;

// السيرفو والحساس
const int servoPin = 10;
const int trigPin = 11;
const int echoPin = 12;

void setup() {
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);

  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);

  pinMode(motor3A, OUTPUT);
  pinMode(motor3B, OUTPUT);

  pinMode(motor4A, OUTPUT);
  pinMode(motor4B, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  scanServo.attach(servoPin);
  scanServo.write(90);

  stopMotors();

  Serial.begin(9600);
}

void loop() {
  // للأمام لمدة 30 ثانية
  runMovement(1, 30000);

  // للخلف لمدة 60 ثانية
  runMovement(2, 60000);

  // يمين ويسار بالتناوب لمدة 60 ثانية
  unsigned long startTurning = millis();

  while (millis() - startTurning < 60000) {
    runMovement(3, 3000);  // يمين 3 ثوان
    runMovement(4, 3000);  // يسار 3 ثوان
  }

  stopMotors();
  delay(1000);
}

// تشغيل حركة مع فحص الحساس
void runMovement(int movementType, unsigned long movementTime) {
  unsigned long startTime = millis();

  while (millis() - startTime < movementTime) {
    float distance = readDistance();

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance > 0 && distance <= 10) {
      avoidObstacle();
    } else {
      if (movementType == 1) {
        moveForward();
      } 
      else if (movementType == 2) {
        moveBackward();
      } 
      else if (movementType == 3) {
        turnRight();
      } 
      else if (movementType == 4) {
        turnLeft();
      }
    }

    delay(50);
  }

  stopMotors();
}

// قراءة المسافة
float readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    return 999;
  }

  return duration * 0.0343 / 2.0;
}

// عند اكتشاف عائق
void avoidObstacle() {
  stopMotors();

  // مسح المنطقة بالسيرفو
  scanServo.write(135);
  delay(600);

  scanServo.write(45);
  delay(600);

  scanServo.write(90);
  delay(400);

  // رجوع للخلف
  moveBackward();
  delay(1000);

  // تغيير الاتجاه لليمين
  turnRight();
  delay(1000);

  stopMotors();
}

// حركة للأمام
void moveForward() {
  motorForward(motor1A, motor1B);
  motorForward(motor2A, motor2B);
  motorForward(motor3A, motor3B);
  motorForward(motor4A, motor4B);
}

// حركة للخلف
void moveBackward() {
  motorBackward(motor1A, motor1B);
  motorBackward(motor2A, motor2B);
  motorBackward(motor3A, motor3B);
  motorBackward(motor4A, motor4B);
}

// انعطاف يمين
void turnRight() {
  motorForward(motor1A, motor1B);
  motorForward(motor2A, motor2B);

  motorBackward(motor3A, motor3B);
  motorBackward(motor4A, motor4B);
}

// انعطاف يسار
void turnLeft() {
  motorBackward(motor1A, motor1B);
  motorBackward(motor2A, motor2B);

  motorForward(motor3A, motor3B);
  motorForward(motor4A, motor4B);
}

// تشغيل محرك للأمام
void motorForward(int pinA, int pinB) {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
}

// تشغيل محرك للخلف
void motorBackward(int pinA, int pinB) {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
}

// إيقاف جميع المحركات
void stopMotors() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);

  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);

  digitalWrite(motor3A, LOW);
  digitalWrite(motor3B, LOW);

  digitalWrite(motor4A, LOW);
  digitalWrite(motor4B, LOW);
}