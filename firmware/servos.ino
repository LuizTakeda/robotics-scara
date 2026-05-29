#define SERVO_1_MIN 66
#define SERVO_1_MAX 494
#define SERVO_1_MINUS_90 95
#define SERVO_1_0 285
#define SERVO_1_PLUS_90 465

#define SERVO_2_MIN 66
#define SERVO_2_MAX 496
#define SERVO_2_MINUS_90 100
#define SERVO_2_0 281
#define SERVO_2_PLUS_90 460

#define SERVO_3_MIN 66
#define SERVO_3_MAX 495

#define SERVO_4_MIN 66
#define SERVO_4_MAX 494

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//**************************************************
// Defines e Configurações
//**************************************************
#define SERVOMIN  150 
#define SERVOMAX  600 

// Instancia o PCA9685 passando o endereço (0x40) e o ponteiro para o segundo I2C (&Wire1)
Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver(0x40, Wire1);

//**************************************************
// Funções Públicas
//**************************************************

void servos_setup(){
  Serial.begin(115200);
  Serial.println("Iniciando teste do PCA9685 no segundo I2C...");

  // 1. Inicializa o SEGUNDO barramento (Wire1) nos pinos da D1 R32 (SDA=15, SCL=14)
  Wire1.begin(15, 14);

  // 2. Inicializa o PCA9685 (ele já sabe que deve usar o Wire1 por causa do construtor acima)
  pca.begin();
  
  // Define a frequência de atualização do PWM para 50Hz
  pca.setOscillatorFrequency(27000000);
  pca.setPWMFreq(50); 

  delay(10);

  servos_set_angles(0,0);
}

void servos_logic(){
  // Sua lógica de controle de tempo ou automação dos servos aqui
}

void servos_set_angles(float angle_1, float angle_2){   
  // Limita os ângulos
  angle_1 = constrain(angle_1, -90.0, 90.0);
  angle_2 = constrain(angle_2, -90.0, 90.0);

  int pulse_1;
  int pulse_2;

  // =========================
  // SERVO 1
  // =========================
  if (angle_1 >= 0) {
    pulse_1 = map(
      angle_1 * 100,
      0, 9000,
      SERVO_1_0,
      SERVO_1_PLUS_90
    );
  } else {
    pulse_1 = map(
      angle_1 * 100,
      -9000, 0,
      SERVO_1_MINUS_90,
      SERVO_1_0
    );
  }

  // Segurança
  pulse_1 = constrain(pulse_1, SERVO_1_MIN, SERVO_1_MAX);

  // =========================
  // SERVO 2
  // =========================
  if (angle_2 >= 0) {
    pulse_2 = map(
      angle_2 * 100,
      0, 9000,
      SERVO_2_0,
      SERVO_2_PLUS_90
    );
  } else {
    pulse_2 = map(
      angle_2 * 100,
      -9000, 0,
      SERVO_2_MINUS_90,
      SERVO_2_0
    );
  }

  // Segurança
  pulse_2 = constrain(pulse_2, SERVO_2_MIN, SERVO_2_MAX);

  // Envia para o PCA9685
  pca.setPWM(12, 0, pulse_1);
  pca.setPWM(13, 0, pulse_2);
}