/*
    Name: division.c
    Author: Muhammad Tayyab
    Date: 10-7-2024
    Description: Implements restoring division algorithem for uint32 numbers
*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Returns msb of num shifted to lsb position
#define GETMSB(num) (num & (1 << 31)) >> 31

void shiftLeft(uint32_t *reminder, uint32_t *quotient) {
    // Shifts reminder and quotient one place left as a single block
    
    // Store msb of quotient
    uint32_t quotient_msb = GETMSB(*quotient);

    // Shift reminder and quotient one place left
    *reminder = (*reminder) << 1;
    *quotient = (*quotient) << 1;
 
    // Place msb of quotient at lsb of reminder
    *reminder = (quotient_msb == 1) ? (*reminder | quotient_msb) : (*reminder & (~quotient_msb));
}

// TODO: Implement the restoring_division function
// It should take dividend and divisor as inputs and return quotient and remainder
void restoring_division(uint32_t dividend, uint32_t divisor, uint32_t *quotient, uint32_t *remainder) {
    // TODO: Implement the non-restoring division algorithm
    // Remember to handle division by zero
    // Returns quotient = remainder = 0 if divisor = 0

    // Q = quotient; A = remainder; M = Divisor

    int numBits;
    uint32_t remainder_msb;
    uint32_t remainder_copy;


    // Check division by zero case
    if (divisor == 0) {
        *quotient = 0;
        *remainder = 0;
        return ;
    };

    // Initialize values
    *quotient = dividend;
    *remainder = 0;
    numBits = 32;

    do {
        // Shift reminder quotient left
        shiftLeft(remainder, quotient);

        // Make a copy of reminder for restoring if required
        remainder_copy = *remainder;

        // Subtract divisor from reminder
        *remainder = (*remainder) - divisor;

        // Check msb of reminder
        remainder_msb = GETMSB(*remainder);
        if (remainder_msb == 1) {
            // Set lsb of quotient to 0
            *quotient = (*quotient) & (~( (uint32_t) 1 ));
            
            // Restore reminder
            *remainder = remainder_copy;
        }
        else {
            // Set lsb of quotient to 1
            *quotient = (*quotient) | (uint32_t) 1;
        }

        // Decrement counter
        numBits--;

    } while (numBits > 0 );         // Repeat until numBits becomes zero

    return ;
}

// TODO: Implement test cases
int run_test_case(uint32_t dividend, uint32_t divisor, int printOnPassFlag) {
    // TODO: Call restoring_division and verify the results

    // Returns 1 and prints error message if test results donot match correct results
    // Returns 0 if test results match correct results
    // If printOnPassFlag = 1, then it prints a pass message for correct test results
    
    // Variable to store results generated by test function
    uint32_t quotient_test, remainder_test;

    // Variable to store correct results;
    uint32_t quotient_correct, remainder_correct;

    // Call the test function
    restoring_division(dividend, divisor, &quotient_test, &remainder_test);

    // Generate correct results
    if (divisor == 0) {
        // Divide by zero case
        quotient_correct = 0;
        remainder_correct = 0;
    }
    else {
        // General case
        quotient_correct = dividend / divisor;
        remainder_correct = dividend % divisor;
    }

    // Check results
    if ((remainder_correct == remainder_test) && (quotient_correct == quotient_test)) {
        if (printOnPassFlag) printf("Test passed on %u / %u\n", dividend, divisor);
        return 0;
    }
    else {
        printf("Test failed on %u / %u\n", dividend, divisor);
        return 1;
    }    
}

int main(int argc, char *argv[]) {
    // If no arguments passed, runs random tests
    // If 2 arguments passed, runs test on those and returns status

    if (argc == 1) { 
        // If no arguments passed, perform random tests
        int numTestCases = 1e6;
        int error;

        for (int i=0; i<numTestCases; i++) {
            error = run_test_case(rand(), rand(), 0);
            if (error) break;
        }
        if (error == 0) {
            printf("Test passed on all %d random values.\n", numTestCases);
        }
        return 0;
    }
    else if (argc == 3) {
        // If 2 arguments passed, run test from them
        return run_test_case(atoi(argv[1]), atoi(argv[2]), 1);
    }
}
