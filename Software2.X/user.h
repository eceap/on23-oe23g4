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
#define	PIN_LED1    PORTCbits.RC2
#define	TRIS_LED1   TRISCbits.TRISC2
#define	PIN_LED2    PORTCbits.RC3
#define	TRIS_LED2   TRISCbits.TRISC3
#define	PIN_LED3    PORTCbits.RC4
#define	TRIS_LED3   TRISCbits.TRISC4
#define	PIN_LED4    PORTCbits.RC5
#define	TRIS_LED4   TRISCbits.TRISC5

// Alias para los leds
#define LED_INICIO_Y_NORMAL     PIN_LED1
#define LED_FALLA_GENERAL       PIN_LED2
#define LED_FUSIBLE             PIN_LED3
#define LED_TRANSFORMADOR       PIN_LED4

// Pines de testeo
#define PIN_FUSIBLE         PORTAbits.RA0
#define TRIS_FUSIBLE        TRISAbits.TRISA0
#define PIN_TRANSFORMADOR   PORTAbits.RA1
#define TRIS_TRANSFORMADOR  TRISAbits.TRISA1

//Buzzer
#define	PIN_BUZZER      PORTCbits.RC6
#define	TRIS_BUZZER     TRISCbits.TRISC6
#define	PIN_TEC_ACK     PORTAbits.RA2
#define	TRIS_TEC_ACK    TRISAbits.TRISA2

// Pines de Oscilación
#define	PIN_Q               PORTCbits.RC0
#define	TRIS_PIN_Q          TRISCbits.TRISC0
#define	PIN_Q_NEGADO        PORTCbits.RC1
#define	TRIS_PIN_Q_NEGADO   TRISCbits.TRISC1

// Tiempos modificables
#define TIEMPO_TOGGLE_LED_VERDE 50 // 50 x 10ms cada ciclo = 500ms
#define TIEMPO_INICIALIZACION_MAXIMO 500 // 500 x 10ms cada ciclo = 5s

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
