#include <stdio.h>
#include <stdlib.h>

int binarySearch(int array[11], int n, int key);

int main() {
    int array[11] = {32, 54, 74, 89, 1, 23, 90, 25, 64, 57, 83};
    int i, j, n, temp, key, mid;
    int flag = 0;

    n = sizeof(array) / sizeof(array[0]);

    for (i = 0; i < n - 1; i++) {

        flag = 0;

        for (j = 0; j < n - 1 - i; ++j) {

            if (array[j] > array[j + 1]) {

                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 1;

            }
        }

        if (flag == 0) {

            break;
        }
    }

    for (i = 0; i < n; i++) {

        printf(" %d ", array[i]);
    }

    printf("\n");

    printf("Please enter the element to search for: ");
    scanf("%d", &key);

    int result = binarySearch(array, n, key);

    if (result == -1) {

        printf("Element not found!!!");
    } 
    
    else {

        printf("Element found at index %d", result);
    }

    return 0;
}

int binarySearch(int array[11], int n, int key) {

    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right) {

        mid = (left + right) / 2;

        if (key == array[mid]) {

            return mid;

        } 
        
        else if (key < array[mid]) {

            right = mid - 1;
        } 
        
        else {

            left = mid + 1;
        }
    }

    return -1;
}
