#include "main.h"
#include "reading.h"
#include "global.h"

enum ButtonState { BUTTON_RELEASED , BUTTON_PRESSED , BUTTON_PRESSED_MORE_THAN_1_SECOND } ;
# define DURATION_FOR_AUTO_INCREASING_1   50
enum ButtonState buttonState1, buttonState2,buttonState3 = BUTTON_RELEASED ;

static uint8_t counterPress [3];
static uint8_t counterForButtonPress_extra [ 3 ];

void fsm_for_input_processing ( void ) {
	/////////////////////// button 1 //////////////////
	switch ( buttonState1 ){
	case BUTTON_RELEASED :
		if( is_button_pressed (0) ) {
			buttonState1 = BUTTON_PRESSED ;
			counterPress[0]++;
		}
	break ;
	case BUTTON_PRESSED :
		if (!is_button_pressed (0) ) {
			buttonState1 = BUTTON_RELEASED ;
		}
		else {
			if( is_button_pressed_1s (0) ) {
				buttonState1 = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
			}
		}
	break ;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND :
		if (! is_button_pressed (0) ) {
			buttonState1 = BUTTON_RELEASED ;
			counterForButtonPress_extra[0]=0;
		}
		if(counterForButtonPress_extra[0]>=DURATION_FOR_AUTO_INCREASING_1){
			counterPress[0]++;
			counterForButtonPress_extra[0]=0;
		}else{
			counterForButtonPress_extra[0]++;
		}

	break ;
	}
	//////////////////////// button 2 ///////////////////
	switch ( buttonState2 ){
	case BUTTON_RELEASED :
		if( is_button_pressed (1) ) {
			buttonState2 = BUTTON_PRESSED ;
			counterPress[1]++;
		}
	break ;
	case BUTTON_PRESSED :
		if (!is_button_pressed (1) ) {
			buttonState2 = BUTTON_RELEASED ;
		}
		else {
			if( is_button_pressed_1s(1)) {
				buttonState2 = BUTTON_PRESSED_MORE_THAN_1_SECOND ;

			}
		}
	break ;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND :
		if (! is_button_pressed (1) ) {
			{buttonState2 = BUTTON_RELEASED ;}
			counterForButtonPress_extra[1]=0;
		}
		if(counterForButtonPress_extra[1]>=DURATION_FOR_AUTO_INCREASING_1){
					counterPress[1]++;
					counterForButtonPress_extra[1]=0;
				}else{
					counterForButtonPress_extra[1]++;
				}
	break ;
	}
	///////////////////// button 3 //////////////////////
	switch ( buttonState3 ){
	case BUTTON_RELEASED :
		if( is_button_pressed (2) ) {
			buttonState3 = BUTTON_PRESSED ;
			counterPress[2]++;
		}
	break ;
	case BUTTON_PRESSED :
		if (! is_button_pressed (2) ) {
			buttonState3 = BUTTON_RELEASED ;
		}
		else {
			if( is_button_pressed_1s (2) ) {
				buttonState3 = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
			}
		}
	break ;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND :
		if (! is_button_pressed (2) ) {
			buttonState3 = BUTTON_RELEASED ;
			counterForButtonPress_extra[2]=0;
		}
		if(counterForButtonPress_extra[2]>=DURATION_FOR_AUTO_INCREASING_1){
					counterPress[2]++;
					counterForButtonPress_extra[2]=0;
				}else{
					counterForButtonPress_extra[2]++;
				}
	break ;
	}
	switch(mode){
	case MODE0:
		if(counterPress[0]>0){
			mode=MODE1;
			number_for_change_duration=1;
			counterPress[0]--;
		}
		break;
	case MODE1:
		if(counterPress[0]>0){
			mode=MODE2;
			number_for_change_duration=1;
			counterPress[0]--;
		}
		if(counterPress[1]>0){
			number_for_change_duration++;
			if(number_for_change_duration>99)
			{number_for_change_duration=1;}
			counterPress[1]--;
		}
		if(counterPress[2]>0){
			duration_for_red = number_for_change_duration;
			counterPress[2]--;
		}
		break;
	case MODE2:
		if(counterPress[0]>0){
			mode=MODE3;
			number_for_change_duration=1;
			counterPress[0]--;
		}
		if(counterPress[1]>0){
			number_for_change_duration++;
			if(number_for_change_duration>99)
			{number_for_change_duration=1;}
			counterPress[1]--;
		}
		if(counterPress[2]>0){
			duration_for_yellow = number_for_change_duration;
			counterPress[2]--;
		}
		break;
	case MODE3:
		if(counterPress[0]>0){
			mode=MODE0;
			number_for_change_duration=1;
			counter=duration_for_red;
			light_state=RED;
			counterPress[0]--;
		}
		if(counterPress[1]>0){
			number_for_change_duration++;
			if(number_for_change_duration>99)
			{number_for_change_duration=1;}
			counterPress[1]--;
		}
		if(counterPress[2]>0){
			duration_for_green = number_for_change_duration;
			counterPress[2]--;
		}
		break;
	}
}












