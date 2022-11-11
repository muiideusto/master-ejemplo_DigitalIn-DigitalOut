/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define pinLED1 PA_10
#define pinLED2 PB_5
#define pinLED3 PB_10

#define pinBT1 PA_15
#define pinBT2 PB_7
#define pinBT3 PC_2

#define WAIT_TIME_MS 100 

DigitalOut led1(pinLED1);
DigitalOut led2(pinLED2);
DigitalOut led3(pinLED3);

DigitalIn bt1(pinBT1);
DigitalIn bt2(pinBT2);
DigitalIn bt3(pinBT3);


//Los leds de la placa son de anodo comun se encienden con un 0 y se apagan con un 1.
//Los botones son de logica activa, al pulsar dan un 1 y cuando se sueltan un 0.
int main()
{
    

    while (true)
    {
        //Si el boton 1 se pulsa el led1 parpadea cada 200ms
        // y se apaga el led3
        if(bt1){
            led1 = !led1;
            led3=1;
        }
        
        //Si se pulsa el boton 2 el led2 se enciende, si se suelta se apaga
        if(bt2!=0){
            led2=0;
        }else{
            led2=1;
        }

        // si el boton 3 se pulsa el led3 se queda encendido hasta que se pulse el boton0
        if(bt3.read()==1){
            led3=0;
        }
        thread_sleep_for(WAIT_TIME_MS);
    }
}
