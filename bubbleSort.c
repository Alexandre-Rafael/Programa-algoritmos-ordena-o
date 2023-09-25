// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de ordenação Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Troque os elementos se estiverem fora de ordem
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
