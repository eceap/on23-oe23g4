/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene las definiciones de user
 * 
 * Aquí se encuentra la implementación de users, los defines, macros, 
 * datos internos y externos, declaraciones y definiciones de funciones
 * internas y definiciones de funciones externas.
 */

/*==================[ Inlcusiones ]============================================*/ 
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

#include "system.h"     /* Funciones/Parametros System, como conf de osc/perif */
#include "user.h"       /* Funciones/Parametros User, como InitApp */
#include "tick.h"

/*==================[ Definiciones y macros ]==================================*/
// Nuevo tipo de datos enumerado llamado estadoMEF_t
typedef enum{ E_INICIALIZACION, E_FUNCIONANDO, E_ERROR } estadoMEF_t;

/*==================[ Definiciones de datos internos ]=========================*/
estadoMEF_t  estadoActual; // Variable de estado (global)
tick_t tInicio;

/*==================[ Definiciones de datos externos ]=========================*/
//char datoUser; //Ejemplo

/*==================[ Declaraciones de funciones internas ]====================*/
uint8_t tests(void);

/*==================[ Definiciones de funciones internas ]=====================*/
//static void funcUser(void){ //Ejemplo
//}; 

/*==================[ Definiciones de funciones externas ]=====================*/
/**
 * @brief	Inicializa Ports, Periféricos e Interrupciones
 * @return	Nada
 */
void appInit(void){
    /* TODO: Inicializar Ports/Periféricos/Interrupciones */

    /* Configura funciones analógicas y dirección de los Ports de I/O */
    ANSEL = 0;
    ANSELH = 0;
    TRIS_LED1 = 0;
    TRIS_LED2 = 0;
    TRIS_LED3 = 0;
    TRIS_LED4 = 0;
    TRIS_TRANSFORMADOR = 1;
    TRIS_FUSIBLE = 1;
    TRIS_TEC_ACK = 1;
    TRIS_BUZZER = 0;
    TRIS_PIN_Q = 0;
    TRIS_PIN_Q_NEGADO = 0;
    tickInit();
    __delay_ms(100); //Espera que se estabilice la fuente
    PIN_LED1 = 0; // Apago todos los leds
    PIN_LED2 = 0;
    PIN_LED3 = 0;
    PIN_LED4 = 0;
    
    /* Habilito Interrupciones si es necesario*/
    CCP1IE = 1;
    // PEIE = 1;
    GIE = 1;  
}


void InicializarMEF(void){
    estadoActual = E_INICIALIZACION; // Establece el estado actual
    tInicio = tickRead(); // Inicia temporizacion
}

void ActualizarMEF(void){
    switch(estadoActual){
        case E_INICIALIZACION:
            if(tickRead() >= tInicio){
                LED_INICIO_Y_NORMAL = !LED_INICIO_Y_NORMAL; // Togglea el led
                tInicio += TIEMPO_TOGGLE_LED_VERDE; // Expande el tiempo para volver a togglear
            }
            if((PIN_TRANSFORMADOR == 1 && PIN_FUSIBLE == 1) || (tickRead() >= TIEMPO_INICIALIZACION_MAXIMO)){
                LED_INICIO_Y_NORMAL = 1;
                estadoActual = E_FUNCIONANDO;
            }
            break;
        
        case E_FUNCIONANDO:
            if( tests() == 1 ){ // Si hay algun error cambio de estado
                LED_INICIO_Y_NORMAL = 0;
                LED_FALLA_GENERAL = 1;
                PIN_BUZZER = 1;
                estadoActual = E_ERROR ;
            }
            break;
            
        case E_ERROR:
            if(PIN_TEC_ACK == 0){ // Si se presiona la tecla
                PIN_BUZZER = 0;
            }
            if(tests() == 0){ // Se arreglaron los errores
                LED_INICIO_Y_NORMAL = 1;
                LED_FALLA_GENERAL = 0;
                LED_FUSIBLE = 0;
                LED_TRANSFORMADOR = 0;
                estadoActual = E_FUNCIONANDO;
            }
            break;
    }
}

uint8_t tests(void){
    if(PIN_FUSIBLE == 0){ // Si NO recibo tension en el pin hay error
        LED_FUSIBLE = 1;
        return(1);
    }
    if(PIN_TRANSFORMADOR == 1){ // Si recibo tension en el pin hay error
        LED_TRANSFORMADOR = 1;
        return(1);
    }
    return(0);
}

/*==================[ Fin del archivo ]========================================*/
    