#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

#define E 750
#define G 630
#define LG 1260
#define A 560
#define LA 1130
#define C 950
#define B 500
#define LB 1000
#define F 710
#define D 840


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

void idle_state()
{
  both_off();
  buzzer_set_period(0);
}

void twinkle_advance()               // alternate between toggling red and green LEDs
{
  static char changed = 0;

  led_changed = 1;

  switch (changed) {
  case 0: buzzer_set_period(C); red_led_on();    changed++; break;
  case 1: buzzer_set_period(0); both_off();      changed++; break;
  case 2: buzzer_set_period(C); red_led_on();    changed++; break;
  case 3: buzzer_set_period(0); both_off();      changed++; break;
  case 4: buzzer_set_period(G); green_led_on();  changed++; break;
  case 5: buzzer_set_period(0); both_off();      changed++; break;
  case 6: buzzer_set_period(G); green_led_on();  changed++; break;
  case 7: buzzer_set_period(0); both_off();      changed++; break;
  case 8: buzzer_set_period(A); red_led_on();    changed++; break;
  case 9: buzzer_set_period(0); both_off();      changed++; break;
  case 10: buzzer_set_period(A); green_led_on(); changed++; break;
  case 11: buzzer_set_period(0); both_off();     changed++; break;
  case 12: buzzer_set_period(G); both_on();      changed++; break;
  case 13: changed++; break;
  case 14: buzzer_set_period(0); both_off();     changed++; break;
  case 15: buzzer_set_period(F); red_led_on();   changed++; break;
  case 16: buzzer_set_period(0); both_off();     changed++; break;
  case 17: buzzer_set_period(F); red_led_on();   changed++; break;
  case 18: buzzer_set_period(0); both_off();     changed++; break;
  case 19: buzzer_set_period(E); green_led_on(); changed++; break;
  case 20: buzzer_set_period(0); both_off();     changed++; break;
  case 21: buzzer_set_period(E); green_led_on(); changed++; break;
  case 22: buzzer_set_period(0); both_off();     changed++; break;
  case 23: buzzer_set_period(D); red_led_on();   changed++; break;
  case 24: buzzer_set_period(0); both_off();     changed++; break;
  case 25: buzzer_set_period(D); green_led_on(); changed++; break;
  case 26: buzzer_set_period(0); both_off();     changed++; break;
  case 27: buzzer_set_period(C); both_on();      changed++; break;
  case 28: changed++; break;
  case 29: buzzer_set_period(0); both_off();     changed = 0; break;
  }
  
  led_update();
}

void dimmer_advance()
{
  static char changed = 0;
  
  led_changed = 1;
  
  switch(changed) {
  case 0: red_led_on(); changed++; break;
  case 1: green_led_on(); changed = 0; break;
  }
  
  led_update();
}

void happy_birthday()
{
  static char changed = 0;

  led_changed = 1;

  switch (changed) {
  case 0: buzzer_set_period(G); red_led_on();    changed++; break;
  case 1: buzzer_set_period(0); both_off();      changed++; break;
  case 2: buzzer_set_period(G); red_led_on();    changed++; break;
  case 3: buzzer_set_period(A); green_led_on();  changed++; break;
  case 4: buzzer_set_period(0); both_off();      changed++; break;
  case 5: buzzer_set_period(G); green_led_on();  changed++; break;
  case 6: buzzer_set_period(0); both_off();      changed++; break;
  case 7: buzzer_set_period(C); both_on();       changed++; break;
  case 8: buzzer_set_period(0); both_off();      changed++; break;
  case 9: buzzer_set_period(B); both_on();      changed++; break;
  case 10: changed++; break;
  case 11: buzzer_set_period(0); both_off();     changed++; break;
  case 12: buzzer_set_period(G); red_led_on();   changed++; break;
  case 13: buzzer_set_period(0); both_off();     changed++; break;
  case 14: buzzer_set_period(G); red_led_on();   changed++; break;
  case 15: buzzer_set_period(A); green_led_on(); changed++; break;
  case 16: buzzer_set_period(0); both_off();     changed++; break;
  case 17: buzzer_set_period(G); green_led_on(); changed++; break;
  case 18: buzzer_set_period(0); both_off();     changed++; break;
  case 19: buzzer_set_period(D); both_on();      changed++; break;
  case 20: buzzer_set_period(0); both_off();     changed++; break;
  case 21: buzzer_set_period(C); both_on();      changed++; break;
  case 22: changed++; break;
  case 23: buzzer_set_period(0); both_off();     changed++; break;
  case 24: buzzer_set_period(G); red_led_on();   changed++; break;
  case 25: buzzer_set_period(0); both_off();     changed++; break;
  case 26: buzzer_set_period(G); red_led_on();   changed++; break;
  case 27: buzzer_set_period(G); green_led_on(); changed++; break;
  case 28: buzzer_set_period(0); both_off();     changed++; break;
  case 29: buzzer_set_period(E); green_led_on(); changed++; break;
  case 30: buzzer_set_period(0); both_off();     changed++; break;
  case 31: buzzer_set_period(C); both_on();      changed++; break;
  case 32: buzzer_set_period(0); both_off();     changed++; break;
  case 33: buzzer_set_period(B); both_on();      changed++; break;
  case 34: buzzer_set_period(0); both_off();     changed++; break;
  case 35: buzzer_set_period(A); both_on();      changed++; break;
  case 36: changed++; break;
  case 37: buzzer_set_period(0); both_off();     changed++; break;
  case 38: buzzer_set_period(F); red_led_on();   changed++; break;
  case 39: buzzer_set_period(0); both_off();     changed++; break;
  case 40: buzzer_set_period(F); red_led_on();   changed++; break;
  case 41: buzzer_set_period(E); green_led_on(); changed++; break;
  case 42: buzzer_set_period(0); both_off();     changed++; break;
  case 43: buzzer_set_period(C); green_led_on(); changed++; break;
  case 44: buzzer_set_period(0); both_off();     changed++; break;
  case 45: buzzer_set_period(D); both_on();      changed++; break;
  case 46: buzzer_set_period(0); both_off();     changed++; break;
  case 47: buzzer_set_period(C); both_on();      changed++; break;
  case 48: changed++; break;
  case 49: buzzer_set_period(0); both_off;       changed = 0; break;
  }

  led_update();
}
