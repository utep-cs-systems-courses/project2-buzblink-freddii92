#include <msp430.h>
#include "stateMachine.h"
#include "led.h"

char toggle_red()
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;
}

char toggle_green()
{
  
}

void state_advance()
{
  
}
