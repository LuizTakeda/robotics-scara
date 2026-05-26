void state_initialization_setup() { 
  Serial.println("[STATE:INITIALIZATION]: Start"); 
}

state_t state_initialization_logic() { 
  return STATE_SEARCHING; 
}