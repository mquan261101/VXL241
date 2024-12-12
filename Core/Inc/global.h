/*
 * global.h
 *
 *  Created on: Oct 3, 2021
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

extern int duration_for_red;
extern int duration_for_yellow;
extern int duration_for_green;
extern int number_for_change_duration;
extern int counter;
extern int duration_for_sub_yellow;
extern enum Mode { MODE0, MODE1 , MODE2 , MODE3 };
extern enum Mode mode ;
extern enum Light_State {RED, YELLOW, GREEN};
extern enum Light_State light_state;

#endif /* INC_GLOBAL_H_ */
