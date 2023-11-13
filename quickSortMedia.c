void quickSortSwapMedia(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[low] > arr[mid])
        quickSortSwapMedia(&arr[low], &arr[mid]);
    if (arr[low] > arr[high])
        quickSortSwapMedia(&arr[low], &arr[high]);
    if (arr[mid] > arr[high])
        quickSortSwapMedia(&arr[mid], &arr[high]);

    return mid;
}

int partitionMedia(int arr[], int low, int high) {
    int pivotIndex = medianOfThree(arr, low, high);
    int pivot = arr[pivotIndex];
    quickSortSwapMedia(&arr[pivotIndex], &arr[low]);

    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
            quickSortSwapMedia(&arr[i], &arr[j]);
        else
            break;
    }

    quickSortSwapMedia(&arr[low], &arr[j]);
    return j;
}

void quickSort_versao2(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partitionMedia(arr, low, high);

        quickSort_versao2(arr, low, pivot - 1);
        quickSort_versao2(arr, pivot + 1, high);
    }
}