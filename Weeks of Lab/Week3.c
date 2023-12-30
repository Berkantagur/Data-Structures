#include <stdio.h>
#include <stdlib.h>

int main() {

    int found = 0, n, k, temp, j;
    int a[15];
    printf("Please enter array size: ");
    scanf("%d", &n);
    
    for( int i = 0; i < n; i++ ){
        printf("Please enter %d. array value: ", i+1);
        scanf("%d", &a );
        a[i] = k;
    }

    /*
    for( int i = 0; i < n;i++ )
        {
            for( int j = i + 1; j < n; j++ )
            {
                if(array[i] > array[j])
                {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
                
            }

            printf(" %d ", array[i]);
        }

    printf("\n");

    for( int i = 0; i < n;i++ )
        {
            for( int j = i + 1 ; j < n;j++ )
            {
                if(array[i] < array[j])
                {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
                
            }

            printf(" %d ", array[i]);
        }
    */
   
    for (int i = 0; i < n; i++){

        temp = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > temp){

            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j + 1] = temp;
    }
    
    printf("Sorted array: ");

    for (int i = 0; i < n; i++){

        printf("%d ", a[i]);

    }

        return 0;
    }
