/*
 * led_display.h
 *
 *  Created on: Oct 2, 2021
 *      Author: Admin
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

int counter;
extern int led_buffer[] ;

void display_light_mode1();
void display_light_blink();
void update_led_buffer();
void display_7seg(int);


#endif /* INC_LED_DISPLAY_H_ */
