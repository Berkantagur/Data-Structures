// Bubble Sort

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int array[], int size) {

    int move, k, temp;

    for (move = 0; move < size -1; move++) {
        
        for (k = 0; k < size - 1 - move; k++) {

            if (array[k] > array[k + 1]) {

                temp = array[k];
                array[k] = array[k + 1];
                array[k + 1] = temp;
            }
        }
    }

}

void showArray(int array[], int size) {

    int z;

    printf("Your Array:\n");
    for (z=0; z<size; z++) {

        printf("%d\t", array[z]);
    }
}

int main(){

    int size, i, j;
    
    printf("Please enter array size: ");
    scanf("%d", &size);

    int* array = (int*)malloc(size * sizeof(int));
    
    if (array == NULL) {

        printf("Memory allocation error!\n");
        return 1;
    }

    for (i = 0; i < size; i++) {

        printf("%d. index of array's value: ", i);
        scanf("%d", &array[i]);
    }

    printf("Before Bubble Sorting ");
    showArray(array, size);
    bubbleSort(array, size);
    printf("\nAfter Bubble Sorting ");
    showArray(array, size);
    
    free (array);
    return 0;
}