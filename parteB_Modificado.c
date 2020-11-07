//! ELO321 - Teoría de Sistemas Operativos, 2020-2
/*!
* @file   : parteB_Modificado.c 
* @author : Julio Contreras Fuica
* @author : Cristian González Bustos
* @date   : 07/11/2020
* @brief  : Parte B de la Tarea 1, modificado según inciso 3.
*/

// Compilar con: gcc parteB_Modificado.c -lpthread -o parteB_mod

#include <pthread.h>
#include <stdio.h>

#define n 50

int numArray [n];

/*! \fn return_Avg (void*)
    \brief Imprime el valor promedio de los números del arreglo
*/
void* return_Avg(void*);

/*! \fn return_Min (void*)
    \brief Imprime el menor de los valores del arreglo
*/
void* return_Min(void*);

/*! \fn return_Max (void*)
    \brief Imprime el mayor de los valores del arreglo
*/
void* return_Max(void*);

void main() {
    float avg_value;
    int min_value;
    int max_value;


    printf("\n");
    time_t t;
    srand((unsigned) time(&t));
    
    // arreglo de 50 números aleatorios
    int i;
    for (i = 0; i < n; i++) {
      numArray[i] = rand() % 100 + 1;  // generar numeros entre 1 y 100
      printf("   %d  ", numArray[i]);
      if ((i+1)%5 == 0 )
          printf("\n");
    }
    
    pthread_t threadID [3];
    pthread_attr_t attr [3];
    
    pthread_attr_init(&attr[0]);
    pthread_create(&threadID[0], &attr[0], return_Avg, &avg_value);
    
    pthread_attr_init(&attr[1]);
    pthread_create(&threadID[1], &attr[1], return_Min, &min_value);
    
    pthread_attr_init(&attr[2]);
    pthread_create(&threadID[2], &attr[2], return_Max, &max_value);
    
    for (i = 0; i < 3; i++)
      pthread_join(threadID[i], NULL);

    printf("Valor promedio: %f\n", avg_value);
    printf("Valor mínimo: %d\n", min_value);
    printf("Valor máximo: %d\n", max_value);
    
    printf("\n");
}


void* return_Avg(void *avg)
{
    *(float*)avg = 0;
    int i;
    
    for (i = 0; i < n; i++)
      *(float*)avg += numArray[i];
    *(float*)avg /= n;
    
    printf("Thread ID: %u calculó promedio.\n", pthread_self() );
    pthread_exit(0);
}

void* return_Min(void *min)
{
    *(int*)min = 100;
    int i;
    
    for (i = 0; i < n; i++) {
      if ( numArray[i] < *(int*)min )
        *(int*)min = numArray[i];
    }
    
    printf("Thread ID: %u calculó mínimo.\n", pthread_self() );
    pthread_exit(0);
}

void* return_Max(void *max)
{
    *(int*)max = 0;
    int i;
    
    for (i = 0; i < n; i++) {
      if ( numArray[i] > *(int*)max )
        *(int*)max = numArray[i];
    }
    
    printf("Thread ID: %u calculó máximo.\n", pthread_self() );
    pthread_exit(0);
}
