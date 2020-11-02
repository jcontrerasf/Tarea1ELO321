//! ELO321 - Teoría de Sistemas Operativos, 2020-2
/*!
* @file   : parteA.c 
* @author : Julio Contreras Fuica
* @author : Cristian González Bustos
* @date   : 01/11/2020
* @brief  : Parte A de la Tarea 1 
*/

//RECORDAR PASAR TABS A ESPACIOS
//RECORDAR PASAR TABS A ESPACIOS
//RECORDAR PASAR TABS A ESPACIOS
//RECORDAR PASAR TABS A ESPACIOS
//RECORDAR PASAR TABS A ESPACIOS
//RECORDAR PASAR TABS A ESPACIOS
//RECORDAR PASAR TABS A ESPACIOS

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*! \fn sucesion_Collatz (unsigned int n)
    \brief Implimenta la susesión de Collatz
    \param n Número a operar
*/
int sucesion_Collatz (unsigned int n);


int main (int argc, char *argv[]){
    int n;
    pid_t pid1;
    time_t tiempo;

    if (argc != 2) //Verifica si hay solo un argumento
    {
        printf("Debes ingresar un solo argumento\n");
        return -1;
    } else {
        n = atoi(argv[1]);
        if (n <= 0) //El argumento es un string o menor a 1
        {
            printf("El número %d no es válido\n", n);
            return -1;
        } else {
            //printf("El número %d sí es válido\n", n);
            pid1 = fork();
            if (pid1 < 0)
            {
                printf("Error al intentar crear el proceso hijo");
            }
            else if (pid1 == 0){ //Proceso hijo
                time(&tiempo);
                printf("Hora de ejecución: %s", ctime(&tiempo));
                exit(1); //Se termina el proceso hijo
                //NO SE SI VA 0 O 1
                //NO SE SI VA 0 O 1
                //NO SE SI VA 0 O 1
            } else {
                wait(); //Se espera a que termine el proceso hijo
            }
            return 0;
        }
    }
}

int sucesion_Collatz (unsigned int n){
    if (n%2 == 0) //Es par
    {
        return n/2;
    } else {
        return 3*n+1;
    }
}