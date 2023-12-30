#include <stdio.h>
#include <stdlib.h>

void mergesort (int array[], int lowb, int uppb);
void merge(int array[], int lower, int mid, int upper);
int temp[30];

int main() {

    int i, k, mid, j, upper, lower;
    int array[] = {81,42,93,24,65,6,37,18,9};

    const int MAX_SIZE = sizeof(array) / sizeof(array[0]);

    lower = 0;
    upper = MAX_SIZE -1;

    mergesort (array, lower, upper);

    printf("The sorted array is: \n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void mergesort (int array[], int lowb, int uppb) {

    int k;
    if (lowb < uppb) {
        k = (lowb + uppb) / 2; //midpoint
        mergesort(array, lowb, k);
        mergesort(array, k+1, uppb);
        merge(array, lowb, k, uppb);
    }

}


void merge (int array[], int lower, int mid, int upper){

    int i, j, k;
    i = lower;
    j = mid + 1;
    k = lower;

    while (i<=mid && j<=upper) {
        if (array[i] <= array[j]) {
            temp[k] = array[i];
            i++;
        }
        else {
            temp[k] = array[j];
            j++;
        }
        k++;
    }

       if (i>mid){
        while (j<=upper){
            temp[k] = array[j];
            j++;
            k++;
        }
    }

    else {

        while (i<=mid){
            temp[k] = array[i];
            i++;
            k++;
        }

        for(k =lower; k<= upper; k++){
            array[k] = temp[k];
        }
    }
    
}