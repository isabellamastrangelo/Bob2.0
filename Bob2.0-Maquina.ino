/** MOTORES **/
const int motor1Pin1 = A3;
const int motor1Pin2 = A0;
const int motor2Pin1 = A2;
const int motor2Pin2 = A1;

/*** ULTRASONICO ***/
const int triggerPin = 3; // Pin de disparo para todos los sensores
const int echoDerecha = 4;  // Pin de eco del primer sensor
const int echoAdelante = 5;  // Pin de eco del segundo sensor
const int echoIzquierda = 6;  // Pin de eco del tercer sensor

long distanciaDerecha, distanciaAdelante, distanciaIzquierda;
#define UMBRAL_DISTANCIA 25

/*** CNY70 ***/
const int sensorPisoD = 9;
const int sensorPisoI = 10;
#define UMBRAL_COLOR 700

int lecturaPisoD, lecturaPisoI;

/*** MAQUINA DE ESTADOS ***/
int estadoMaquina;
#define BUSQUEDA 0
#define ATRAS_IZQ 1
#define ATRAS_DER 2
#define ATRAS 3
#define ADELANTE 4
#define GIRAR_DERECHA 5
#define GIRAR_IZQUIERDA 6

void setup() {
  // Inicializar comunicación serial
  Serial.begin(9600);

  // Configurar los pines como entrada o salida
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  pinMode(triggerPin, OUTPUT);
  pinMode(echoDerecha, INPUT);
  pinMode(echoAdelante, INPUT);
  pinMode(echoIzquierda, INPUT);

  pinMode(sensorPisoD, INPUT);
  pinMode(sensorPisoI, INPUT);

}

void loop() {
  /**LECTURA PISO**/
  lecturaPisoD = analogRead(sensorPisoD);
  lecturaPisoI = analogRead(sensorPisoI);

  /**LECTURA DISTANCIA**/
  distanciaDerecha = medirDistancia(echoDerecha);
  distanciaAdelante = medirDistancia(echoAdelante);
  distanciaIzquierda = medirDistancia(echoIzquierda);

  switch (estadoMaquina) {
    case BUSQUEDA:
      if (lecturaPisoD < UMBRAL_COLOR) {
        if (lecturaPisoI < 200) {
          Serial.println("Ambos: Blanco");
          estadoMaquina = ATRAS;
        }
        else {
          Serial.println("Derecha: Blanco");
          estadoMaquina = ATRAS_DERECHA;
        }
      }
      else if (lecturaPisoI < 200) {
        Serial.println("Izquierda: Blanco");
        estadoMaquina = ATRAS_IZQUIERDA;
      }
      break;
    case ADELANTE:
      break;
    case ATRAS:
      break;
    case GIRAR_DERECHA:
      break;
    case GIRAR_IZQUIERDA:
      break;
    case ATRAS_DERECHA:
      break;
    case ATRAS_IZQUIERDA:
      break;
  }
  //imprimirSensoresDistancia();
  //imprimirSensoresPiso();


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

void imprimirSensoresDistancia() {
  Serial.print("Distancia Derecha: ");
  Serial.print(distanciaDerecha);
  Serial.print(" cm, Distancia Adelante: ");
  Serial.print(distanciaAdelante);
  Serial.print(" cm, Distancia Izquierda: ");
  Serial.print(distanciaIzquierda);
  Serial.println(" cm");
}

void imprimirSensoresPiso() {
  Serial.print("Valor del sensor 1: ");
  Serial.print(lecturaPisoD);
  Serial.print(", Valor del sensor 2: ");
  Serial.println(lecturaPisoI);
}

/** FUNCIONES MOTORES **/
void avanzar(unsigned int tiempo, unsigned int velocidad) {
  digitalWrite(motor1Pin1, velocidad);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, velocidad);
  digitalWrite(motor2Pin2, LOW);
  delay(tiempo);
}

void retroceder(unsigned int tiempo, unsigned int velocidad) {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, velocidad);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, velocidad);
  delay(tiempo);
}

void detenerse(unsigned int tiempo) {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  delay(tiempo);
}

void girarDerecha(unsigned int tiempo, unsigned int velocidad) {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, velocidad);
  digitalWrite(motor2Pin1, velocidad);
  digitalWrite(motor2Pin2, LOW);
  delay(tiempo);
}

void girarIzquierda(unsigned int tiempo, unsigned int velocidad) {
  digitalWrite(motor1Pin1, velocidad);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, velocidad);
  delay(tiempo);
}
