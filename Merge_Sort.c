#include <stdio.h>
#include <stdlib.h>
void merge (int array[], int left, int mid, int right);
void showArray(int *array, int arraysize);
void mergesort(int array[], int left, int right);

int main() {

    int n, arraySize;

    printf("Please enter array size: ");
    scanf("%d", &arraySize);

    const int MAX_SIZE = arraySize;

    if (arraySize < 1) {
        printf("Error! Size must be greater than zero.\n");
        return -1;
    }

    int *array = (int *)malloc(MAX_SIZE * sizeof(int));

    if (array == NULL) {

        printf("Memory allocation failed.\n");
        return 1;
    }

    for(n = 0; n < arraySize; n++){

        printf("%d. index of array's value: ", n);
        scanf("%d", &array[n]);

    }

    showArray(array, arraySize);
    printf("\n\nAfter Merge Sort Operation ");

    mergesort(array, 0, arraySize - 1);
    printf("The sorted array is: \n");
    showArray(array, arraySize);

    free(array);

    return 0;
}


void mergesort(int array[], int left, int right) {
    
    int mid;

    if (left < right) {

        mid = (left + right) / 2;
        mergesort(array, left, mid);
        mergesort(array, mid+1, right);
        merge(array, left, mid, right);
    }
}

void merge (int array[], int left, int mid, int right) {

    int i, j, l = 0;
    int *tempArr = (int *)malloc((right - left + 1) * sizeof(int));

    if (tempArr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (i = left, j = mid + 1; (i <= mid) && (j <= right);) {

        if (array[i] < array[j]) {

            tempArr[l] = array[i];
            i++;
        }
        else {
            tempArr[l] = array[j];
            j++;
        }
        l++;
    }

    while (i<=mid) {

        tempArr[l] = array[i];
        i++;
        l++;
    }

    while (j<=right) {

        tempArr[l] = array[j];
        j++;
        l++;
    }

    for (i = left, l = 0; i <= right; i++, l++) {

        array[i] = tempArr[l];
    }

    free(tempArr);

}

void showArray(int *array, int arraysize) {

    int j;
    printf("Your Array:\n");
    for (j=0; j<arraysize; j++) {

        printf("%d\t", array[j]);
    }
}
