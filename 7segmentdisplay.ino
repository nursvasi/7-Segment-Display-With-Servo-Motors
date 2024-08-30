#include <Servo.h>

Servo myservo[7];

int segmentOn[7] = {80, 90, 80, 90, 100, 90, 100};
int segmentOff[7] = {0, 0, 180, 180, 0, 180, 0};
int digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,1,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

void setup() {
  for (int i = 0; i <= 6; i++) {
    myservo[i].attach(2 + i);
  }
  for (int i = 0; i <= 6; i++) {
    myservo[i].write(segmentOn[i]);
  }
  delay(5000);
}

void displayDigit(int digit) {
  for (int i = 0; i <= 6; i++) {
    if (digits[digit][i] == 1) {
      myservo[i].write(segmentOn[i]);
    } else {
      myservo[i].write(segmentOff[i]);
    }
  }
}

void turnOffAllSegments() {
  for (int i = 0; i <= 6; i++) {
    myservo[i].write(segmentOff[i]);
  }
}

void loop() {
  static int tens = 9; // Onlar basamağı
  for (int units = 9; units >= 0; units--) { // Birler basamağı
    displayDigit(units);
    delay(14500); // 10 saniye bekleme

    turnOffAllSegments();
    delay(500); // Segmentlerin kapandığını göstermek için bekleme

    if (units == 0 && tens > 0) {
      tens--; // Onlar basamağını bir eksilt
      units = 10; // Birler basamağını tekrar 9'a ayarla
      displayTensDigit(tens);
    }
  }
}

void displayTensDigit(int tensDigit) {
  // Onlar basamağını ikinci Arduino'ya göndermek için kullanılacak fonksiyon
  // Bu fonksiyon, ikinci Arduino ile iletişim kurmak için gerekli kodu içermelidir
}