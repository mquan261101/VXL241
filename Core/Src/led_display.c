#include "main.h"
#include "led_display.h"
#include "global.h"
int led_buffer[4] ={0,0,0,0};
void update7SEG ( int index ) {
	switch(led_buffer[index]){
		  case 0:
			  HAL_GPIO_WritePin(l7_GPIO_Port, l7_Pin, SET);
			  HAL_GPIO_WritePin(GPIOB, l1_Pin|l2_Pin|l3_Pin|l4_Pin
			                          |l5_Pin|l6_Pin, GPIO_PIN_RESET);
			  break;

		  case 1:
			  HAL_GPIO_WritePin(GPIOB, l2_Pin|l3_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOB, l1_Pin|l4_Pin
			                          |l5_Pin|l6_Pin|l7_Pin, GPIO_PIN_SET);
			  break;
		  case 2:
	  		  HAL_GPIO_WritePin(GPIOB, l1_Pin|l2_Pin|l4_Pin
	  		                          |l5_Pin|l7_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOB, l3_Pin|l6_Pin, GPIO_PIN_SET);
		  		break;
		  case 3:
	  		  HAL_GPIO_WritePin(GPIOB, l1_Pin|l2_Pin|l3_Pin|l4_Pin
	  		                          |l7_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOB, l5_Pin|l6_Pin, GPIO_PIN_SET);
		  		break;
		  case 4:
	  		  HAL_GPIO_WritePin(GPIOB, l2_Pin|l3_Pin
	  		                         |l6_Pin|l7_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOB, l1_Pin|l4_Pin|l5_Pin, GPIO_PIN_SET);
		  		break;
		  case 5:
	  		  HAL_GPIO_WritePin(GPIOB, l1_Pin|l3_Pin|l4_Pin
	  		                          |l7_Pin|l6_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOB, l2_Pin|l5_Pin, GPIO_PIN_SET);
		  		break;
		  case 6:
	  		  HAL_GPIO_WritePin(l2_GPIO_Port, l2_Pin, SET);
	  		  HAL_GPIO_WritePin(GPIOB, l1_Pin|l3_Pin|l4_Pin
	  		                          |l5_Pin|l6_Pin|l7_Pin, GPIO_PIN_RESET);
		  		break;
		  case 7:
	  		  HAL_GPIO_WritePin(GPIOB, l1_Pin|l2_Pin|l3_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOB, l4_Pin|l5_Pin|
	  				  	  	  	  	  l6_Pin|l7_Pin, GPIO_PIN_SET);
		  		break;
		  case 8:
			  HAL_GPIO_WritePin(GPIOB, l1_Pin|l2_Pin|l3_Pin|l4_Pin
	                        |l5_Pin|l6_Pin|l7_Pin, GPIO_PIN_RESET);
		  		break;
		  case 9:
			  HAL_GPIO_WritePin(GPIOB, l1_Pin|l2_Pin|l3_Pin|l4_Pin
			                          |l6_Pin|l7_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(l5_GPIO_Port, l5_Pin, SET);

				  break;
		  }
}


void display_light_mode1(){
	if(mode==MODE0){
	counter--;
	switch(light_state){
	case RED:
		HAL_GPIO_WritePin(re_1_GPIO_Port, re_1_Pin, RESET);
		 HAL_GPIO_WritePin(GPIOA,ye_1_Pin|gr_1_Pin, GPIO_PIN_SET);
		if(counter>3){
		HAL_GPIO_WritePin(gr_2_GPIO_Port, gr_2_Pin, RESET);
		 HAL_GPIO_WritePin(GPIOA,re_2_Pin|ye_2_Pin, GPIO_PIN_SET);
		}
		else{
		HAL_GPIO_WritePin(ye_2_GPIO_Port, ye_2_Pin, RESET);
		 HAL_GPIO_WritePin(GPIOA,re_2_Pin|gr_2_Pin, GPIO_PIN_SET);
		}
		if(counter==0){light_state=GREEN; counter=duration_for_green;}
		break;
	case YELLOW:
		 HAL_GPIO_WritePin(GPIOA,ye_1_Pin|re_2_Pin, GPIO_PIN_RESET);
		 HAL_GPIO_WritePin(GPIOA,re_1_Pin|gr_1_Pin
		                          |ye_2_Pin|gr_2_Pin, GPIO_PIN_SET);
		if(counter==0){light_state=RED; counter=duration_for_red;}
		break;
	case GREEN:
		 HAL_GPIO_WritePin(GPIOA,gr_1_Pin|re_2_Pin, GPIO_PIN_RESET);
		 HAL_GPIO_WritePin(GPIOA,re_1_Pin|ye_1_Pin
				 	 	 	 	 |ye_2_Pin|gr_2_Pin, GPIO_PIN_SET);
		if(counter==0){light_state=YELLOW; counter=duration_for_yellow;}
		break;
	}
	}
}

void display_light_blink(){
	switch (mode){
case MODE0:
		break;
case MODE1:
	  HAL_GPIO_WritePin(GPIOA, ye_1_Pin|gr_1_Pin
	                          |re_2_Pin|ye_2_Pin|gr_2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_TogglePin(re_1_GPIO_Port, re_1_Pin);
	  break;
case MODE2:
	  HAL_GPIO_WritePin(GPIOA, re_1_Pin|gr_1_Pin
	                          |re_2_Pin|ye_2_Pin|gr_2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_TogglePin(ye_1_GPIO_Port, ye_1_Pin);
	  break;
case MODE3:
	  HAL_GPIO_WritePin(GPIOA, re_1_Pin|ye_1_Pin
	                          |re_2_Pin|ye_2_Pin|gr_2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_TogglePin(gr_1_GPIO_Port, gr_1_Pin);
	  break;
	}
}

void update_led_buffer(){
	switch(mode){
	case MODE0:
		switch(light_state){
		case RED:
			led_buffer[0]=counter/10;
			led_buffer[1]=counter%10;
			if(counter>3){
			led_buffer[2]=(counter-4)/10;
			led_buffer[3]=(counter-4)%10;
			}
			else{
			led_buffer[2]=counter/10;
			led_buffer[3]=counter%10;
			}
			break;
		case YELLOW:
			led_buffer[0]=counter/10;
			led_buffer[1]=counter%10;
			led_buffer[2]=counter/10;
			led_buffer[3]=counter%10;
			break;
		case GREEN:
			led_buffer[0]=counter/10;
			led_buffer[1]=counter%10;
			led_buffer[2]=(counter+duration_for_yellow)/10;
			led_buffer[3]=(counter+duration_for_yellow)%10;
			break;

		}
		break;
	case MODE1:
		led_buffer[0]=number_for_change_duration/10;
		led_buffer[1]=number_for_change_duration%10;
		led_buffer[2]=0;
		led_buffer[3]=2;
		break;
	case MODE2:
		led_buffer[0]=number_for_change_duration/10;
		led_buffer[1]=number_for_change_duration%10;
		led_buffer[2]=0;
		led_buffer[3]=3;
		break;
	case MODE3:
		led_buffer[0]=number_for_change_duration/10;
		led_buffer[1]=number_for_change_duration%10;
		led_buffer[2]=0;
		led_buffer[3]=4;
		break;
	}
}
void display_7seg(int index){
	  switch(index){
	  case 0:
		  update7SEG(0);
		 HAL_GPIO_WritePin(en_1_GPIO_Port, en_1_Pin, RESET);
		 HAL_GPIO_WritePin(GPIOA, en_2_Pin|en_3_Pin|en_4_Pin, GPIO_PIN_SET);

		  break;
	  case 1:
		 HAL_GPIO_WritePin(en_2_GPIO_Port, en_2_Pin, RESET);
		 HAL_GPIO_WritePin(GPIOA, en_1_Pin|en_3_Pin|en_4_Pin, GPIO_PIN_SET);
		 update7SEG(1);
		  break;
	  case 2:
		 HAL_GPIO_WritePin(en_3_GPIO_Port, en_3_Pin, RESET);
		 HAL_GPIO_WritePin(GPIOA, en_1_Pin|en_2_Pin|en_4_Pin, GPIO_PIN_SET);
		 update7SEG(2);
		  break;
	  case 3:
		 HAL_GPIO_WritePin(en_4_GPIO_Port, en_4_Pin, RESET);
		 HAL_GPIO_WritePin(GPIOA, en_1_Pin|en_2_Pin|en_3_Pin, GPIO_PIN_SET);
		 update7SEG(3);
		  break;
	  }
}
