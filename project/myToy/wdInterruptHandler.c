#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){      // 250 interrupts/sec
  static char blink_count = 0;
  
  if (++blink_count == speed) {         // getting speed from switches.c. speed varies from switch
    switch_interrupt_handler();
    blink_count = 0;
  }
}
