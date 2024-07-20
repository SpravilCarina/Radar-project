//include biblioteca
#include <Servo.h>. 
// Definesc pinii Tirg și Echo ai senzorului cu ultrasunete
const int trigPin = 10;
const int echoPin = 11;
// Variabile pentru durata și distanța
long duration;
int distance;
Servo myServo; // Creez un obiect servo pentru controlul servomotorului
void setup() {
  pinMode(trigPin, OUTPUT); // Setez trigPin-ul ca ieșire
  pinMode(echoPin, INPUT); // Setez echoPin ca intrare
  Serial.begin(9600);
  myServo.attach(12); // Definesc pe ce pin este atașat servomotorul
}
void loop() {
  //rotește servomotorul de la 15 la 165 de grade
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();// Apelez o funcție pentru calcularea distanței măsurate de senzorul cu ultrasunete pentru fiecare grad
  
  Serial.print(i); // Trimit gradul curent în portul serial
  Serial.print(","); // Trimit caracterul de adăugare chiar lângă valoarea anterioară necesară mai târziu în Procesare IDE pentru indexare
  Serial.print(distance); // Trimit valoarea distanței în portul serial
  Serial.print("."); // Trimit caracterul de adăugare chiar lângă valoarea anterioară necesară mai târziu în Procesare IDE pentru indexare
  }
  // Repet rândurile anterioare de la 165 la 15 grade
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
// Funcție pentru calcularea distanței măsurate de senzorul cu ultrasunete
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Setez trigPin-ul pe starea HIGH pentru 10 microsecunde
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Citesc echoPin, returnează timpul de călătorie a undei sonore în microsecunde
  distance= duration*0.034/2;
  return distance;
}