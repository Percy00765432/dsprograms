#include <stdio.h>

void printBinary(int a) {
    if (a > 0) {
        printBinary(a / 2);
        printf("%d", a % 2);
    }
}

int main() {
    int a;
    printf("Enter a decimal number: ");
    scanf("%d", &a);
    
    if (a == 0) {
        printf("Binary: 0\n");
    } else {
        printf("Binary: ");
        printBinary(a);
        printf("\n");
    }

    return 0;
}