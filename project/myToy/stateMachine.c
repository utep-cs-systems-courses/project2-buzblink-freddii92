#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

char toggle_siren()           // toggle red and green LED to simulate siren
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    green_on = 0;
    buzzer_set_period(500);
    state = 1;
    break;
  case 1:
    red_on = 0;
    green_on = 1;
    buzzer_set_period(1000);
    state = 0;
    break;
  }
  return 1;
}

char toggle_red()           // toggle red and green LED to simulate siren
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    green_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    green_on = 0;
    state = 0;
    break;
  }
  return 1;
}

char toggle_green()
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

void state_advance()        // alternate between toggling red and green LEDs
{
  char changed = 0;

  static enum {R = 0, G = 1} color = G;
  
  changed = toggle_red();

  led_changed = changed;
  led_update();
  
  if (switch_state_changed) {
    toggle_siren();
    led_changed = 1;
    led_update();
  }
}
