#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){      // 250 interrupts/sec
  static char blink_count = 0;
  static char dimmer_count = 0;
  
  if (++blink_count == 125) {
    state_advance();
    blink_count = 0;
  }
  if (++dimmer_count == 4 && switch_state_changed == 0) {
    dimmer_advance();
    dimmer_count = 0;
  }
}
