// Definir pines del puente H (L298N)
const int motor1Pin1 = A3;  // Conectar al pin IN1 del L298N
const int motor1Pin2 = A0;  // Conectar al pin IN2 del L298N
const int motor2Pin1 = A2;  // Conectar al pin IN3 del L298N
const int motor2Pin2 = A1;  // Conectar al pin IN4 del L298N

void setup() {
  // Configurar los pines como salida
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
}

void loop() {
  // Prueba las funciones de movimiento
  avanzar(2000, 130);     // Avanza durante 2 segundos
  detenerse(1000);   // Detiene durante 1 segundo
  retroceder(2000, 250);  // Retrocede durante 2 segundos
  detenerse(1000);   // Detiene durante 1 segundo
  girarIzquierda(2000, 160); // Gira a la izquierda durante 2 segundos
  detenerse(1000);   // Detiene durante 1 segundo
  girarDerecha(2000, 170);   // Gira a la derecha durante 2 segundos
  detenerse(1000);   // Detiene durante 1 segundo
}

// Función para avanzar
void avanzar(unsigned int tiempo, unsigned int velocidad) {
  digitalWrite(motor1Pin1, velocidad);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, velocidad);
  digitalWrite(motor2Pin2, LOW);
  delay(tiempo);
}

// Función para retroceder
void retroceder(unsigned int tiempo, unsigned int velocidad) {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, velocidad);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, velocidad);
  delay(tiempo);
}

// Función para detenerse
void detenerse(unsigned int tiempo) {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  delay(tiempo);
}

// Función para girar a la derecha
void girarDerecha(unsigned int tiempo, unsigned int velocidad) {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, velocidad);
  digitalWrite(motor2Pin1, velocidad);
  digitalWrite(motor2Pin2, LOW);
  delay(tiempo);
}

// Función para girar a la izquierda
void girarIzquierda(unsigned int tiempo, unsigned int velocidad) {
  digitalWrite(motor1Pin1, velocidad);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, velocidad);
  delay(tiempo);
}
