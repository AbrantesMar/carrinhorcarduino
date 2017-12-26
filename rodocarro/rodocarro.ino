/* Carro Arduino com controle Bluetooth
      Código retirado do link abaixo:
   http://www.instructables.com/id/Arduino-Bluetooth-RC-Car-Android-Controlled/?ALLSTEPS
      Conclusão e adaptações por Usinainfo:
   http://www.usinainfo.com.br/
*/

// Define os pinos de utilização do Driver L298.
const int motorA1  = 4;    // Pin  4 of L293.
const int motorA2  = 5;    // Pin  5 of L293.
const int motorB1  = 6;   // Pin 6 of L293.
const int motorB2  = 7;   // Pin 7 of L293.

const int buzzer = 8;   // Define o Pino 13 como pino do Buzzer.

const int BTState = 2;    // Define o Pino 2 como o pino de comunicação do Bluetooth.

// Variáveis Úteis
int i = 0;
int j = 0;
int state_rec;
int vSpeed = 200;   // Define velocidade padrão 0 < x < 255.
char state;

void setup() {
  // Inicializa as portas como entrada e saída.
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(BTState, INPUT);

  // Inicializa a comunicação serial em 9600 bits.
  Serial.begin(9600);
}

void loop() {
  // Para o carro quando a conexão com Bluetooth é perdida ou desconectada.
  if (digitalRead(BTState) == LOW) {
    state_rec = 'S';
  }

  // Salva os valores da variável 'state'
  if (Serial.available() > 0) {
    state_rec = Serial.read();
    state = state_rec;
    //   Serial.println(vSpeed);
  }

  // Altera a velocidade de acordo com valores especificados.
  if (state == '0') {
    vSpeed = 0;
  }
  else if (state == '4') {
    vSpeed = 100;
  }
  else if (state == '6') {
    vSpeed = 155;
  }
  else if (state == '7') {
    vSpeed = 180;
  }
  else if (state == '8') {
    vSpeed = 200;
  }
  else if (state == '9') {
    vSpeed = 230;
  }
  else if (state == 'q') {
    vSpeed = 255;
  }

  if (state != 'S') {
    Serial.print(state);
  }

  switch(state){
    case 'F':
      front();
      break;
    case 'I':
      frontLeft();
      break;
    case 'G':
      frontRight();
      break;
    case 'B':
      back();
      break;
    case 'H':
      backLeft();
      break;
    case 'J':
      backRight();
      break;
    case 'L':
      left();
      break;
    case 'R':
      right();
      break;
    case 'V':
      if (j == 0) {
        tone(buzzer, 1000, 1000);
        j = 1;
      }
      else if (j == 1) {
        noTone(buzzer);
        j = 0;
      }
      state = 'n';
      break;
      
  }
}

void front(){
  analogWrite(motorB1, vSpeed);
  analogWrite(motorA1, vSpeed);
  analogWrite(motorA2, 0);
  analogWrite(motorB2, 0);
}

void frontLeft(){
  analogWrite(motorA1, vSpeed);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, 100);
  analogWrite(motorB2, 0);
}

void frontRight(){
  analogWrite(motorA1, 100);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, vSpeed);
  analogWrite(motorB2, 0);
}

void back(){
  analogWrite(motorA1, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, vSpeed);
  analogWrite(motorA2, vSpeed);
}

void backLeft(){
  analogWrite(motorA1, 0);
  analogWrite(motorA2, vSpeed);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 100);
}

void backRight(){
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 100);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, vSpeed);
}

void left(){
  analogWrite(motorA1, 0);
  analogWrite(motorA2, vSpeed);
  analogWrite(motorB1, vSpeed);
  analogWrite(motorB2, 0);
}

void right(){
  analogWrite(motorA1, vSpeed);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, vSpeed);
}

void pause(){
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
}



