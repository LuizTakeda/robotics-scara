// #include <Wire.h>
// #include <Adafruit_PWMServoDriver.h>

// // Inicializa a biblioteca do PCA9685 usando o endereço padrão 0x40
// Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver(0x40);

// // Ajustes de pulso para Servos de 180 graus (podem variar dependendo da marca do servo)
// #define SERVOMIN  150 // Comprimento mínimo do pulso (fração de 4096) -> perto de 0°
// #define SERVOMAX  600 // Comprimento máximo do pulso (fração de 4096) -> perto de 180°

// // Canal onde o servo está conectado no PCA9685 (0 a 15)
// uint8_t canalServo = 13; 

// void setup() {
//   Serial.begin(115200);
//   Serial.println("Iniciando teste do PCA9685...");

//   // Inicializa o barramento I2C nos pinos corretos da D1 R32
//   Wire.begin(15, 14);

//   pca.begin();
  
//   // Define a frequência de atualização do PWM para 50Hz (padrão para servos)
//   pca.setOscillatorFrequency(27000000);
//   pca.setPWMFreq(50); 

//   delay(10);
// }

// void loop() {
//   Serial.println("Movendo para 0 graus");
//   pca.setPWM(canalServo, 0, SERVOMIN);
//   delay(1000);

//   Serial.println("Movendo para 90 graus");
//   // Calcula o meio termo entre o mínimo e o máximo
//   int pulsoMeio = (SERVOMIN + SERVOMAX) / 2;
//   pca.setPWM(canalServo, 0, pulsoMeio);
//   delay(1000);

//   Serial.println("Movendo para 180 graus");
//   pca.setPWM(canalServo, 0, SERVOMAX);
//   delay(1000);
// }