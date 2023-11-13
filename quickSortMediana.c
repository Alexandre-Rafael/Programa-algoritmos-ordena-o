
void swapMediana(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int medianOfThree1(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[low] > arr[mid])
        swapMediana(&arr[low], &arr[mid]);
    if (arr[low] > arr[high])
        swapMediana(&arr[low], &arr[high]);
    if (arr[mid] > arr[high])
        swapMediana(&arr[mid], &arr[high]);

    return mid;
}

int partitionMediana(int arr[], int low, int high) {
    int pivotIndex = medianOfThree1(arr, low, high);
    int pivot = arr[pivotIndex];
    swapMediana(&arr[pivotIndex], &arr[low]);

    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
            swapMediana(&arr[i], &arr[j]);
        else
            break;
    }

    swapMediana(&arr[low], &arr[j]);
    return j;
}

void quickSort_versao3(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partitionMediana(arr, low, high);

        quickSort_versao3(arr, low, pivot - 1);
        quickSort_versao3(arr, pivot + 1, high);
    }
}
