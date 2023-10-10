// Define los pines de los sensores CNY70
const int sensorPisoD = 9;
const int sensorPisoI = 10;
#define UMBRAL_COLOR 700

void setup() {
  // Inicializa la comunicación serial
  Serial.begin(9600);
  pinMode(sensorPisoD, INPUT);
  pinMode(sensorPisoI, INPUT);
}

void loop() {
  // Lee el valor analógico del primer sensor
  int lecturaPisoD = analogRead(sensorPisoD);

  // Lee el valor analógico del segundo sensor
  int lecturaPisoI = analogRead(sensorPisoI);

  // Imprime los valores de ambos sensores
  Serial.print("Valor del sensor 1: ");
  Serial.print(lecturaPisoD);
  Serial.print(", Valor del sensor 2: ");
  Serial.println(lecturaPisoI);

  if(lecturaPisoD < UMBRAL_COLOR) {
    Serial.println("Derecha: Blanco");
  }
  else {
    Serial.println("Derecha: Negro");
  }

  if(lecturaPisoI < 200) {
    Serial.println("Izquierda: Blanco");
  }
  else {
    Serial.println("Izquierda: Negro");
  }
  // Espera un breve período antes de la siguiente lectura
  delay(1000);
}
