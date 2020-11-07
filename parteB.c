//! ELO321 - Teoría de Sistemas Operativos, 2020-2
/*!
* @file   : parteB.c 
* @author : Julio Contreras Fuica
* @author : Cristian González Bustos
* @date   : 01/11/2020
* @brief  : Parte B de la Tarea 1 
*/

#include <pthread.h>
#include <stdio.h>

#define n 50

float avg_value;
int min_value;
int max_value;

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
    
    pthread_t tid1, tid2, tid3;
    pthread_attr_t attr1, attr2, attr3;
    
    pthread_attr_init(&attr1);
    pthread_create(&tid1, &attr1, return_Avg, NULL);
    
    pthread_attr_init(&attr2);
    pthread_create(&tid2, &attr2, return_Min, NULL);
    
    pthread_attr_init(&attr3);
    pthread_create(&tid3, &attr3, return_Max, NULL);
    
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    
    printf("\n");
}


void* return_Avg(void*p)
{
    avg_value = 0;
    int i;
    
    for (i = 0; i < n; i++)
      avg_value += numArray[i];
    avg_value /= n;
    
    printf("Valor promedio: %f\n", avg_value);
    printf("Thread ID: %u calculo promedio.\n", pthread_self() );
    pthread_exit(0);
}

void* return_Min(void*p)
{
    min_value = 100;
    int i;
    
    for (i = 0; i < n; i++) {
      if ( numArray[i] < min_value )
        min_value = numArray[i];
    }
    
    printf("Valor minimo: %d\n", min_value);
    printf("Thread ID: %u calculo minimo.\n", pthread_self() );
    pthread_exit(0);
}

void* return_Max(void*p)
{
    max_value = 0;
    int i;
    
    for (i = 0; i < n; i++) {
      if ( numArray[i] > max_value )
        max_value = numArray[i];
    }
    
    printf("Valor maximo: %d\n", max_value);
    printf("Thread ID: %u calculo maximo.\n", pthread_self() );
    pthread_exit(0);
}























