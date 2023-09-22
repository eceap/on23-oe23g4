/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene la función principal
 * 
 * Aquí se encuentra la implementación de la función principal
 */
/*==================[ Inlcusiones ]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>
#include <stdio.h>
#include "system.h"
#include "user.h"
#include "tick.h"

/*==================[ Funcion principal ]======================================*/
void main(void) {
    appInit();
    InicializarMEF();
    PIN_LED1 = 0;
    PIN_LED2 = 0;
    PIN_LED3 = 0;
    PIN_LED4 = 0;
    PIN_LED5 = 0;
    while (1) {
        ActualizarMEF();
    }
}