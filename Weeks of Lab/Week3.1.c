#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int *a, temp, n, j,b,min,i;
    printf("Please enter array size: ");
    scanf("%d", &n);
    a = (int*)malloc(n*sizeof(int));
    
    for( int i = 0; i < n;i++ ){
        printf("Please enter %d. array value: ", i+1);
        scanf("%d",&b );
        a[i]=b;
    }

    printf("Unsorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);    
    printf("\n");

    for( i = 0 ; i < n-1 ; i++){
        min = i;
        for(int j = i+1 ; j < n ; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        if (min != i){
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    }
    
    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}