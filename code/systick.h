#ifndef _SYSTICK_LIB
	#define _SYSTICK_LIB

	#include "config.h"

	#define SYSTICK_CALIBRATION		(F_CPU/8/SYSTICK_F-1)
	#define SYSTICK_1s				(SYSTICK_F)

	void systick_init(void);
	int8_t systick_blink_set(uint8_t led, uint8_t blinks, uint16_t period);
	int8_t systick_blink_stop(uint8_t led);

	#define HARDWARE_BUTTON_HOLD_THRESHOLD	100	//how many ticks of systick timer must be button preseed to change to HOLD state

	enum btn
	{
		RELEASED,
		PRESSED,
		HELD
	}button_state;

	void (*volatile button_pressed_callback)(void);
	void (*volatile button_held_callback)(void);
	void (*volatile button_released_callback)(void);


#endif