#include <stdio.h>

int add(int a, int b) {
    int carry = 0, result = 0, mask = 1;
    for (int i = 0; i < 4; ++i) {
        int bitA = (a & (mask << i)) >> i;
        int bitB = (b & (mask << i)) >> i;
        int sum = bitA ^ bitB ^ carry;
        carry = (bitA & bitB) | ((bitA ^ bitB) & carry);
        result |= (sum << i);
    }
    return result;
}

int subtract(int a, int b) {
    return add(a, add(~b, 1));
}

int bitwiseAND(int a, int b) {
    return a & b;
}

int bitwiseOR(int a, int b) {
    return a | b;
}

int bitwiseXOR(int a, int b) {
    return a ^ b;
}

int bitwiseNOT(int a) {
    return ~a & 0x0F;
}

int multiply(int a, int b) {
    int result = 0;
    for (int i = 0; i < 4; ++i) {
        if ((b & (1 << i)) != 0) {
            result = add(result, a << i);
        }
    }
    return result;
}

int divide(int a, int b) {
    int quotient = 0;
    while (a >= b) {
        a = subtract(a, b);
        quotient = add(quotient, 1);
    }
    return quotient;
}

void displayBinary(int num) {
    int mask = 8; // 2^3
    while (mask > 0) {
        printf("%d", (num & mask) ? 1 : 0);
        mask >>= 1;
    }
    printf("\n");
}

int main() {
    int operand1, operand2;
    char operation;

    printf("Enter the first decimal number: ");
    scanf("%d", &operand1);

    printf("Enter the second decimal number: ");
    scanf("%d", &operand2);

    printf("Select operation (+, -, *, /, &, |, ^, ~): ");
    scanf(" %c", &operation);

    printf("\n");

    printf("Operand 1 (decimal): %d\n", operand1);
    printf("Operand 1 (binary): ");
    displayBinary(operand1);

    printf("\nOperand 2 (decimal): %d\n", operand2);
    printf("Operand 2 (binary): ");
    displayBinary(operand2);

    int result;

    switch (operation) {
        case '+':
            result = add(operand1, operand2);
            printf("Addition: ");
            break;

        case '-':
            result = subtract(operand1, operand2);
            printf("Subtraction: ");
            break;

        case '*':
            result = multiply(operand1, operand2);
            printf("Multiplication: ");
            break;

        case '/':
            result = divide(operand1, operand2);
            printf("Division: ");
            break;

        case '&':
            result = bitwiseAND(operand1, operand2);
            printf("Bitwise AND: ");
            break;

        case '|':
            result = bitwiseOR(operand1, operand2);
            printf("Bitwise OR: ");
            break;

        case '^':
            result = bitwiseXOR(operand1, operand2);
            printf("Bitwise XOR: ");
            break;

        case '~':
            result = bitwiseNOT(operand1);
            printf("Bitwise NOT (Operand 1): ");
            break;

        default:
            printf("Invalid operation\n");
            return 1;
    }

    displayBinary(result);

    return 0;
}
