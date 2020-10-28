#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

char red_led_on()                      // turning red LED on and green LED off
{
  red_on = 1;
  green_on = 0;
  led_update();
}

char green_led_on()                    // turning green LED on and red LED off
{
  red_on = 0;
  green_on = 1;
  led_update();
}

char both_on()                         // turning both LEDs on
{
  red_on = 1;
  green_on = 1;
  led_update();
}

char both_off()                        // turning both LEDs off
{
  red_on = 0;
  green_on = 0;
  led_update();
}

void state_advance()               // alternate between toggling red and green LEDs
{
  static char changed = 0;

  led_changed = 1;

  switch (changed) {
  case 0:
    red_led_on();
    changed++;
    break;
  case 1:
    green_led_on();
    changed++;
    break;
  case 2:
    both_on();
    changed++;
    break;
  case 3:
    both_off();
    changed++;
    break;
  case 4:
    both_on();
    changed++;
    break;
  default:
    changed = 0;
  }
  
  led_update();
}

