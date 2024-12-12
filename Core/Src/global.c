/*
 * global.c
 *
 *  Created on: Oct 3, 2021
 *      Author: Admin
 */

int duration_for_red=10;
int duration_for_yellow=5;
int duration_for_green=7;
int number_for_change_duration=1;
int counter;
int duration_for_sub_yellow;
enum Mode { MODE0, MODE1 , MODE2 , MODE3 };
enum Mode mode=MODE0 ;
enum Light_State {RED, YELLOW,GREEN};
enum Light_State light_state=RED;
