static float s_go_to_target_x = 0, s_go_to_target_y = 0;
static bool s_go_to_target_grab = false;

void state_go_to_target_setup() {
  Serial.println("[STATE:GO_TO_TARGET]: Start"); 
  
  Serial.println("[STATE:GO_TO_TARGET]: =START=CONTEXT===========");
  Serial.printf ("[STATE:GO_TO_TARGET]: Target X: %.2f\n", s_go_to_target_x);
  Serial.printf ("[STATE:GO_TO_TARGET]: Target Y: %.2f\n", s_go_to_target_y);
  Serial.printf ("[STATE:GO_TO_TARGET]: Grab    : %s\n", s_go_to_target_grab ? "true" : "false");
  Serial.println("[STATE:GO_TO_TARGET]: =END======================");
}

state_t state_go_to_target_logic() { 
  servos_set_angles(s_go_to_target_x, s_go_to_target_y);

  if(!s_go_to_target_grab){
    delay(5000);
    return STATE_SEARCHING; 
  }

  return STATE_NONE;
}

void state_go_to_target_clear_context(){
  s_go_to_target_x = 0;
  s_go_to_target_y = 0;
  s_go_to_target_grab = false;
}

void state_go_to_target_set_position(float x, float y){
  s_go_to_target_x = x;
  s_go_to_target_y = y;
}

void state_go_to_target_set_grab(bool grab){
  s_go_to_target_grab = grab;
}