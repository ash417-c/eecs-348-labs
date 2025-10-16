#include <stdio.h>
#include "isOdd.h"

int main(){
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("%d is %s", number, isOdd(number) ? "odd" : "even");

    return 0;
}