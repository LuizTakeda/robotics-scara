enum state_t {
  STATE_NONE = 0,
  STATE_INITIALIZATION,
  STATE_SEARCHING,          
  STATE_GO_TO_TARGET,     
  STATE_OBJECT_EVALUATION,
  STATE_GRABBING_OBJECT,   
  STATE_DELIVERING_OBJECT  
}; 

typedef void (*setup_func_t)(void);
typedef state_t (*logic_func_t)(void);

static state_t s_current_state = STATE_INITIALIZATION;
static bool s_setup_executed = false;

void state_initialization_setup();    state_t state_initialization_logic();
void state_searching_setup();         state_t state_searching_logic();
void state_go_to_target_setup();      state_t state_go_to_target_logic();
void state_object_evaluation_setup(); state_t state_object_evaluation_logic();
void state_grabbing_object_setup();   state_t state_grabbing_object_logic();
void state_delivering_object_setup(); state_t state_delivering_object_logic();

static const setup_func_t s_setup_functions[] = {
  NULL, 
  state_initialization_setup,
  state_searching_setup,
  state_go_to_target_setup, 
  state_object_evaluation_setup, 
  state_grabbing_object_setup, 
  state_delivering_object_setup
};

static const logic_func_t s_logic_functions[] = {
  NULL, 
  state_initialization_logic,
  state_searching_logic,
  state_go_to_target_logic, 
  state_object_evaluation_logic, 
  state_grabbing_object_logic, 
  state_delivering_object_logic
};

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (s_current_state <= STATE_NONE || s_current_state > STATE_DELIVERING_OBJECT) {
    return; 
  }

  // --- EXECUÇÃO DO SETUP DO ESTADO ATUAL ---
  if (!s_setup_executed) {
    if (s_setup_functions[s_current_state] != NULL) {
      s_setup_functions[s_current_state](); 
    }
    s_setup_executed = true;
  }

  // --- EXECUÇÃO DA LÓGICA DO ESTADO ATUAL ---
  state_t next_state = STATE_NONE;
  if (s_logic_functions[s_current_state] != NULL) {
    next_state = s_logic_functions[s_current_state](); 
  }

  // --- GERENCIAMENTO DE TRANSIÇÃO ---
  if (next_state != STATE_NONE) {
    s_current_state = next_state;
    s_setup_executed = false;
  }
}
