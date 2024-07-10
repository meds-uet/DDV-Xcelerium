#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Restoring Division Function
void restoring_division(uint32_t dividend, uint32_t divisor, uint32_t *quotient, uint32_t *remainder) {
    uint32_t Q = dividend; // Quotient
    uint32_t M = divisor;  // Divisor
    uint32_t A = 0;        // Remainder
    uint32_t n = 32;       // Number of bits in the dividend

    if (Q == 0) {
        printf("The dividend is zero\n");
        *quotient = 0;
        *remainder = Q;
        return;
    }

    if (M == 0) {
        printf("The Divisor is zero\n");
        printf("The quotient and remainder both are undefined\n");
        *quotient = UINT32_MAX;  // Max value of unsigned 32-bit integer
        *remainder = UINT32_MAX;
        return;
    }

    for (uint32_t i = 0; i < n; i++) {
        // Shift A and Q left as a single unit
        A = (A << 1) | ((Q >> 31) & 1);
        Q = Q << 1;

        // Subtract divisor from A
        uint32_t temp = A;
        A = A - M;

        // Check the MSB of A
        if ((A & (1 << 31)) == 0) {  // MSB is 0
            Q = Q | 1; // Set LSB of Q to 1
        } else {       // MSB is 1
            A = temp;  // Restore A
        }
    }

    *quotient = Q;
    *remainder = A;
}

// Test cases
void run_test_case(uint32_t dividend, uint32_t divisor) {
    uint32_t quotient;
    uint32_t remainder;

    restoring_division(dividend, divisor, &quotient, &remainder);

    uint32_t restoringQuotient = quotient;
    uint32_t restoringRemainder = remainder;

    uint32_t standardQuotient = dividend / divisor;
    uint32_t standardRemainder = dividend % divisor;

    // Check if the results match
    if (restoringQuotient == standardQuotient && restoringRemainder == standardRemainder) {
        printf("Test passed.\n");
    } else {
        printf("Test failed.\n");
    }
    printf("Dividend: %u, Divisor: %u\n", dividend, divisor);
    printf("Restoring Quotient: %u, Restoring Remainder: %u\n", restoringQuotient, restoringRemainder);
    printf("Standard Quotient: %u, Standard Remainder: %u\n", standardQuotient, standardRemainder);
    printf("\n");
}

int main() {
    // Run multiple test cases
    run_test_case(20, 3);
    run_test_case(10, 2);
    run_test_case(100, 25);
    run_test_case(12345, 123);
    run_test_case(0, 10);  // Test case for zero dividend
    run_test_case(10, 0);  // Test case for zero divisor
    return 0;
}
