//**************************************************
// Defines
//**************************************************

#define FILTER_ALPHA 0.3 // Configuração do Filtro EMA
#define NOT_SEEING_DISTANCE 250 
#define READ_RATE_MS 60
#define PRINT_RATE_MS 300
#define PRINT_DISTANCE false

//**************************************************
// Globals
//**************************************************

static VL53L0X s_sensor;

static float s_filtered_distance = NOT_SEEING_DISTANCE; 
static uint16_t s_current_distance = NOT_SEEING_DISTANCE;

//**************************************************
// Public Functions
//**************************************************

void distance_sensor_setup(){
  Wire.begin(21, 22);
  
  s_sensor.setTimeout(200);
  if (!s_sensor.init()) {
    Serial.println("[DISTANCE_SENSOR]: Fail to initialize");
    while (1) {}
  }

  if(!s_sensor.setSignalRateLimit(0.5)){
    Serial.println("[DISTANCE_SENSOR]: Invalid signal rate limit");
  } 
  
  if(!s_sensor.setMeasurementTimingBudget(33000)){
    Serial.println("[DISTANCE_SENSOR]: Invalid meashurement timing budget");
  }

  s_sensor.startContinuous();

  Serial.println("[DISTANCE_SENSOR]: Success to initialize");
}

void distance_sensor_logic(){
  static uint32_t s_read_last_millis = millis();
  static uint32_t s_print_last_millis = millis();

  if (millis() - s_read_last_millis >= READ_RATE_MS) {
    s_read_last_millis = millis();

    uint16_t mm_distance = s_sensor.readRangeContinuousMillimeters();

    if (s_sensor.timeoutOccurred()) { 
      s_filtered_distance = NOT_SEEING_DISTANCE;
      s_current_distance = NOT_SEEING_DISTANCE; 
      Serial.printf("[DISTANCE_SENSOR]: Read timeout\n");
      return; 
    } 

    if (mm_distance == 0 || mm_distance >= NOT_SEEING_DISTANCE) {
      mm_distance = NOT_SEEING_DISTANCE; 
    } 
    
    s_filtered_distance = (FILTER_ALPHA * mm_distance) + ((1.0 - FILTER_ALPHA) * s_filtered_distance);

    s_current_distance = (uint16_t)s_filtered_distance;
  }

  if (PRINT_DISTANCE && millis() - s_print_last_millis >= PRINT_RATE_MS) {
    s_print_last_millis = millis();
    Serial.printf("[DISTANCE_SENSOR]: %dmm\n", s_current_distance);
  }
}

uint16_t distance_sensor_get(){
  return s_current_distance;
}