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
            if (b != 0) {
                return a / b;
            } else {
                printf("Error: Division by zero\n");
                return 0;  // You might want to handle this differently based on your requirements
            }
        default:
            printf("Error: Undefined operation\n");
            return 0;
    }
}

int main() {
    int operand1, operand2;
    char operation;

    printf("Enter operand1: ");
    scanf("%d", &operand1);

    printf("Enter operand2: ");
    scanf("%d", &operand2);

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);  // Note the space before %c to consume any whitespace characters

    int result = ALU(operand1, operand2, operation);

    printf("ALU Result: %d\n", result);

    return 0;
}

