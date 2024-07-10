/*---------------------------
Author = Muhammad Mujtaba Rawn
Date = Jul 10 24
-----------------------------*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void intToBinary(int n, int bin[], int size);
void printBinary(int bin[], int size);

// Function to add binary numbers
void binaryAdd(int A[], int B[], int result[], int size);

// Function to subtract binary numbers
void binarySubtract(int A[], int B[], int result[], int size);

// Function to shift left
void shiftLeft(int bin[], int size);

void restoring_division(uint32_t dividend, uint32_t divisor, uint32_t *quotient, uint32_t *remainder) {
    if (divisor == 0) {
        printf("The divisor shouldn't be zero.\n");
        return;
    }

    int n = 32;
    // Registers
    int Q[n];
    int M[n];
    int A[n];
    int tempA[n];

    // Initializing A to 0
    for (int i = 0; i < n; i++) {
        A[i] = 0;
        Q[i] = 0;
        M[i] = 0;
        tempA[i] = 0;
    }

    // Converting int to binary
    intToBinary((int)dividend, Q, n);
    intToBinary((int)divisor, M, n);

    for (int i = 0; i < n; i++) {
        // Shift left AQ
        shiftLeft(A, n);
        shiftLeft(Q, n);
        A[0] = Q[n - 1];

        // A = A - M
        binarySubtract(A, M, tempA, n);
        for (int j = 0; j < n; j++) {
            A[j] = tempA[j];
        }

        if (A[n - 1] == 1) { // If A < 0
            Q[0] = 0;
            // Restore A = A + M
            binaryAdd(A, M, tempA, n);
            for (int j = 0; j < n; j++) {
                A[j] = tempA[j];
            }
        } else {
            Q[0] = 1;
        }
    }

    // Convert binary Q to integer quotient
    *quotient = 0;
    for (int i = 0; i < n; i++) {
        *quotient |= (Q[i] << i);
    }

    // Convert binary A to integer remainder
    *remainder = 0;
    for (int i = 0; i < n; i++) {
        *remainder |= (A[i] << i);
    }

    printf("Quotient: %u\n", *quotient);
    printf("Remainder: %u\n", *remainder);
}

void intToBinary(int n, int bin[], int size) {
    for (int i = 0; i < size; i++) {
        bin[i] = (n >> i) & 1;
    }
}

void printBinary(int bin[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", bin[i]);
    }
    printf("\n");
}

void shiftLeft(int bin[], int size) {
    for (int i = size - 1; i > 0; i--) {
        bin[i] = bin[i - 1];
    }
    bin[0] = 0;
}

void binaryAdd(int A[], int B[], int result[], int size) {
    int carry = 0;
    for (int i = 0; i < size; i++) {
        int sum = A[i] + B[i] + carry;
        result[i] = sum % 2;
        carry = sum / 2;
    }
}

void binarySubtract(int A[], int B[], int result[], int size) {
    int borrow = 0;
    for (int i = 0; i < size; i++) {
        int diff = A[i] - B[i] - borrow;
        if (diff < 0) {
            diff += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[i] = diff;
    }
}

void run_test_case(uint32_t dividend, uint32_t divisor) {
    uint32_t quotient;
    uint32_t remainder;
    restoring_division(dividend, divisor, &quotient, &remainder);
    printf("Dividend: %u, Divisor: %u -> Quotient: %u, Remainder: %u\n", dividend, divisor, quotient, remainder);
}

int main() {
    // Test cases
    run_test_case(20, 3);
    run_test_case(15, 4);
    run_test_case(50, 7);
    run_test_case(100, 10);
    return 0;
}
