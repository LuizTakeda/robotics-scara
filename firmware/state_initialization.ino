void state_initialization_setup() { Serial.println("Setup: Inicializando..."); }
state_t state_initialization_logic() { 
  // Se sensores ok, avança:
  return STATE_SEARCHING; 
}