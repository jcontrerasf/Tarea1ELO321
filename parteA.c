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

    const int SIZE = 4096;
    const char *name = "/shm";
    int shm_fd;
    void *ptr;

    if (argc != 2) //Verifica si hay solo un argumento
    {
        printf("Debes ingresar un solo argumento\n");
        return -1;
    }
    n = atoi(argv[1]); //El argumento se convierte a entero
    if (n <= 0) //El argumento es un string o menor a 1
    {
        printf("El número %d no es válido\n", n);
        return -1;
    }
    //    } else { está bien haberlo quitado?????????????????????????????????????????????
    //printf("El número %d sí es válido\n", n);
    pid1 = fork();
    if (pid1 < 0)
        printf("Error al intentar crear el proceso hijo");
    else if (pid1 == 0){ //Proceso hijo
        time(&tiempo);
        printf("Hora de ejecución: %s", ctime(&tiempo));
        exit(0); //Se termina el proceso hijo
    } else
        wait(); //Se espera a que termine el proceso hijo
/*
    //Se crea el segmento de memoria compartida
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    //Se configura el tamaño de la memoria compartida
    ftruncate(shm_fd,SIZE);

    //now map the shared memory segment in the address space of the process
    ptr = mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        printf("Map failed\n");
        return -1;
    }
*/
    pid1 = fork(); //Se reutiliza la variable pid1
    if (pid1 < 0)
        printf("Error al intentar crear el proceso hijo");
    else if (pid1 == 0){ //Proceso hijo
        printf("numero =%d\n", n);
        while(n > 1){
            n = sucesion_Collatz(n);
            printf("numero =%d\n", n);
        }
        exit(0); //Se termina el proceso hijo
    } else
        wait(); //Se espera a que termine el proceso hijo
    return 0;
}

int sucesion_Collatz (unsigned int n){
    if (n%2 == 0) //Es par
    {
        return n/2;
    } else { //Es impar
        return 3*n+1;
    }
}