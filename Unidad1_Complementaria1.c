//Universidas Atonoma Nacional de Mexico
//FACULTAD DE CONTADURÍA Y ADMINISTRACION
//INFORMATICA A DISTANCIA
//Programa creado por Daniel Hernandez Hernandez el 25/08/2024
//Asignatura: 2237 Programacion
//Profesor: Raúl Ojeda Villagómez

//Libreria estandar de C, Libreria para funciones la cual ocupo para rand() y srand() y Libreria para funciones de tiempo
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constantes
#define TOTAL_NUMEROS 100
#define NUMEROS_ALEATORIOS 80

// Funcion para intercambiar dos números
void intercambiar(int *a, int *b) {
    int temporal = *a;
    *a = *b;
    *b = temporal;
}

// Funcion para asignar numeros aleatorios al arreglo
void aleatorizar(int arreglo[], int tamano) {
    if (tamano <= 1) return;
    srand((unsigned int)time(NULL));
    for (int i = tamano - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        intercambiar(&arreglo[i], &arreglo[j]);
    }
}

// Funcion para comparar dos numeros
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int numeros[TOTAL_NUMEROS];  //Guardar los numeros del 1 al 100

    // Inicializa el arreglo con numeros del 1 al 100
    for (int i = 0; i < TOTAL_NUMEROS; i++) {
        numeros[i] = i + 1;
    }

    aleatorizar(numeros, TOTAL_NUMEROS); //Asigna números aleatorios al arreglo

    // Ordena los primeros 80 numeros aleatorios
    qsort(numeros, NUMEROS_ALEATORIOS, sizeof(int), comparar);
    printf("80 numeros aleatorios:\n");
    for (int i = 0; i < NUMEROS_ALEATORIOS; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    // Ordena los 20 numeros restantes
    qsort(numeros + NUMEROS_ALEATORIOS, TOTAL_NUMEROS - NUMEROS_ALEATORIOS, sizeof(int), comparar);
    printf("20 numeros faltantes:\n");
    for (int i = NUMEROS_ALEATORIOS; i < TOTAL_NUMEROS; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}
//Programador: Daniel Hernandez Hernandez
//Fecha: 04/09/2024
//Programa para generar 100 números aleatorios y mostrar los primeros 80 ordenados y los últimos 20 también ordenados