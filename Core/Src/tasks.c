/*
 * tasks.c
 *
 *  Created on: Oct 29, 2021
 *      Author: Admin
 */
#include "tasks.h"


void toogle_led1(void){
	  HAL_GPIO_TogglePin(out1_GPIO_Port, out1_Pin);
}
void toogle_led2(void){
	  HAL_GPIO_TogglePin(out2_GPIO_Port, out2_Pin);
}
void toogle_led3(void){
	  HAL_GPIO_TogglePin(out3_GPIO_Port, out3_Pin);
}
void toogle_led4(void){
	  HAL_GPIO_TogglePin(out4_GPIO_Port, out4_Pin);
}
void toogle_led5(void){
   	  HAL_GPIO_TogglePin(out5_GPIO_Port, out5_Pin);

}
