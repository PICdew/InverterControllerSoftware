/* 
 * File:   system.h
 * Author: Luke
 *
 * Created on 5. September 2016, 21:17
 */

#ifndef OS_H
#define	OS_H

#include <stdint.h>

/*
 * Configuration bits
 */

// CONFIG1
#pragma config FEXTOSC = HS     // External Oscillator mode selection bits (HS (crystal oscillator) above 4MHz; PFM set to high power)
#pragma config RSTOSC = EXT4X   // Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)
#pragma config CLKOUTEN = OFF   // Clock Out Enable bit (CLKOUT function is disabled; i/o or oscillator function on OSC2)
#pragma config CSWEN = OFF      // Clock Switch Enable bit (The NOSC and NDIV bits cannot be changed by user software)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (FSCM timer enabled)

// CONFIG2
#pragma config MCLRE = ON       // Master Clear Enable bit (MCLR pin is Master Clear function)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config LPBOREN = OFF    // Low-Power BOR enable bit (ULPBOR disabled)
#pragma config BOREN = ON       // Brown-out reset enable bits (Brown-out Reset Enabled, SBOREN bit is ignored)
#pragma config BORV = HI        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (VBOR) is set to 2.7V)
#pragma config ZCD = OFF        // Zero-cross detect disable (Zero-cross detect circuit is disabled at POR.)
#pragma config PPS1WAY = OFF    // Peripheral Pin Select one-way control (The PPSLOCK bit can be set and cleared repeatedly by software)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable bit (Stack Overflow or Underflow will cause a reset)

// CONFIG3
#pragma config WDTCPS = WDTCPS_31// WDT Period Select bits (Divider ratio 1:65536; software control of WDTPS)
#pragma config WDTE = OFF       // WDT operating mode (WDT Disabled, SWDTEN is ignored)
#pragma config WDTCWS = WDTCWS_7// WDT Window Select bits (window always open (100%); software control; keyed access not required)
#pragma config WDTCCS = SC      // WDT input clock selector (Software Control)

// CONFIG4
#pragma config WRT = OFF        // UserNVM self-write protection bits (Write protection off)
#pragma config SCANE = available// Scanner Enable bit (Scanner module is available for use)
#pragma config LVP = ON         // Low Voltage Programming Enable bit (Low Voltage programming enabled. MCLR/Vpp pin function is MCLR.)

// CONFIG5
#pragma config CP = OFF         // UserNVM Program memory code protection bit (Program Memory code protection disabled)
#pragma config CPD = OFF        // DataNVM code protection bit (Data EEPROM code protection disabled)

/*
 * General definitions
 */

#define _XTAL_FREQ 8000000

//#define NUMBER_OF_TIMESLOTS 16

//#define  PPSUnLock()    {EECON2 = 0b01010101; EECON2 = 0b10101010; PPSCONbits.IOLOCK = 0;}
//#define  PPSLock() 		{EECON2 = 0b01010101; EECON2 = 0b10101010; PPSCONbits.IOLOCK = 1;}

//#define PPS_FUNCTION_CCP1_OUTPUT 14
//#define PPS_FUNCTION_CCP2_OUTPUT 18

#define PIN_INPUT           1
#define PIN_OUTPUT          0
#define PIN_DIGITAL         1
#define PIN_ANALOG          0

#define RELAY1_TRIS TRISAbits.TRISA1
#define RELAY1_PIN LATAbits.LATA1

#define RELAY2_TRIS TRISAbits.TRISA2
#define RELAY2_PIN LATAbits.LATA2

#define RELAY3_TRIS TRISAbits.TRISA0
#define RELAY3_PIN LATAbits.LATA0

#define EXTERNAL_ENABLE_TRIS TRISAbits.TRISA3
#define EXTERNAL_ENABLE_PIN PORTAbits.RA3

#define EXTERNAL_SPINDLE_TRIS TRISAbits.TRISA4
#define EXTERNAL_SPINDLE_PIN PORTAbits.RA4

#define EXTERNAL_REVERSE_TRIS TRISAbits.TRISA4
#define EXTERNAL_REVERSE_PIN PORTAbits.RA4

#define DISPLAY_A_TRIS TRISCbits.TRISC2
#define DISPLAY_A_PIN LATCbits.RC2

#define DISPLAY_B_TRIS TRISCbits.TRISC1
#define DISPLAY_B_PIN LATCbits.RC1

#define DISPLAY_C_TRIS TRISCbits.TRISC7
#define DISPLAY_C_PIN LATCbits.RC7

#define DISPLAY_D_TRIS TRISCbits.TRISC5
#define DISPLAY_D_PIN LATCbits.RC5

#define DISPLAY_E_TRIS TRISCbits.TRISC4
#define DISPLAY_E_PIN LATCbits.RC4

#define DISPLAY_F_TRIS TRISCbits.TRISC3
#define DISPLAY_F_PIN LATCbits.RC3

#define DISPLAY_G_TRIS TRISCbits.TRISC0
#define DISPLAY_G_PIN LATCbits.RC0

#define DISPLAY_DP_TRIS TRISCbits.TRISC6
#define DISPLAY_DP_PIN LATCbits.RC6

#define DISPLAY_SEG1_TRIS TRISBbits.TRISB7
#define DISPLAY_SEG1_PIN LATBbits.LATB7

#define DISPLAY_SEG2_TRIS TRISBbits.TRISB6
#define DISPLAY_SEG2_PIN LATBbits.LATB6

#define DISPLAY_SEG3_TRIS TRISBbits.TRISB5
#define DISPLAY_SEG3_PIN LATBbits.LATB5

#define DISPLAY_SEG4_TRIS TRISBbits.TRISB4
#define DISPLAY_SEG4_PIN LATBbits.LATB4

#define FORWARD_TRIS TRISBbits.TRISB0
#define FORWARD_PIN PORTBbits.RB0

#define REVERSE_TRIS TRISBbits.TRISB3
#define REVERSE_PIN PORTBbits.RB3

#define ENCODER_A_TRIS TRISBbits.TRISB2
#define ENCODER_A_PIN PORTBbits.RB2

#define ENCODER_B_TRIS TRISBbits.TRISB1
#define ENCODER_B_PIN PORTBbits.RB1


//#define TEMPERATURE_TRIS TRISAbits.TRISA0
//#define TEMPERATURE_ANCON ANCON0bits.PCFG0
//
//#define BUZZER_TRIS TRISAbits.TRISA1
//#define BUZZER_PIN LATAbits.LATA1
//
//#define FAN_TRIS TRISBbits.TRISB7
//#define FAN_PIN LATBbits.LATB7
//
//#define DISPLAY_RESET_TRIS TRISBbits.TRISB6
//#define DISPLAY_RESET_PIN LATBbits.LATB6
//
//#define DISPLAY_BACKLIGHT_TRIS TRISCbits.TRISC7
//#define DISPLAY_BACKLIGHT_PIN LATCbits.LATC7
//#define DISPLAY_BACKLIGHT_PPS RPOR18
//
//#define I2C_SDA_TRIS TRISBbits.TRISB5
//#define I2C_SCL_TRIS TRISBbits.TRISB4
//
//#define MOTOR_ENABLE_TRIS TRISBbits.TRISB3
//#define MOTOR_ENABLE_PIN LATBbits.LATB3
//
//#define MOTOR_DIRECTION_TRIS TRISBbits.TRISB2
//#define MOTOR_DIRECTION_PIN LATBbits.LATB2
//
//#define MOTOR_STEP_TRIS TRISBbits.TRISB1
//#define MOTOR_STEP_PIN LATBbits.LATB1
//#define MOTOR_STEP_PIN_READ PORTBbits.RB1
//#define MOTOR_STEP_PPS RPOR4
//
//#define MOTOR_ERROR_TRIS TRISBbits.TRISB0
//#define MOTOR_ERROR_PIN PORTBbits.RB0
//#define MOTOR_ERROR_ANCON ANCON1bits.PCFG12
//
//#define ENCODER1_PORT PORTC
//#define ENCODER1_MASK 0b00000111
//
//#define ENCODER1_A_TRIS TRISCbits.TRISC2
//#define ENCODER1_A_PIN PORTCbits.RC2
//#define ENCODER1_A_ANCON ANCON1bits.PCFG11
//#define ENCODER1_A_MASK 0b00000100
//
//#define ENCODER1_B_TRIS TRISCbits.TRISC0
//#define ENCODER1_B_PIN PORTCbits.RC0
//#define ENCODER1_B_ANCON NONE
//#define ENCODER1_B_MASK 0b00000001
//
//#define ENCODER1_PB_TRIS TRISCbits.TRISC1
//#define ENCODER1_PB_PIN PORTCbits.RC1
//#define ENCODER1_PB_ANCON NONE
//#define ENCODER1_PB_MASK 0b00000010
//
//#define ENCODER2_PORT PORTA
//#define ENCODER2_MASK 0b00101100
//
//#define ENCODER2_A_TRIS TRISAbits.TRISA2
//#define ENCODER2_A_PIN PORTAbits.RA2
//#define ENCODER2_A_ANCON ANCON0bits.PCFG2
//#define ENCODER2_A_MASK 0b00000100
//
//#define ENCODER2_B_TRIS TRISAbits.TRISA5
//#define ENCODER2_B_PIN PORTAbits.RA5
//#define ENCODER2_B_ANCON ANCON0bits.PCFG4
//#define ENCODER2_B_MASK 0b00100000
//
//#define ENCODER2_PB_TRIS TRISAbits.TRISA3
//#define ENCODER2_PB_PIN PORTAbits.RA3
//#define ENCODER2_PB_ANCON ANCON0bits.PCFG3
//#define ENCODER2_PB_MASK 0b00001000


/*
 * Type definitions
 */

//typedef enum 
//{
//    DISPLAY_STATE_MAIN = 0x00,
//    DISPLAY_STATE_MAIN_SETUP = 0x01,
//    DISPLAY_STATE_MAIN_DIVIDE = 0x02,
//    DISPLAY_STATE_MAIN_ARC = 0x03,
//    DISPLAY_STATE_MAIN_MANUAL = 0x04,
//    DISPLAY_STATE_MAIN_ZERO = 0x05,
//    DISPLAY_STATE_SETUP1 = 0x10,
//    DISPLAY_STATE_SETUP1_CONFIRM = 0x11,
//    DISPLAY_STATE_SETUP1_CANCEL = 0x12,        
//    DISPLAY_STATE_SETUP2 = 0x20,
//    DISPLAY_STATE_SETUP2_CCW = 0x21,
//    DISPLAY_STATE_SETUP2_CW = 0x22,        
//    DISPLAY_STATE_DIVIDE1 = 0x30,
//    DISPLAY_STATE_DIVIDE1_CONFIRM = 0x31,
//    DISPLAY_STATE_DIVIDE1_CANCEL = 0x32,
//    DISPLAY_STATE_DIVIDE2 = 0x40,
//    DISPLAY_STATE_DIVIDE2_NORMAL = 0x41,
//    DISPLAY_STATE_ARC1 = 0x50,
//    DISPLAY_STATE_ARC1_CONFIRM = 0x51,
//    DISPLAY_STATE_ARC1_CANCEL = 0x52,
//    DISPLAY_STATE_ARC2 = 0x60,
//    DISPLAY_STATE_ARC2_CCW = 0x61,
//    DISPLAY_STATE_ARC2_CANCEL = 0x62,
//    DISPLAY_STATE_ARC2_CW = 0x63,
//    DISPLAY_STATE_ZERO = 0x70,
//    DISPLAY_STATE_ZERO_NORMAL = 0x71,
//    DISPLAY_STATE_MANUAL = 0x80,
//    DISPLAY_STATE_MANUAL_CCW = 0x81,
//    DISPLAY_STATE_MANUAL_CANCEL = 0x82,
//    DISPLAY_STATE_MANUAL_CW = 0x83,
//    DISPLAY_STATE_MANUAL_BUSY = 0x84,
//    DISPLAY_STATE_ENCODER_TEST = 0xF0
//} displayState_t;
//
//typedef struct
//{
//    volatile uint8_t subTimeSlot;
//    volatile uint8_t timeSlot;
//    volatile uint8_t done;
//    volatile int8_t encoder1Count;
//    volatile int8_t button1;
//    volatile int8_t encoder2Count;
//    volatile int8_t button2;
//    volatile uint16_t current_position;
//    displayState_t displayState;
//    uint8_t busy;
//} os_t;


/*
 * Global variables
 */

//os_t os;


/*
 * Function prototypes
 */


//void tmr0_isr(void);
//void system_init(void);

#endif	/* OS_H */
