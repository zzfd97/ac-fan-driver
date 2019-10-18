/*
 * config.h
 *
 * Created: 26/07/2019 00:18:18
 */ 

#ifndef CONFIG_H_
#define CONFIG_H_

/* PIN DEFINITIONS */
//#define ON_EVALBOARD 1
#ifdef ON_EVALBOARD
	#define LED_PIN IOPORT_CREATE_PIN(PORTB, 5) // evalboard LED
#else
	#define LED_PIN IOPORT_CREATE_PIN(PORTD, 3)
#endif

#define ZERO_CROSSING_PIN IOPORT_CREATE_PIN(PORTD, 2) // source for INT0 interrupt
#define FAN1_DRIVE_PIN			IOPORT_CREATE_PIN(PORTD, 5) // signal for gate of triac driving fan1
#define FAN2_DRIVE_PIN			IOPORT_CREATE_PIN(PORTD, 6) // signal for gate of triac driving fan2
#define FAN3_DRIVE_PIN			IOPORT_CREATE_PIN(PORTD, 7) // signal for gate of triac driving fan3
#define RS_DRIVER_ENABLE_PIN	IOPORT_CREATE_PIN(PORTB, 0) // driver enable control pin (high is driver enable)

/* WORKING PARAMETERS */
#define FAN_NUMBER 3
#define HALF_SINE_PERIOD_US 10000
#define GATE_DRIVING_TIMER_RESOLUTION_US 100
#define ZERO_CROSSING_OFFSET_US 260 // for now it is measured value
#define GATE_PULSE_TIME_US 100
#define MIN_FAN_VOLTAGE 50 // this is min value for triac gate driver
#define MAX_FAN_VOLTAGE 225 // // this is max value for triac gate driver
#define FAN_FULL_ON_VOLTAGE 255
#define FAN_OFF_VOLTAGE 0
#define MIN_WORKING_TEMPERATURE 0 // exceeding this value results in sending error alert
#define MAX_WORKING_TEMPERATURE 90 // exceeding this value results in sending error alert
#define MAX_GATE_DELAY_US 9500
#define MIN_GATE_DELAY_US 500
#define TARGET_TEMPERATURE 70
#define PID_KP 1
#define PID_TIME_CONST_S 5
#define WORKING_PARAMETERS_UPDATE_PERIOD_US 1000000

/* UART PARAMETERS */
#define UART_BAUD_RATE 9600
#define MYUBRR (F_CPU/16/UART_BAUD_RATE - 1)

//#define MOCK_OUTPUT_VOLTAGE_REGULATION 1 // activates proportional regulation instead of PI
#define SEND_DEBUG_INFO_OVER_RS 1

/* CONSTANTS */
#define PI (3.14)

#endif /* CONFIG_H_ */