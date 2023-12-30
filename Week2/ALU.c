#include <stdio.h>

int ALU(int a, int b, char operation) {
    switch (operation) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;  
    }
}

int main() {
    int operand1 = 10;
    int operand2 = 5;

    char operation = '+';
    int result = ALU(operand1, operand2, operation);

    printf("ALU Result: %d\n", result);

    return 0;
}
