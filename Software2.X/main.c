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
    while (1) {
        ActualizarMEF();
    }
}