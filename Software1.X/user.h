/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene macros y definiciones de user
 * 
 * Aquí se definen macros, tipos de datos y se declaran las funciones y datos 
 * externos de user
 */
#ifndef USER_H
#define USER_H
/*==================[ Inclusiones]============================================*/
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

/*==================[ Macros ]=================================================*/
/* User Level #define Macros                                                 */
/* TODO: Los parámetros de user.c pueden ponerse aquí */

// Leds 
#define	PIN_LED1    PORTDbits.RD0
#define	TRIS_LED1   TRISDbits.TRISD0
#define	PIN_LED2    PORTDbits.RD2
#define	TRIS_LED2   TRISDbits.TRISD2
#define	PIN_LED3    PORTDbits.RD3
#define	TRIS_LED3   TRISDbits.TRISD3
#define	PIN_LED4    PORTDbits.RD4
#define	TRIS_LED4   TRISDbits.TRISD4
#define	PIN_LED5    PORTDbits.RD5
#define	TRIS_LED5   TRISDbits.TRISD5
#define	PIN_LED6    PORTDbits.RD6
#define	TRIS_LED6   TRISDbits.TRISD6
#define	PIN_LED7    PORTDbits.RD7
#define	TRIS_LED7   TRISDbits.TRISD7

// Alias para los leds
#define LED_INICIO_Y_NORMAL     PIN_LED1
#define LED_FALLA_GENERAL       PIN_LED2
#define LED_FUSIBLE             PIN_LED3
#define LED_TRANSFORMADOR       PIN_LED4
#define LED_FALLA_CI            PIN_LED5
#define LED_TENSION_GRAL        PIN_LED6
#define LED_TENSION_CI          PIN_LED7

// Pines de testeo
#define PIN_FUSIBLE         PORTAbits.RA0
#define TRIS_FUSIBLE        TRISAbits.TRISA0
#define PIN_TRANSFORMADOR   PORTAbits.RA1
#define TRIS_TRANSFORMADOR  TRISAbits.TRISA1
#define PIN_ALIM_CI         PORTAbits.RA2
#define TRIS_ALIM_CI        TRISAbits.TRISA2
#define PIN_Q               PORTAbits.RA3
#define TRIS_PIN_Q          TRISAbits.TRISA3
#define PIN_Q_NEGADO        PORTAbits.RA4
#define TRIS_PIN_Q_NEGADO   TRISAbits.TRISA4

//Buzzer
#define	PIN_BUZZER      PORTCbits.RC0
#define	TRIS_BUZZER     TRISCbits.TRISC0
#define	PIN_TEC_ACK     PORTBbits.RB0
#define	TRIS_TEC_ACK    TRISBbits.TRISB0

// Tiempos modificables
#define TIEMPO_TOGGLE_LED_VERDE 500 // 500 x 1ms cada ciclo = 500ms
#define TIEMPO_INICIALIZACION_MAXIMO 5000 // 5000 x 1ms cada ciclo = 5s

/*==================[ Tipos de datos declarados por el usuario ]===============*/

/*==================[ Declaraciones de datos externos ]========================*/
//extern char datoUser; //Ejemplo

/*==================[ Declaraciones de funciones externas ]====================*/
/* TODO: Los prototipos de User level (ej. InitApp) van aquí */
void appInit(void);     /* Inicializa las I/O y los perif�ricos */
void InicializarMEF(void);  // Inicializa la maquina de estado finito
void ActualizarMEF(void);   // Actualiza la maquina de estado finito

/*==================[ Fin del archivo ]========================================*/
#endif// USER_H
