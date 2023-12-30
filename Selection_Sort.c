// Selection Sort

#include<stdio.h>
#include<stdlib.h>

void selectionSort(int array[], int arraySize) {

    int i, index, j, min;

    for (i = 0; i < arraySize - 1; ++i){

        min = array[arraySize-1];
        index = arraySize - 1;

        for (j = i; j <= arraySize - 1; j++){
            
            if (array[j] < min) {

                min = array[j];
                index = j;
            }
        }

        if (index != i) {
            array[index] = array[i];
            array[i] = min;
            }

    }

    
}


void showArray(int array[], int arraysize) {

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
    printf("\n\nAfter Selection Sort Operation ");
    selectionSort(array, arraySize);
    showArray(array, arraySize);


    return 0;
}