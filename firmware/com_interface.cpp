#include <Arduino.h>
#include "com_interface.h"

//**************************************************
// Globals
//**************************************************

static com_interface_get_t s_current_command = { COM_INTERFACE_ID_NONE };

//**************************************************
// Function Prototypes
//**************************************************

static bool check_go_to_cmd(const String& input_string);

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
  s_current_command.id = COM_INTERFACE_ID_NONE;

  if (Serial.available() > 0) {
    String input_string = Serial.readStringUntil('\n');
    input_string.trim();

    if (check_go_to_cmd(input_string)) {
      Serial.println("[COM_INTERFACE]: Received go to command");
      return;
    }
  }
}

com_interface_get_t com_interface_get() {
  return s_current_command;
}

//**************************************************
// Private Functions
//**************************************************

static bool check_go_to_cmd(const String& input_string) {
  int cmd_id = 0;
  float x = 0.0f;
  float y = 0.0f;
  int grab_int = 0;

  int parsed_fields = sscanf(input_string.c_str(), "%d,%f,%f,%d", &cmd_id, &x, &y, &grab_int);

  if (cmd_id != COM_INTERFACE_ID_GO_TO || parsed_fields != 4) {
    return false; 
  }

  s_current_command.id = (com_interface_id_t)cmd_id;
  s_current_command.payload.go_to.x = x;
  s_current_command.payload.go_to.y = y;
  s_current_command.payload.go_to.grab = (bool)grab_int;

  return true;
}