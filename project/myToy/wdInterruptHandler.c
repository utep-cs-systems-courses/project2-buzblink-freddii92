#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){      // 250 interrupts/sec
  static char blink_count = 0;
  static char dimmer_count = 0;
  
  if (++blink_count == 80) {
    switch_interrupt_handler();
    blink_count = 0;
  }
  if (++dimmer_count == 4) {
    switch_interrupt_handler_SW2();
    dimmer_count = 0;
  }
}
