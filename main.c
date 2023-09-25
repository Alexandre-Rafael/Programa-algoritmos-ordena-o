#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include "menuInsertionSort.c"
#include "menuBubbleSort.c"




void createDirectories(const char *algorithmName) {
    char algorithmDir[100];

    // Diretório do algoritmo
    snprintf(algorithmDir, sizeof(algorithmDir), "%s", algorithmName);
    mkdir(algorithmDir);

    // Subdiretórios dentro do diretório do algoritmo
    snprintf(algorithmDir, sizeof(algorithmDir), "%s/Arquivos de Entrada", algorithmName);
    mkdir(algorithmDir);

    snprintf(algorithmDir, sizeof(algorithmDir), "%s/Arquivos de Saida", algorithmName);
    mkdir(algorithmDir);

    snprintf(algorithmDir, sizeof(algorithmDir), "%s/Arquivos de Tempo", algorithmName);
    mkdir(algorithmDir);

    // Subdiretórios dentro de cada diretório do algoritmo
    snprintf(algorithmDir, sizeof(algorithmDir), "%s/Arquivos de Entrada/Crescente", algorithmName);
    mkdir(algorithmDir);

    snprintf(algorithmDir, sizeof(algorithmDir), "%s/Arquivos de Entrada/Decrescente", algorithmName);
    mkdir(algorithmDir);

    snprintf(algorithmDir, sizeof(algorithmDir), "%s/Arquivos de Entrada/Random", algorithmName);
    mkdir(algorithmDir);

    snprintf(algorithmDir, sizeof(algorithmDir), "%s/Arquivos de Saida/Crescente", algorithmName);
    mkdir(algorithmDir);

    snprintf(algorithmDir, sizeof(algorithmDir), "%s/Arquivos de Saida/Decrescente", algorithmName);
    mkdir(algorithmDir);

    snprintf(algorithmDir, sizeof(algorithmDir), "%s/Arquivos de Saida/Random", algorithmName);
    mkdir(algorithmDir);

    snprintf(algorithmDir, sizeof(algorithmDir), "%s/Arquivos de Tempo/Crescente", algorithmName);
    mkdir(algorithmDir);

    snprintf(algorithmDir, sizeof(algorithmDir), "%s/Arquivos de Tempo/Decrescente", algorithmName);
    mkdir(algorithmDir);

    snprintf(algorithmDir, sizeof(algorithmDir), "%s/Arquivos de Tempo/Random", algorithmName);
    mkdir(algorithmDir);

    // Defina as permissões para 0777 após criar os diretórios
    chmod(algorithmDir, 0777);
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
            createDirectories("InsertionSort");
            menuInsertionSort();
            break;

        case 2:
            printf("Array ordenado usando Bubble Sort.\n");
            createDirectories("BubbleSort");
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

    do {

        opcao = exibirMenu();

    } while (opcao != 5);

    scanf("%d", &opcao);

    return 0;
}



// Função auxiliar para salvar um array em um arquivo
void saveArrayToFile(int arr[], int size, const char *prefix, const char *folder, const char *algorithmName) {
    char filename[100];
    snprintf(filename, sizeof(filename), "%s/Arquivos de Entrada/%s/entrada_%s_%d.txt", algorithmName, folder, prefix, size);
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

// Função auxiliar para salvar um array ordenado em um arquivo
void saveSortedArrayToFile(int arr[], int size, const char *prefix, const char *folder, const char *algorithmName) {
    char filename[100];
    snprintf(filename, sizeof(filename), "%s/Arquivos de Saida/%s/saida_%s_%d.txt", algorithmName, folder, prefix, size);
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

// Função auxiliar para salvar o tempo de execução em um arquivo
void saveTimeToFile(double time_taken, const char *prefix, int size, const char *folder, const char *algorithmName) {
    char filename[100];
    snprintf(filename, sizeof(filename), "%s/Arquivos de Tempo/%s/tempo_%s_%d.txt", algorithmName, folder, prefix, size);
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "%.5lf segundos\n", time_taken);
        fclose(file);
    } else {
        printf("Não foi possível criar o arquivo: %s\n", filename);
    }
}