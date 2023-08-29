#include <stdio.h>
#include <stdlib.h>
#include "menuInsertionSort.c"
#include <time.h>

int exibirMenu() { // Função para exibir o menu

    int opcao;

    printf("================================ MENU ======================================\n");
    printf("|                          Algoritmos de Ordenacao                        |\n");
    printf("|-------------------------------------------------------------------------|\n");
    printf("|  Digite 1 para o Insertion Sort                                         |\n");
    printf("|  Digite 2 para o Bubble Sort                                            |\n");
    printf("|  Digite 3 para o Quick Sort                                             |\n");
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
            printf("Array ordenado usando Bubble Sort.\n");
            break;

        case 3:
            printf("Array ordenado usando Quick Sort.\n");
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


