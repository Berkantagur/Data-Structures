// Insertion Sort

#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *array, int arraySize) {

    int m, n, key;

    for (m=1; m<arraySize; m++) {

        key = array[m];

        for (n=m-1; n>=0 && key<= array[n]; n--) {

            array[n+1] = array[n];

        }
        array[n+1] = key;
    }
}


void showArray(int *array, int arraysize) {

    int j;
    printf("Your Array:\n");
    for (j=0; j<arraysize; j++) {

        printf("%d\t", array[j]);
    }
}

int main() {

    int i, arraySize;

    printf("Please enter array size between 1 to 15: ");
    scanf("%d", &arraySize);

    int array[15];

    for(i=0; i<arraySize; i++){

        printf("%d. index of array's value: ", i);
        scanf("%d", &array[i]);

    }

    showArray(array, arraySize);
    printf("\n\nAfter Insertion Sort Operation ");
    insertionSort(array, arraySize);
    showArray(array, arraySize);
    


    return 0;
}