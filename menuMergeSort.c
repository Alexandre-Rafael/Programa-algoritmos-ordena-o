#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mergeSort.c" 

void createDirectories(const char *algorithmName); // Declare a função createDirectories no início do arquivo

int menuMergeSort() {
    int size;
    char option;

    printf("Digite o tamanho do array: ");
    scanf("%d", &size);

    const char *prefix;
    const char *folder;
    int *arr = NULL;

    if (size <= 0) {
        printf("Tamanho invalido do array.\n");
        return 1;
    }

    // Nome do algoritmo
    const char *algorithmName = "MergeSort";

    // Crie os diretórios necessários
    createDirectories(algorithmName);

    printf("================================ MENU ======================================\n");
    printf("|                          Merge Sort                                     |\n");
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
            arr = (int *)malloc(sizeof(int) * size);

            if (arr == NULL) {
                printf("Erro na alocaçao de memória.\n");
                return 1;
            }

            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 1000000;
            }
            prefix = "random";
            folder = "Random";
            break;
        case 'c':
            arr = (int *)malloc(sizeof(int) * size);

            if (arr == NULL) {
                printf("Erro na alocaçao de memória.\n");
                return 1;
            }

            for (int i = 0; i < size; i++) {
                arr[i] = i;
            }
            prefix = "crescente";
            folder = "Crescente";
            break;
        case 'd':
            arr = (int *)malloc(sizeof(int) * size);

            if (arr == NULL) {
                printf("Erro na alocaçao de memória.\n");
                return 1;
            }

            for (int i = 0; i < size; i++) {
                arr[i] = size - i;
            }
            prefix = "decrescente";
            folder = "Decrescente";
            break;
        case 's':
            return 0;
        default:
            printf("Opcao invalida\n");
            return 1;
    }

    int *arr_copy = (int *)malloc(sizeof(int) * size);

    if (arr_copy == NULL) {
        printf("Erro na alocação de memória para arr_copy.\n");
        free(arr);
        return 1;
    }

    memcpy(arr_copy, arr, sizeof(int) * size);

    clock_t t = clock();
    mergeSort(arr, 0, size - 1);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    saveArrayToFile(arr_copy, size, prefix, folder, algorithmName);
    saveSortedArrayToFile(arr, size, prefix, folder, algorithmName);
    saveTimeToFile(time_taken, prefix, size, folder, algorithmName);

    free(arr);
    free(arr_copy);
    return 0;
}
