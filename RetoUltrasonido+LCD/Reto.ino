#include <LiquidCrystal.h>

// Configuración de pines LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Pines del sensor ultrasónico
int TRIG = 10;
int ECO = 9;

// Variables de medición
long DURACION;
float DISTANCIA;

void setup() {
  lcd.begin(16, 2);      // Inicializa LCD de 16x2∏
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  Serial.begin(9600);    // Comunicación serial
}

void loop() {
  // --- Generar pulso de 10 microsegundos ---
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // --- Medir duración del eco ---
  DURACION = pulseIn(ECO, HIGH);

  // --- Calcular distancia en cm ---
  DISTANCIA = DURACION / 58.2;

  // --- Mostrar en LCD ---
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distancia:");
  lcd.setCursor(0, 1);
  lcd.print(DISTANCIA);
  lcd.print(" cm");

  // --- Mostrar también en Serial ---
  Serial.print("Distancia: ");
  Serial.print(DISTANCIA);
  Serial.println(" cm");

  delay(1000); // Esperar 1 segundo antes de la siguiente lectura
}
