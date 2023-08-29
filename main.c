#include <stdio.h>
#include <stdlib.h>
#include "menu.c"

int exibirMenu() { // Função para exibir o menu

    int opcao;

    printf("================================ MENU ======================================\n");
    printf("|                          Algoritmos de Ordenacao                        |\n");
    printf("|-------------------------------------------------------------------------|\n");
    printf("|  Digite 1 para o Insertion Sort                                         |\n");
    printf("|  NADA POR AQUI                                                          |\n");
    printf("|  NADA POR AQUI                                                          |\n");
    printf("|  Digite 4 para Sair                                                     |\n");
    printf("|-------------------------------------------------------------------------|\n");
    
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Array ordenado usando Insertion Sort.\n");
            menuInsertionSort();
            break;

        case 2:
            printf("Nada por aqui\n");
            break;

        case 3:
            printf("Nada por aqui\n");
            break;

        case 4:
            exit(0);

        default:
            printf("Opcao invalida.\n");
            break;
    }

    return opcao;
}

int main() {

    int opcao;

    do {

        opcao = exibirMenu();

    } while (opcao != 4);

    scanf("%d", &opcao);

    return 0;
}

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




