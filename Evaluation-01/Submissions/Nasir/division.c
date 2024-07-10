#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// Function to perform restoring division
void restoring_division(uint32_t dividend, uint32_t divisor, uint32_t *quotient, uint32_t *remainder) {
    if (divisor == 0) {
        printf("Error: Division by zero.\n");
        *quotient = 0;
        *remainder = 0;
        return;
    }

    uint32_t bitLength = sizeof(uint32_t) * 8;

    *remainder = 0;
    *quotient = 0;

    for (int i = 0; i < bitLength; i++) {
        // Shift left remainder and the next bit of the dividend
        *remainder = (*remainder << 1) | ((dividend >> (bitLength - 1 - i)) & 1);

        // Subtract divisor from the remainder
        *remainder -= divisor;

        // If the remainder is negative, restore the previous remainder and set quotient bit to 0
        if ((int32_t)(*remainder) < 0) {
            *remainder += divisor;
            *quotient <<= 1;
        } else {
            *quotient = (*quotient << 1) | 1;
        }
    }
}

// Function to run a test case and compare results
void run_test_case(uint32_t dividend, uint32_t divisor) {
    uint32_t quotient = 0;
    uint32_t remainder = 0;
    restoring_division(dividend, divisor, &quotient, &remainder);

    uint32_t expected_quotient = dividend / divisor;
    uint32_t expected_remainder = dividend % divisor;

    printf("Test Case:\n");
    printf("Dividend: %u, Divisor: %u\n", dividend, divisor);
    printf("Expected Quotient: %u, Expected Remainder: %u\n", expected_quotient, expected_remainder);
    printf("Actual Quotient: %u, Actual Remainder: %u\n", quotient, remainder);

    if (quotient == expected_quotient && remainder == expected_remainder) {
        printf("Test passed.\n");
    } else {
        printf("Test failed.\n");
    }

    printf("\n");
}


void tests(uint32_t dividend, uint32_t divisor, const char* filename) {
    // TODO: Write student data to a text file
    FILE *file = fopen(filename, "a");
    if(file == NULL){
        printf("File not opened");
        exit(1);
    }
    else {
        fprintf(file, "%u ", dividend);
        fprintf(file, "%u\n", divisor);
    }
    fclose(file);
}

int main() {
    // Generate and run random test cases
    // run_test_case(20, 3);
    // run_test_case(50, 7);
    // run_test_case(100, 10);
    // run_test_case(0, 1); // Edge case: Dividend is zero
    // run_test_case(1, 1); // Edge case: Dividend and divisor are both one
    // run_test_case(10, 2); // Simple division
    // run_test_case(UINT32_MAX, UINT32_MAX); // Both dividend and divisor are the maximum 32-bit value
    srand(time(NULL));
    const char * filename = "text.txt";
    for (int i = 0; i < 10; i++)
    {
        uint32_t dividend = rand() % 10000;
        uint32_t divisor = rand() % 100 + 1;  // Ensure divisor is non-zero
        run_test_case(dividend, divisor);
        tests(dividend, divisor, filename);
    }

    return 0;
}