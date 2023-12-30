#include<stdio.h>
#include <stdlib.h>

int main () {

    int array[] = {32,54,74,89,1,23,90,25,64,57,83,6};
    int i, j, n, temp;
    int flag = 0;

    n = sizeof(array) / sizeof(array[0]);

    for (i = 0; i < n-1; i++){

        flag = 0;

        for (j = 0; j < n-1-i; ++j){

            if (array[j] > array[j+1]){

                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = 1;

            }
        }

        if (flag == 0){

            break;

        }

    }

    for (i = 0; i < n; i++) {

        printf(" %d ", array[i]);

    }
    
    
    return 0;

}