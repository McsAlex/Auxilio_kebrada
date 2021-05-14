/*
 * File:   TECLADO.c
 * Author: 20185561
 *
 * Created on 5 de Maio de 2021, 14:21
 */


#include <xc.h>
#include "config.h"
#include "TECLADO.h"
#include "delay.h"

void Teclado_init( void )
{
    ANSELH = 0;
    TRISB = 0xF0; 
    PORTB = 0;
}

#define MASK 0x10

char tabela[4][4] = {{'1', '2', '3', 'A' },
                     {'4', '5', '6', 'B' },
                     {'7', '8', '9', 'C' },
                     {'*', '0', '#', 'D' }};

char Teclado( void )
{
    char tecla = 0;
    char col;
    char lin; 
    
    for ( lin = 0; lin<4; lin++ )
    {
        PORTB = 0x01<<lin;
        for( col = 0; col<4; col++ )
        {
            if ( PORTB & MASK<<col ) tecla = tabela[lin][col];
        }
    }
    
    return( tecla );
    //Apagar daqui pra baixo se der errado

}



