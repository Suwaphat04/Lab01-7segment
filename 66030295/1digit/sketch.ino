#include <Arduino.h>

// กำหนดขา GPIO ที่เชื่อมต่อกับ 7-segment display
int segA = 18;
int segB = 5;
int segC = 17;
int segD = 16;
int segE = 4;
int segF = 0;
int segG = 2;
//int segDP = 5;  // หากมีจุดทศนิยม ก็ใช้พินนี้

// กำหนด GPIO สำหรับ Common Cathode (COM)
int comPin = 4;

int digit[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  // ตั้งค่า pin สำหรับการควบคุม 7-segment display
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  //pinMode(segDP, OUTPUT);

  // กำหนด pin สำหรับ COM (Ground)
  pinMode(comPin, OUTPUT);
}

void displayDigit(int num) {
  // ปิดการแสดงผลก่อน
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);

  // แสดงผลตัวเลขตาม array digit
  digitalWrite(segA, digit[num][0]);
  digitalWrite(segB, digit[num][1]);
  digitalWrite(segC, digit[num][2]);
  digitalWrite(segD, digit[num][3]);
  digitalWrite(segE, digit[num][4]);
  digitalWrite(segF, digit[num][5]);
  digitalWrite(segG, digit[num][6]);
}

void loop() {
  // ทำการแสดงตัวเลข 0-9 แบบวนซ้ำ
  for (int i = 0; i < 10; i++) {
    displayDigit(i);  // แสดงตัวเลข i
    delay(1000);      // หน่วงเวลา 1 วินาที
  }
}
