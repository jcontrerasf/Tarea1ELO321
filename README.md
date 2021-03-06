# Tarea1ELO321
Tarea 1 de Teoría de Sistemas Operativos (ELO321) USM 2020-2.

### Integrante 1
Julio Erik Contreras Fuica

ROL: 201721059-1

e-mail: julio.contrerasf@sansano.usm.cl

### Integrante 2
Cristian Andrés González Bustos

ROL:201704003-3

e-mail: cristian.gonzalezbu@sansano.usm.cl

## Archivos

- __parteA.c__ Corresponde al código para la parte A de la tarea.

Compilar con:
```
$ gcc -lm -std=c99 -Wall -Wextra -D_XOPEN_SOURCE=700 parteA.c -o parteA -lrt
```
Ejectutar con:
```
$ ./parteA n
```
Donde n corresponde al número para comenzar la Conjetura de Collatz

***

- __parteA_Zombie.c__ Corresponde al código para la parte A de la tarea luego de agregar sleep().

Compilar con:
```
$ gcc -lm -std=c99 -Wall -Wextra -D_XOPEN_SOURCE=700 parteA_Zombie.c -o parteA_Zombie -lrt
```
Ejectutar con:
```
$ ./parteA_Zombie n &
```
Donde n corresponde al número para comenzar la Conjetura de Collatz
Ver procesos zombie con
```
$ ps -l
```

***

- __parteB.c__ Corresponde al código para la parte B de la tarea.

Compilar con:
```
$ gcc parteB.c -lpthread -o parteB
```
Ejecutar con:
```
$ ./parteB
```

***

- __parteB_Modificado.c__ Corresponde al código para la parte B de la tarea, considerando el inciso 3.

Compilar con:
```
$ gcc parteB_Modificado.c -lpthread -o parteB_mod
```
Ejecutar con
```
$ ./parteB_mod
```