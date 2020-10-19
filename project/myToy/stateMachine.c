#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

static int x = 500;

char toggle_siren()           // toggle red and green LED to simulate siren
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    green_on = 0;
    up_state();
  case 1:
    red_on = 1;
    green_on = 0;
    state++;
    break;
  case 2:
    red_on = 0;
    green_on = 1;
    buzzer_set_period(1000);
    state = 0;
  }
  return 1;
}

char toggle_lights()           // toggle red and green LED to simulate siren
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

void up_state()
{
  buzzer_set_period(2000000/x);
}

void state_advance()        // alternate between toggling red and green LEDs
{
  if (switch_state_changed) {
    toggle_siren();
    led_changed = 1;
    led_update();
  }
}

void dimmer_advance()
{
  char changed = 0;
  changed = toggle_lights();
  led_changed = changed;
  led_update();
}
