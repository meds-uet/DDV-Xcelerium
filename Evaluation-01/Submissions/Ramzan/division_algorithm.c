#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Function to perform restoring division
void restoring_division(uint32_t dividend, uint32_t divisor, uint32_t *quotient, uint32_t *remainder) {
    if (divisor == 0) {
        printf("Division by zero is not allowed.\n");
        *quotient = 0;
        *remainder = dividend;
        return;
    }

    uint32_t A = 0;
    uint32_t Q = dividend;
    uint32_t M = divisor;
    int n = 32; // Number of bits in the dividend

    for (int i = 0; i < n; i++) {
        // Left shift A and Q as a single unit
        A = (A << 1) | (Q >> 31);
        Q = Q << 1;

        // Subtract M from A
        A = A - M;

        // Check the most significant bit of A
        if ((A & 0x80000000) == 0) {
            Q = Q | 1;
        } else {
            A = A + M; // Restore A
        }
    }

    *quotient = Q;
    *remainder = A;
}

// Function to run a test case
void run_test_case(uint32_t dividend, uint32_t divisor) {
    uint32_t quotient, remainder;
    restoring_division(dividend, divisor, &quotient, &remainder);

    if (divisor != 0) {
        printf("Dividend: %u, Divisor: %u, Quotient: %u, Remainder: %u\n", dividend, divisor, quotient, remainder);
        // Verify the results
        if (dividend / divisor == quotient && dividend % divisor == remainder) {
            printf("Test passed!\n");
        } else {
            printf("Test failed!\n");
        }
    } else {
        printf("Division by zero test: Quotient: %u, Remainder: %u\n", quotient, remainder);
    }
}

int main() {
    uint32_t dividend, divisor;

    printf("Enter a dividend number: ");
    scanf("%u", &dividend);
    printf("Enter a divisor number: ");
    scanf("%u", &divisor);

    uint32_t quotient, remainder;
    restoring_division(dividend, divisor, &quotient, &remainder);
    printf("The division of %u by %u gives quotient %u and remainder %u\n", dividend, divisor, quotient, remainder);

    // Running some test cases
    run_test_case(10, 3);
    run_test_case(20, 4);
    run_test_case(100, 10);
    run_test_case(15, 0); // Division by zero test

    return 0;
}
