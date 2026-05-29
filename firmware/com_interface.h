#pragma once

enum com_interface_id_t {
  COM_INTERFACE_ID_NONE = 0,
  COM_INTERFACE_ID_GO_TO
};

struct com_interface_go_to_payload_t {
  float x, y;
  bool grab;
};

struct com_interface_get_t {
  com_interface_id_t id; 
  
  union {
    com_interface_go_to_payload_t go_to; 
  } payload;
};

void com_interface_setup();
void com_interface_logic();
com_interface_get_t com_interface_get();