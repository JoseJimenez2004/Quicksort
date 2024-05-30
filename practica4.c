#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para intercambiar dos elementos en un arreglo
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para seleccionar el pivote como el último elemento
int partition_last(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Función para seleccionar el pivote al azar y realizar la partición directamente
int partition_random(int arr[], int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);
    int pivot = arr[random];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


// Implementación del algoritmo Quicksort de tres vías
void quickSort_random(int arr[], int low, int high) {
    if (low < high) {
        int lt = low, gt = high;
        int i = low + 1;
        int pivot = arr[low];
        while (i <= gt) {
            if (arr[i] < pivot) {
                swap(&arr[i++], &arr[lt++]);
            } else if (arr[i] > pivot) {
                swap(&arr[i], &arr[gt--]);
            } else {
                i++;
            }
        }
        quickSort_random(arr, low, lt - 1);
        quickSort_random(arr, gt + 1, high);
    }
}

int main() {
    int n, choice;
    printf("Ingrese el tamaño de los datos de entrada: ");
    scanf("%d", &n);

    // Generar datos aleatorios entre 1 y 99
    int data[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        data[i] = rand() % 99 + 1;
    }

    // Menú para seleccionar el tipo de Quicksort a ejecutar
    printf("Seleccione el tipo de Quicksort:\n");
    printf("1. Quicksort con pivote en el último elemento\n");
    printf("2. Quicksort aleatorizado\n");
    printf("3. Quicksort de tres vías\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Calcular el tiempo de ejecución de Quicksort con el pivote en el último elemento
            clock_t start1, end1;
            start1 = clock();
            quickSort_random(data, 0, n - 1);
            end1 = clock();
            double time_taken1 = ((double)end1 - start1) / CLOCKS_PER_SEC;
            printf("Tiempo de ejecucion de Quicksort con pivote en el ultimo elemento: %f segundos\n", time_taken1);
            // Imprimir el arreglo ordenado
        /*printf("Arreglo ordenado:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");*/
            break;
        case 2:
            // Calcular el tiempo de ejecución de Quicksort aleatorizado
            clock_t start2, end2;
            start2 = clock();
            quickSort_random(data, 0, n - 1);
            end2 = clock();
            double time_taken2 = ((double)end2 - start2) / CLOCKS_PER_SEC;
            printf("Tiempo de ejecucion de Quicksort aleatorizado: %f segundos\n", time_taken2);
// Imprimir el arreglo ordenado
       /* printf("Arreglo ordenado:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");*/
            break;
        case 3:
            // Calcular el tiempo de ejecución de Quicksort de tres vías
            clock_t start3, end3;
            start3 = clock();
            quickSort_random(data, 0, n - 1);
            end3 = clock();
            double time_taken3 = ((double)end3 - start3) / CLOCKS_PER_SEC;
            printf("Tiempo de ejecucion de Quicksort de tres vias: %f segundos\n", time_taken3);
            // Imprimir el arreglo ordenado
       /* printf("Arreglo ordenado:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");*/
            break;
        default:
            printf("Opcion invalida.\n");
            break;
    }

    return 0;
}

