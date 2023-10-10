// Definir pines para el sensor ultrasónico
const int trigPin = 3;
const int echoPin = 4;

void setup() {
  // Inicializar comunicación serial
  Serial.begin(9600);
  
  // Configurar los pines como entrada o salida
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Enviar un pulso ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Medir la duración del eco
  long duration = pulseIn(echoPin, HIGH);

  // Calcular la distancia en centímetros
  int distancia = duration / 58;

  // Imprimir la distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Esperar un breve período antes de la siguiente medición
  delay(1000);
}
