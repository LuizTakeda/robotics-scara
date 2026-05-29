#include <Arduino.h>
#include "com_interface.h"

//**************************************************
// Globals
//**************************************************

static com_interface_get_t s_current_command = { COM_INTERFACE_ID_NONE };

//**************************************************
// Public Functions
//**************************************************

void com_interface_setup() {
  s_current_command.id = COM_INTERFACE_ID_NONE; 

  Serial.println("[COM_INTERFACE]: Success to initialize");
  
  Serial.println("[COM_INTERFACE]: =START=COMMANDS=============");
  Serial.printf ("[COM_INTERFACE]:  Go To: %d(command_id),x(float),y(float),grab(bool)\n", COM_INTERFACE_ID_GO_TO);
  Serial.println("[COM_INTERFACE]: =END========================");
}

void com_interface_logic() {
}

com_interface_get_t com_interface_get() {
  return s_current_command;
}