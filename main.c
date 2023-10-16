/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K42
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/
#include <xc.h>
#include "mcc_generated_files/mcc.h"
// Definición de la tabla LUT
const uint8_t sineLUT[] = {
    16, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 25, 26, 27, 27, 28, 29, 29, 30, 30,
    30, 31, 31, 31, 31, 31, 31, 31, 31, 31, 30, 30, 30, 29, 29, 28, 27, 27, 26, 25,
    25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7,
    6, 6, 5, 4, 4, 3, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2,
    3, 4, 4, 5, 6, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 15
};
uint8_t LUTIndex = 0;
/*
                         Main application
 */
void main(void)
{
 // Inicializar el dispositivo
    SYSTEM_Initialize();
    TRISCbits.TRISC2 = 0;  // Configura RC2 como salida

    // Habilitar las interrupciones globales
    INTERRUPT_GlobalInterruptEnable();

  
    
    while (1)
    {
      // Actualizar el valor del DAC usando la tabla LUT
        DAC1_SetOutput(sineLUT[LUTIndex]);

        // Incrementar el índice de la tabla LUT
        LUTIndex++;
        if (LUTIndex >= sizeof(sineLUT))
        {
            LUTIndex = 0;
        }

        // Esperar un tiempo específico para obtener la frecuencia deseada
        // Este valor puede necesitar ajustes según la frecuencia de reloj y la configuración del timer
        __delay_us(10); // Ajustar según sea necesario
    }
}
/**
 End of File
*/