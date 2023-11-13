// Função para realizar a troca entre dois elementos do array
void troca(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Função de particionamento do array
int partition(int arr[], int p, int r) {
    int x = arr[r];
    int i = p - 1;
    
    for (int j = p; j <= r - 1; j++) {
        if (arr[j] <= x) {
            i++;
            troca(arr, i, j);
        }
    }
    
    troca(arr, i + 1, r);
    return i + 1;
}

// Função principal do Quick Sort
void quickSort_versao1(int arr[], int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quickSort_versao1(arr, p, q - 1);
        quickSort_versao1(arr, q + 1, r);
    }
}