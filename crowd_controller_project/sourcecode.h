#include <LiquidCrystal.h>
Liquid Crystal lcd(12, 11, 10, 9, 8, 7);
// Define pins for IR sensors and LED
const int IR_LED = 13;
const int IR_SENSOR_1 = 2;
const int IR_SENSOR_2 = 3;
int buzzer=4;
int maximum=5;

// Initialize person count and sensor states
int count = 0;
int sensor_1_state = LOW;
int sensor_2_state = LOW;
void setup() {

 // Initialize serial communication
 Serial.begin(9600);
 lcd.begin(16, 2);
 // Initialize 16x2 display
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("CROWD CONTROLLER");
 lcd.setCursor(0, 1);
 lcd.print("*USING ARDUINO*");
 delay(1000); // wa 

 // Initialize IR sensor and LED pins
 pinMode(IR_LED, OUTPUT);
 pinMode(buzzer, OUTPUT);
 pinMode(IR_SENSOR_1, INPUT);
 pinMode(IR_SENSOR_2, INPUT);
}
void loop() {
 // Turn on IR LED
 digitalWrite(buzzer,LOW);
 // Read IR sensor states
 sensor_1_state = digitalRead(IR_SENSOR_1);
 sensor_2_state = digitalRead(IR_SENSOR_2);
 
 // Check if a person entered or left the room
 if (sensor_1_state == HIGH && sensor_2_state == LOW) {
 count++;
 Serial.println("Person entered the room.");
 Serial.print("Total persons: ");
 Serial.println(count);
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("NO.OF PERSONS: ");
 lcd.print(count);
 delay(1000); // wait for person to leave
 } else if (sensor_1_state == LOW && sensor_2_state == HIGH) {
 count--;
 Serial.println("Person left the room.");
 Serial.print("Total persons: ");
 Serial.println(count);

 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("NO.OF PERSONS:");
 lcd.print(count);
 delay(1000); // wait for person to enter
 }
 
 // Turn off IR LED
 if( maximum<count){
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("NO.OF PERSONS: ");
 lcd.print(count);
 lcd.setCursor(0, 1);
 lcd.print("AREA FULL");
 delay(100); 
 }
 if( 6<count){
 digitalWrite(buzzer,HIGH);
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("NO.OF PERSONS: ");
 lcd.print(count);
 lcd.setCursor(0, 1);
 lcd.print("OVER CROWDED");
 delay(500); 
 }
 }
