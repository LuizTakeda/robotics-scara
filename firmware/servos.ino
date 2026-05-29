#define SERVO_1_MIN 66
#define SERVO_1_MAX 494
#define SERVO_1_MINUS_90 95
#define SERVO_1_0 285
#define SERVO_1_PLUS_90 465

//mid 285
// -90 : 95
// +90 : 465

#define SERVO_2_MIN 66
#define SERVO_2_MAX 496
#define SERVO_2_MINUS_90 100
#define SERVO_2_0 281
#define SERVO_2_PLUS_90 460

//mid 281
// -90 : 100
// +90 : 460

#define SERVO_3_MIN 66
#define SERVO_3_MAX 495

#define SERVO_4_MIN 66
#define SERVO_4_MAX 494

// #include <Wire.h>
// #include <Adafruit_PWMServoDriver.h>

// //**************************************************
// // Defines e Configurações
// //**************************************************
// #define SERVOMIN  150 
// #define SERVOMAX  600 

// // Instancia o PCA9685 passando o endereço (0x40) e o ponteiro para o segundo I2C (&Wire1)
// Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver(0x40, Wire1);

// //**************************************************
// // Funções Públicas
// //**************************************************

// void servos_setup(){
//   Serial.begin(115200);
//   Serial.println("Iniciando teste do PCA9685 no segundo I2C...");

//   // 1. Inicializa o SEGUNDO barramento (Wire1) nos pinos da D1 R32 (SDA=15, SCL=14)
//   Wire1.begin(15, 14);

//   // 2. Inicializa o PCA9685 (ele já sabe que deve usar o Wire1 por causa do construtor acima)
//   pca.begin();
  
//   // Define a frequência de atualização do PWM para 50Hz
//   pca.setOscillatorFrequency(25000000);
//   pca.setPWMFreq(50); 

//   delay(10);
  
//   // min
//   // pca.setPWM(12, 0, 70);
//   // pca.setPWM(13, 0, 365);

//   // max
//   // pca.setPWM(12, 0, 535)
//   // pca.setPWM(13, 0, 365);

//   // Center = 0°
//   // pca.setPWM(12, 0, 375);
//   // pca.setPWM(13, 0, 365);
  
//   pca.setPWM(12, 0, 71);
//   delay(3000);

//   pca.setPWM(12, 0, 535); // max
//   delay(3000);


//   //72

//   //530

//   // Up = 90°
//   for(int i = 71; i < 600; i++){
//     Serial.printf("[SERVOS]: %d\n", i);
//     pca.setPWM(12, 0, i);
//     delay(100);
//   }

//   while(1);

//   // pca.setPWM(13, 0, 365);

//   // Min
//   // pca.setPWM(14, 0, 80);
//   // pca.setPWM(15, 0, 80);
// }

// void servos_logic(){
//   // Sua lógica de controle de tempo ou automação dos servos aqui
// }

// void servos_set_angles(float angle_1, float angle_2){   
//   // Exemplo de conversão simples de ângulo para pulso e envio
//   // int pulso1 = map(angle_1, 0, 180, SERVOMIN, SERVOMAX);
//   // pca.setPWM(canal_1, 0, pulso1);
// }