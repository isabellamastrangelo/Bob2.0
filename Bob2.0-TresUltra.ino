// Definir pines para el sensor ultrasónico
const int triggerPin = 3; // Pin de disparo para todos los sensores
const int echoPin1 = 4;  // Pin de eco del primer sensor
const int echoPin2 = 5;  // Pin de eco del segundo sensor
const int echoPin3 = 6;  // Pin de eco del tercer sensor

void setup() {
  // Inicializar comunicación serial
  Serial.begin(9600);
  
  // Configurar los pines como entrada o salida
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
}

void loop() {
  // Realizar una lectura para el primer sensor
  long distancia1 = medirDistancia(echoPin1);

  // Realizar una lectura para el segundo sensor
  long distancia2 = medirDistancia(echoPin2);

  // Realizar una lectura para el tercer sensor
  long distancia3 = medirDistancia(echoPin3);

  // Imprimir las distancias en el monitor serial
  Serial.print("Distancia 1: ");
  Serial.print(distancia1);
  Serial.print(" cm, Distancia 2: ");
  Serial.print(distancia2);
  Serial.print(" cm, Distancia 3: ");
  Serial.print(distancia3);
  Serial.println(" cm");

  // Esperar un breve período antes de la siguiente medición
  delay(1000);
}

long medirDistancia(int echoPin) {
  // Enviar un pulso ultrasónico
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Medir la duración del eco
  long duration = pulseIn(echoPin, HIGH);

  // Calcular la distancia en centímetros
  long distancia = duration / 58;

  return distancia;
}
