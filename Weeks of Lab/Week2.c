#include <stdio.h>

int main() {

    int found = 0, n, k, temp, j, a;
    int array[15];
    printf("Please enter array size: ");
    scanf("%d", &n);
    
    for( int i = 0; i < n; i++ ){
        printf("Please enter %d. array value: ", i+1);
        scanf("%d", &a );
        array[i] = k;
    }


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
    
        return 0;
    }
