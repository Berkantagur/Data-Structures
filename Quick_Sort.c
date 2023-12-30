#include <stdio.h>
#include <stdlib.h>
void showArray(int array[], int size);
void quicksort(int array[], int left, int right){
    
    int k, j, pivot, temp;

    k = left;
    j = right;
    pivot = array[(left + right) / 2];
    
    do {
        
        while((array[k] < pivot) && (k < right))
            k++;
        while((array[j] > pivot) && (j > left))
            j--;    
        
        if(k <= j){
            temp = array[k];
            array[k] = array[j];
            array[j] = temp;
            k++;
            j--;
        }
    }while(k <= j);

    if(left < j)
        quicksort(array, left, j);
    
    if(k < right)
        quicksort(array, k, right);
}

void showArray(int array[], int size) {

    int z;

    printf("Your Array:\n");
    for (z=0; z<size; z++) {

        printf("%d\t", array[z]);
    }
}

int main(){

    int size;

    printf("Please enter array size: ");
    scanf("%d", &size);

    int array[size];

    for(int i=0;i<size;i++){
        printf("%d. index of array's value: ", i);
        scanf("%d", &array[i]);
    }

    printf("\nBefore Quick Sort Operation ");
    showArray(array, size);
    quicksort(array, 0, size - 1);
    printf("\n\nAfter Quick Sort Operation ");
    showArray(array, size);

    return 0;
}