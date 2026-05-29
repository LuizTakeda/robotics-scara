#include <Wire.h>
#include <VL53L0X.h>
#include <Adafruit_PWMServoDriver.h>

enum state_t {
  STATE_NONE = 0,
  STATE_INITIALIZATION,
  STATE_SEARCHING,          
  STATE_GO_TO_TARGET,     
  STATE_OBJECT_EVALUATION,
  STATE_GRABBING_OBJECT,   
  STATE_DELIVERING_OBJECT  
}; 

// typedef void (*setup_func_t)(void);
// typedef state_t (*logic_func_t)(void);

// static state_t s_current_state = STATE_INITIALIZATION;
// static bool s_setup_executed = false;

// void state_initialization_setup();    state_t state_initialization_logic();
// void state_searching_setup();         state_t state_searching_logic();
// void state_go_to_target_setup();      state_t state_go_to_target_logic();
// void state_object_evaluation_setup(); state_t state_object_evaluation_logic();
// void state_grabbing_object_setup();   state_t state_grabbing_object_logic();
// void state_delivering_object_setup(); state_t state_delivering_object_logic();

// static const setup_func_t s_setup_functions[] = {
//   NULL, 
//   state_initialization_setup,
//   state_searching_setup,
//   state_go_to_target_setup, 
//   state_object_evaluation_setup, 
//   state_grabbing_object_setup, 
//   state_delivering_object_setup
// };

// static const logic_func_t s_logic_functions[] = {
//   NULL, 
//   state_initialization_logic,
//   state_searching_logic,
//   state_go_to_target_logic, 
//   state_object_evaluation_logic, 
//   state_grabbing_object_logic, 
//   state_delivering_object_logic
// };

// void setup() {
//   Serial.begin(115200);

//   distance_sensor_setup();

//   servos_setup();
// }

// void loop() {
//   distance_sensor_logic();
  
//   if (s_current_state <= STATE_NONE || s_current_state > STATE_DELIVERING_OBJECT) {
//     return; 
//   }

//   // --- EXECUÇÃO DO SETUP DO ESTADO ATUAL ---
//   if (!s_setup_executed) {
//     if (s_setup_functions[s_current_state] != NULL) {
//       s_setup_functions[s_current_state](); 
//     }
//     s_setup_executed = true;
//   }

//   // --- EXECUÇÃO DA LÓGICA DO ESTADO ATUAL ---
//   state_t next_state = STATE_NONE;
//   if (s_logic_functions[s_current_state] != NULL) {
//     next_state = s_logic_functions[s_current_state](); 
//   }

//   // --- GERENCIAMENTO DE TRANSIÇÃO ---
//   if (next_state != STATE_NONE) {
//     s_current_state = next_state;
//     s_setup_executed = false;
//   }
// }

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

void setup(){
  Serial.begin(115200);
  delay(500); // Dá um tempo para o monitor serial estabilizar
  
  Serial.println("\n==================================================");
  Serial.println("[SERVOS]: Iniciando calibração via Monitor Serial");
  Serial.println("[SERVOS]: Digite no formato: CANAL,VALOR (Ex: 12,300)");
  Serial.println("==================================================\n");

  // 1. Inicializa o SEGUNDO barramento (Wire1) nos pinos da D1 R32 (SDA=15, SCL=14)
  Wire1.begin(15, 14);

  // 2. Inicializa o PCA9685
  pca.begin();
  
  // Define a frequência de atualização do PWM para 50Hz (Frequência padrão de fábrica: 27MHz)
  pca.setOscillatorFrequency(27000000);
  pca.setPWMFreq(50); 

  delay(10);
  
  // Removeu-se o loop de teste antigo para entrar direto na lógica de digitação
}

void loop(){
  // Verifica se há dados disponíveis enviados pelo Monitor Serial
  if (Serial.available() > 0) {
    // Lê a string digitada até o usuário apertar "Enter"
    String input = Serial.readStringUntil('\n');
    input.trim(); // Remove espaços em branco ou quebras de linha extras

    // Procura pela vírgula que separa o canal do valor do pulso
    int commaIndex = input.indexOf(',');
    
    if (commaIndex != -1) {
      // Separa o texto antes e depois da vírgula
      String canalStr = input.substring(0, commaIndex);
      String valorStr = input.substring(commaIndex + 1);

      // Converte os textos para números inteiros
      int canal = canalStr.toInt();
      int valor = valorStr.toInt();

      // Validação de segurança dos parâmetros informados
      if (canal >= 0 && canal <= 15 && valor >= 0 && valor <= 4095) {
        
        Serial.printf("[SERVOS OK]: Enviando para o Canal %d -> Pulso: %d\n", canal, valor);
        
        // Envia o comando físico para o PCA9685
        pca.setPWM(canal, 0, valor);
        
      } else {
        Serial.println("[ERRO]: Valores inválidos! Canal deve ser 0-15 e Valor deve ser 0-4095.");
      }
    } else {
      Serial.println("[ERRO]: Formato incorreto. Use: CANAL,VALOR (exemplo: 12,250)");
    }
  }
}

void servos_set_angles(float angle_1, float angle_2){   
  // Sua função de conversão final entrará aqui após descobrir os limites
}