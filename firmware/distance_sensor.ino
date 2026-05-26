// #include <Wire.h>
// #include <VL53L0X.h>

// VL53L0X sensor;

// void setup() {
//   // Inicializa a comunicação serial para o monitor
//   Serial.begin(115200);

//   if (!sensor.init()) {
//     Serial.println("Falha ao detectar ou inicializar o sensor VL53L0X!");
//     while (1) {} // Trava o código aqui se houver erro
//   }

//   // Define que o sensor fará leituras contínuas em alta velocidade/precisão padrão
//   sensor.startContinuous();
//   Serial.println("Sensor VL53L0X inicializado com sucesso!");
// }

// void loop() {
//   // Leitura da distância em milímetros (mm)
//   uint16_t distancia = sensor.readRangeContinuousMillimeters();

//   // Verifica se houve timeout na leitura
//   if (sensor.timeoutOccurred()) { 
//     Serial.println(" TIMEOUT - Falha na leitura"); 
//   } else {
//     Serial.print("Distancia: ");
//     Serial.print(distancia);
//     Serial.println(" mm");
//   }

//   delay(100); // Aguarda 100ms antes da próxima leitura
// }
//   // Inicializa o barramento I2C nos pinos padrão do ESP32 (SDA=21, SCL=22)
//   Wire.begin(21, 22);

//   // Inicializa o sensor
//   sensor.setTimeout(500);

