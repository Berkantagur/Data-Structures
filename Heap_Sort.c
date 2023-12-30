#include <stdio.h>
#include <stdlib.h>

int heap_size;

void heapify(int array[], int n);
void build_heap(int array[], int n);
void heapsort(int array[], int n);
void showArray(int array[], int size);


void build_heap(int array[], int n){

    int i;
    heap_size = n-1;

    for (i = (n - 1) / 2; i >= 0; i--)
        heapify(array, i);

}

void heapsort(int array[], int n){

    int i, temp;
    build_heap(array, n);

    for (i = n - 1; i >= 1; i--){

        temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        heap_size--;
        heapify(array, 0);
    }
}

void heapify(int array[], int n){

    int left, right, largest, temp;

    left = 2 * n + 1;
    right = 2 * n + 2;

    if (left <= heap_size && array[left] > array[n])
        largest = left;
    else
        largest = n;

    if (right <= heap_size && array[right] > array[largest])
        largest = right;

    if (largest != n){

        temp = array[n];
        array[n] = array[largest];
        array[largest] = temp;
        heapify(array, largest);
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

    int i, n, array[20];

    printf("Please enter the number of elements you want: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++){

        printf("Please enter %d. index of element: ", i);
        scanf("%d", &array[i]);
    }

    printf("Before Heap Sorting ");
    showArray(array, n);
    heapsort(array, n);

    printf("\n\nSorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);

    return 0;
}