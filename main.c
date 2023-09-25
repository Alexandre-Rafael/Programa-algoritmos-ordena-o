#include <stdio.h>
#include <stdlib.h>
#include "menuInsertionSort.c"
#include "menuBubbleSort.c"
#include <string.h>
#include <time.h>
#include <sys/stat.h>


void createDirectories() {
    _mkdir("Arquivos de Entrada", 0777);
    _mkdir("Arquivos de Saida", 0777);  
    _mkdir("Arquivos de Tempo", 0777);  

    _mkdir("Arquivos de Entrada/Crescente", 0777);    // Pasta para entrada crescente
    _mkdir("Arquivos de Entrada/Decrescente", 0777);  // Pasta para entrada decrescente
    _mkdir("Arquivos de Entrada/Random", 0777);      // Pasta para entrada random

    _mkdir("Arquivos de Saida/Crescente", 0777);      // Pasta para saída crescente
    _mkdir("Arquivos de Saida/Decrescente", 0777);    // Pasta para saída decrescente
    _mkdir("Arquivos de Saida/Random", 0777);       

    _mkdir("Arquivos de Tempo/Crescente", 0777);      
    _mkdir("Arquivos de Tempo/Decrescente", 0777);    
    _mkdir("Arquivos de Tempo/Random", 0777);        
}

int exibirMenu() { // Função para exibir o menu

    int opcao;

    printf("================================ MENU ======================================\n");
    printf("|                          Algoritmos de Ordenacao                        |\n");
    printf("|-------------------------------------------------------------------------|\n");
    printf("|  Digite 1 para o Insertion Sort                                         |\n");
    printf("|  Digite 2 para o Bubble Sort                                            |\n");
    printf("|  Digite 3 para o Selection Sort                                         |\n");
    printf("|  Digite 4 para o Shell Sort                                             |\n");
    printf("|  Digite 5 para Sair                                                     |\n");
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
            menuBubbleSort();
            break;

        case 3:
            printf("Array ordenado usando Selection Sort.\n");
            break;

        case 4:
            printf("Array ordenado usando Shell Sort.\n");
            break;


        case 5:
            exit(0);

        default:
            printf("Opcao invalida.\n");
            break;
    }

    return opcao;
}

int main() {

    int opcao;

    createDirectories();

    do {

        opcao = exibirMenu();

    } while (opcao != 4);

    scanf("%d", &opcao);

    return 0;
}

void saveArrayToFile(int arr[], int size, const char *prefix, const char *folder) {
    char filename[100];
    snprintf(filename, sizeof(filename), "Arquivos de Entrada\\%s\\entrada_%s_%d.txt", folder, prefix, size);
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

void saveSortedArrayToFile(int arr[], int size, const char *prefix, const char *folder) {
    char filename[100];
    snprintf(filename, sizeof(filename), "Arquivos de Saida\\%s\\saida_%s_%d.txt", folder, prefix, size);
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

void saveTimeToFile(double time_taken, const char *prefix, int size, const char *folder) {
    char filename[100];
    snprintf(filename, sizeof(filename), "Arquivos de Tempo\\%s\\tempo_%s_%d.txt", folder, prefix, size);
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "%.5lf segundos\n", time_taken);
        fclose(file);
    } else {
        printf("Não foi possível criar o arquivo: %s\n", filename);
    }
}

