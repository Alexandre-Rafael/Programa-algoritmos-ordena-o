#include "insertionSort.c"
#include <time.h>

void saveArrayToFile(int arr[], int size, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "%d\n", size);
        for (int i = 0; i < size; i++) {
            fprintf(file, "%d\n", arr[i]);
        }
        fclose(file);
    } else {
        printf("Não foi possível criar o arquivo: %s\n", filename);
    }
}

void saveTimeToFile(double time_taken, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "%f\n", time_taken);
        fclose(file);
    } else {
        printf("Não foi possível criar o arquivo: %s\n", filename);
    }
}

int menuInsertionSort() {
    int size;
    char option;

    printf("Digite o tamanho do array: ");
    scanf("%d", &size);

    int arr[size];

    printf("================================ MENU ======================================\n");
    printf("|                          INSERTION SORT                                 |\n");
    printf("|-------------------------------------------------------------------------|\n");
    printf("|  'r' para numeros randomicos                                            |\n");
    printf("|  'c' para numeros crescentes                                            |\n");
    printf("|  'd' para numeros decrescentes                                          |\n");
    printf("|  's' para sair                                                          |\n");
    printf("|-------------------------------------------------------------------------|\n");

    scanf(" %c", &option);

    switch (option) {
        case 'r':
            srand(time(NULL));
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 1000000; // Números randômicos de 0 a 1.000.000
            }
            break;
        case 'c':
            for (int i = 0; i < size; i++) {
                arr[i] = i;
            }
            break;
        case 'd':
            for (int i = 0; i < size; i++) {
                arr[i] = size - i;
            }
            break;
        case 's':
            return 0;
        default:
            printf("Opção inválida\n");
            return 1;
    }

    printf("Array original:\n");
    printArray(arr, size);

    int arr_copy[size];
    for (int i = 0; i < size; i++) {
        arr_copy[i] = arr[i];
    }

    clock_t t;
    t = clock();
    insertionSort(arr, size);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("Array ordenado:\n");
    printArray(arr, size);

    saveArrayToFile(arr_copy, size, "instancias_entrada.txt");
    saveArrayToFile(arr, size, "instancias_ordenadas.txt");
    saveTimeToFile(time_taken, "tempo_gasto.txt");

    return 0;
}