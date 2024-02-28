/* xanela-do-coche-automatizada
Programa para simular o funcionamiento dunha ventanilla dun coche.
O pulsador acciona a ventanilla de subida o ser pulsado,
unha  segunda pulsación fai que se accione a ventanilla de baixada.
O percorrido do  motor dura 7 segundos.

Entradas: Pulsador (dixital)
Saídas: Relé (2x dixital)

Autor: Juan Carlos Breijo Pérez
Data: Febreiro de 2024
*/

#define ventanillaarriba 11
#define ventanillaabajo 12
#define pulsador 7

bool estado = 0;
int contador = 100; // Contador para o número de impulsos ao motor

void setup() {
  pinMode(ventanillaarriba, OUTPUT);
  pinMode(ventanillaabajo, OUTPUT);
  pinMode(pulsador, INPUT);

  Serial.begin(9600);
  int estado;

  Serial.println(estado);
}

void loop() {
  // Lectura do pulsador
  if(digitalRead(pulsador)) {
    estado = !estado; 
    contador = 100;
    while(digitalRead(pulsador)) {
      delay(20);
    }
  }
  // Fin da lectura do pulador

  Serial.print("valor do contador: ");
  Serial.println(contador);

  // Accionamiento dos motores
  if(contador > 0) {
    if(estado == 0) {
      digitalWrite(ventanillaarriba, HIGH);
      digitalWrite(ventanillaabajo, LOW);
      delay(70);
      contador--;
    }
    else {
      digitalWrite(ventanillaarriba, LOW);
      digitalWrite(ventanillaabajo, HIGH);
      delay(70);
      contador--;
    }
  }
  else {             // Se non está o motor accionado, lee botón 10 veces/s
    delay(100);
  }
  // Fin de accionamentos dos motores
  delay(7);
  if (contador ==0) {
    digitalWrite(ventanillaarriba, LOW);
    digitalWrite(ventanillaabajo, LOW);
  }
}
