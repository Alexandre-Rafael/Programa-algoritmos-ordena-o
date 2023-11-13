void swapRandom(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int randomPivo(int low, int high) {
    return low + rand() % (high - low + 1);
}

int partitionRandom(int arr[], int low, int high) {
    int pivotIndex = randomPivo(low, high);
    int pivot = arr[pivotIndex];
    swapRandom(&arr[pivotIndex], &arr[low]);

    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
            swapRandom(&arr[i], &arr[j]);
        else
            break;
    }

    swapRandom(&arr[low], &arr[j]);
    return j;
}

void quickSort_versao4(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partitionRandom(arr, low, high);

        quickSort_versao4(arr, low, pivot - 1);
        quickSort_versao4(arr, pivot + 1, high);
    }
}
