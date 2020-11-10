/*
   TUTORIAL SEVEN SEGMENT PADA ARDUINO
   MENGGUNAKAN CHIP TM1637
   MEMBUAT JAM DIGITAL

   Pinout :
   CLK -> D10
   DIO -> D11

   Tombol 1 -> D9
   Tombol 2 -> D8

   D4 -> Led Merah
   D5 -> Led Hijau
   D6 -> Led Biru
   D7 -> Led Kuning

*/

#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 10
#define DIO 11
#define merah 4
#define hijau 5
#define biru 6
#define kuning 7
#define TOMBOL1 9
#define TOMBOL2 8

//inisiasi TM1637
TM1637Display display(CLK, DIO);

int jam = 10;
int menit = 30;
int detik = 0;
int waktu;

void setup()
{
  display.setBrightness(0x0f);
  pinMode(kuning, OUTPUT);
  pinMode(biru, OUTPUT);
  pinMode(hijau, OUTPUT);
  pinMode(merah, OUTPUT);
  pinMode(TOMBOL1, INPUT);
  pinMode(TOMBOL2, INPUT);
  digitalWrite(TOMBOL1, HIGH); //pull high sebagai default awal
  digitalWrite(TOMBOL2, HIGH); //pull high sebagai default awal

}

void loop()
{
  detik++;
  if (detik == 60) {
    detik = 0;
    menit++;
  }
  if (menit == 60) {
    menit = 0;
    jam++;
  }
  if (jam == 24) {
    jam = 0;
  }

  waktu = (jam * 100) + menit;
  cekLed();

  display.showNumberDecEx(waktu, (0x80 >> 1), true);
  delay(500);
  display.showNumberDec(waktu, true);
  delay(500);
  if (digitalRead(TOMBOL1) == LOW) {
    jam++;
    detik = 0;
  }

  if (digitalRead(TOMBOL2) == LOW) {
    menit++;
    detik = 0;
  }

}

void cekLed(){
  if(detik>=0 && detik<15){
    digitalWrite(kuning,HIGH);
    digitalWrite(biru,LOW);
    digitalWrite(hijau,LOW);
    digitalWrite(merah,LOW);
  }
  if(detik>=15 && detik<30){
    digitalWrite(kuning,HIGH);
    digitalWrite(biru,HIGH);
    digitalWrite(hijau,LOW);
    digitalWrite(merah,LOW);
  }
  if(detik>=30 && detik<45){
    digitalWrite(kuning,HIGH);
    digitalWrite(biru,HIGH);
    digitalWrite(hijau,HIGH);
    digitalWrite(merah,LOW);
  }
  if(detik>=45 && detik<60){
    digitalWrite(kuning,HIGH);
    digitalWrite(biru,HIGH);
    digitalWrite(hijau,HIGH);
    digitalWrite(merah,HIGH);
  }
}
