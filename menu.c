#include "insertionSort.c"
#include <time.h>

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

    const char *prefix;
    const char *folder; 

    switch (option) {
        case 'r':
            srand(time(NULL));
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 1000000; 
            }
            prefix = "random";
            folder = "Random"; 
            break;
        case 'c':
            for (int i = 0; i < size; i++) {
                arr[i] = i;
            }
            prefix = "crescente";
            folder = "Crescente"; 
            break;
        case 'd':
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

    printf("Original:\n");
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

    printf("Ordenado:\n");
    printArray(arr, size);


    saveArrayToFile(arr_copy, size, prefix, folder);
    saveSortedArrayToFile(arr, size, prefix, folder);
    saveTimeToFile(time_taken, prefix, size, folder);

    return 0;
}
