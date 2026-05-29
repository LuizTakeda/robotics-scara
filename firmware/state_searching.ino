void state_searching_setup() { 
    Serial.println("[STATE:SEARCHING]: Start"); 
}

state_t state_searching_logic() { 
  auto cmd = com_interface_get();

  if(cmd.id == COM_INTERFACE_ID_GO_TO){

    state_go_to_target_clear_context();
    state_go_to_target_set_position(cmd.payload.go_to.x, cmd.payload.go_to.y);
    state_go_to_target_set_grab(cmd.payload.go_to.grab);

    return STATE_GO_TO_TARGET;
  }

  return STATE_NONE; 
} 