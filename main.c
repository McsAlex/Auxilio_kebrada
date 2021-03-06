/*
 * File:   main.c
 * Author: 21192700
 *
 * Created on 14 de Maio de 2021, 16:17
 */

#include "config.h"
#include <xc.h>
#include "TECLADO.h"
#include "delay.h"
#include "LCD4vias.h"

void main(void) 
{
    char estado = 0;
    char tecla = 0;
    Teclado_init();
    dispLCD_init();
    while(1)
    {
        tecla = Teclado();
        switch( estado )
        {
            case 0: 
                    estado = 1;
                    break;
            case 1: 
                dispLCD(0,0, "Salve danado!   ");    
                delay (4000);
                estado = 10;
                    break; 
            case 10: 
                dispLCD(0,0, "Auxilio  kebrada");
                dispLCD(1,0,"1:Operacao C:cfg");
                if( tecla == '1')
                    estado = 20;
                if(tecla == 'C')
                    estado = 100;
                    break; 
            case 20: 
                dispLCD(0,0,"Operando...     ");
                dispLCD(1,0, "                ");
                if( tecla == '*')
                    estado = 10;
                    break; 
            case 100: 
                dispLCD(0,0,"Configurando... ");
                dispLCD(1,0,"                ");
                if( tecla == '*')    
                    estado = 10;
                    break; 
        }
    }
    ;
}
