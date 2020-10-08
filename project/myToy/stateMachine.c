#include <msp430.h>
#include "stateMachine.h"
#include "led.h"

char toggle_siren()           // toggle red and green LED to simulate siren
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    green_on = 0;
    state = 1;
    break;
  case 1:
    red_on = 0;
    green_on = 1;
    state = 0;
    break;
  }
  return 1;
}

void state_advance()        // alternate between toggling red and green LEDs
{
  toggle_siren();
  led_changed = 1;
  led_update();
}
