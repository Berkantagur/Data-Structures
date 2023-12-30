#include <stdio.h>

int main(){

    int op, input;

    printf("Please enter a number: ");
    scanf("%d", &input);

    if (input < 0){
        printf("Please enter a positive number.\n");
        return 0;
    }
    
    op = input % 7;

    //Today is Sunday.

    switch (op) {

        case 0:
            printf("After day %d, it's Sunday\n", input);
            break;
        case 1:
            printf("After day %d, it's Monday\n", input);
            break;
        case 2:
            printf("After day %d, it's Tuesday\n", input);
            break;
        case 3:
            printf("After day %d, it's Wednesday\n", input);
            break;
        case 4:
            printf("After day %d, it's Thursday", input);
            break;
        case 5:
            printf("After day %d, it's Friday", input);
            break;
        case 6:
            printf("After day %d, it's Saturday", input);
            break;
    }

    return 0;
}