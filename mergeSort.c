// Função para mesclar duas partes do array
void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *M = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++) {
        M[j] = arr[q + 1 + j];
    }

    int i = 0, j = 0;
    int k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }

    // Liberar a memória alocada
    free(L);
    free(M);
}

// Função principal do Merge Sort
void mergeSort(int arr[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}