//! ELO321 - Teoría de Sistemas Operativos, 2020-2
/*!
* @file   : parteA.c 
* @author   : Julio Contreras Fuica
* @date   : 01/11/2020
* @brief  : Parte A de la Tarea 1 
*/

#include <time.h>
#include <stdio.h>
#include <string.h> 


int main (int argc, char *argv[]){
	int n;
	if (argc != 2) //Verifica si hay solo un argumento
	{
		printf("Debes ingresar un solo numero\n");
	} else {
		n = atoi(argv[1]);
		if (n <= 0) //El argumento es un string o menor a 1
		{
			printf("El numero %d no es valido\n", n);
			return -1;
		} else {
			printf("El numero %d es valido\n", n);
			return 0;
		}
	}
}