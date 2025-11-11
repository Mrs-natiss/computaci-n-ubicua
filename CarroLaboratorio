// --- Control de carro con Motor Shield L298P ---
// Motor A conectado a M1 (lado izquierdo)
// Motor B conectado a M2 (lado derecho)

// Pines Motor A
#define IN1 12   // Pin digital 12 controla la dirección del Motor A (izquierdo)
#define IN2 13   // Pin digital 13 controla la dirección opuesta del Motor A
#define ENA 10   // Pin PWM 10 controla la velocidad del Motor A

// Pines Motor B
#define IN3 9    // Pin digital 9 controla la dirección del Motor B (derecho)
#define IN4 8    // Pin digital 8 controla la dirección opuesta del Motor B
#define ENB 11   // Pin PWM 11 controla la velocidad del Motor B

// Pines receptor KRF100
#define D0 2    // Botón A del control → Adelante
#define D1 3    // Botón B del control → Izquierda
#define D2 4    // Botón C del control → Atrás
#define D3 5    // Botón D del control → Derecha

// * AJUSTE DE VELOCIDADES *
// Estas constantes definen la velocidad de movimiento del carro.
// El valor máximo permitido para analogWrite() es 255.
const int VELOCIDAD_RECTA = 120;  // Velocidad para avanzar o retroceder.
const int VELOCIDAD_GIRO = 100;   // Velocidad usada para girar (más lenta para tener control).

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial para monitorear mensajes en la PC.

  // Configurar pines del motor como salidas (para enviar señales desde el Arduino)
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Configurar pines del receptor como entradas (para recibir señales del control remoto)
  pinMode(D0, INPUT);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
}

void loop() {
  // --- Lógica principal del control remoto ---
  // Se evalúa continuamente el estado de cada botón del receptor KRF100.
  
  if (digitalRead(D0) == HIGH) { // Si el botón A está presionado...
    Adelante(VELOCIDAD_RECTA, VELOCIDAD_RECTA); // Avanza hacia adelante.
    
  }
  else if (digitalRead(D1) == HIGH) { // Si el botón B está presionado...
    Izquierda(VELOCIDAD_GIRO, VELOCIDAD_GIRO); // Realiza giro tipo tanque hacia la izquierda.
    
  }
  else if (digitalRead(D2) == HIGH) { // Si el botón C está presionado...
    Atras(VELOCIDAD_RECTA, VELOCIDAD_RECTA); // Retrocede.
   
  }
  else if (digitalRead(D3) == HIGH) { // Si el botón D está presionado...
    Derecha(VELOCIDAD_GIRO, VELOCIDAD_GIRO); // Realiza giro tipo tanque hacia la derecha.
  
  }
  else {
    Parar(); // Si no se presiona ningún botón, se detienen los motores.
  }
}

// --- FUNCIONES DE MOVIMIENTO (MODIFICADAS) ---
// Estas funciones controlan directamente la dirección y velocidad de los motores.

void Adelante(int velIzq, int velDer) {
  // Ambos motores giran hacia adelante.
  digitalWrite(IN1, HIGH);  // Motor A: activa dirección hacia adelante.
  digitalWrite(IN2, LOW);   // Asegura que no esté en sentido contrario.
  analogWrite(ENA, velIzq); // Aplica velocidad al motor A.

  digitalWrite(IN3, HIGH);  // Motor B: activa dirección hacia adelante.
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velDer); // Aplica velocidad al motor B.
}

void Atras(int velIzq, int velDer) {
  // Ambos motores giran hacia atrás.
  digitalWrite(IN1, LOW);   // Motor A: invierte la dirección.
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, velIzq); // Aplica velocidad al motor A.

  digitalWrite(IN3, LOW);   // Motor B: invierte la dirección.
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, velDer); // Aplica velocidad al motor B.
}

void Izquierda(int velIzq, int velDer) {
  // Movimiento tipo tanque: solo se mueve el motor derecho.
  // El motor izquierdo se detiene, haciendo que el carro gire sobre su eje hacia la izquierda.
  digitalWrite(IN1, LOW);  // Motor A apagado.
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);     // Sin velocidad.

  digitalWrite(IN3, HIGH); // Motor B hacia adelante.
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velDer); // Aplica velocidad al motor derecho.
}

void Derecha(int velIzq, int velDer) {
  // Movimiento tipo tanque: solo se mueve el motor izquierdo.
  // El motor derecho se detiene, haciendo que el carro gire sobre su eje hacia la derecha.
  digitalWrite(IN1, HIGH); // Motor A hacia adelante.
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velIzq); // Aplica velocidad al motor izquierdo.

  digitalWrite(IN4, LOW);  // Motor B apagado.
  digitalWrite(IN3, LOW);
  analogWrite(ENB, 0);     // Sin velocidad.
}

void Parar() {
  // Detiene ambos motores apagando las señales y poniendo velocidad 0.
  digitalWrite(IN1, LOW); // Apaga dirección del motor A.
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); // Apaga dirección del motor B.
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);    // Velocidad 0 → motor A detenido.
  analogWrite(ENB, 0);    // Velocidad 0 → motor B detenido.
}
