// Author: Hamza
// Date: 10 July 2024
// Division.c for calculating dividend and divsior of two numbers


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// Implement the restoring_division function
void restoring_division(uint32_t dividend, uint32_t divisor, uint32_t *quotient, uint32_t *remainder) {
    // Step 1: Intializing the Registers
    uint32_t Q = dividend;   
    uint32_t M = divisor;    
    uint32_t A = 0;       
    // Calculating number of bits in the dividend and storing it in n
    uint32_t n = sizeof(dividend) * 8;  

    for (uint32_t i = 0; i < n; i++) {
        // Step-2: Shifting A and Q to left
        // First doing left shift of A, and then setting the LSB of A to MSB of Q 
        // For extracting the MSB we have to right shift it to n - 1 bit to take MSB to LSB bit, then extracting it using bitwise anding 1
        // Then setting this MSB to LSB of A using bitwise OR
        A = (A << 1) | ((Q >> (n - 1)) & 1);
        Q = Q << 1;


        // Step-3: Subtracting M from A
        uint32_t original_A = A;  // Storing original A for step-4 
        A = A - M;

        // Step-4: Checking the most significant bit of A
        // First left shifting 1 to n - 1 bits means to the MSB bit of A and then compare it with MSB
        if (A & (1 << (n - 1))) {  // If MSB of A is 1
            Q = Q & (~1);  // Setting LSB of Q to 0
            A = original_A;  // Restoring A to its original value
        } else {
            Q = Q | 1;  // Setting the LSB of Q to 1
        }
    }

    // Step-7: Extracting Quotient
    *quotient = Q;
    *remainder = A;
}

// Implement test cases
void run_test_case(uint32_t dividend, uint32_t divisor) {
    // Initializing unsigned 32 bit ints
    uint32_t quotient = 0;
    uint32_t remainder = 0;
    uint32_t testQuotient = 0;
    uint32_t testRemainder = 0;

    // Checking if the divisor is equal to 0
    if (divisor == 0){
        printf("Divisor can't be equal to 0\n");
        printf("---------------------------------------------\n");
        return;
    }

    // Calculating the quotient and remainder using operators
    testQuotient = dividend / divisor;
    testRemainder = dividend % divisor;

    restoring_division(dividend, divisor, &quotient, &remainder);

    // Comparing the function result with operator results
    if (testQuotient == quotient) {
        printf("Test Passed for Quotient\n");
        printf("The quotient of %u and %u is %u\n", dividend, divisor, quotient);
        printf("---------------------------------------------\n");
    } else {
        printf("Test failed for Quotient\n");
        printf("Expected %u, got %u\n", testQuotient, quotient);
        printf("---------------------------------------------\n");
    }

    if (testRemainder == remainder) {
        printf("Test Passed for Remainder\n");
        printf("The remainder of %u and %u is %u\n", dividend, divisor, remainder);
        printf("---------------------------------------------\n");
    } else {
        printf("Test failed for Remainder\n");
        printf("Expected %u, got %u\n", testRemainder, remainder);
        printf("---------------------------------------------\n");
    }
}

int main() {
    srand(time(NULL));
    // Since we have to compare them with TCL results so we will not use random
    // int testCount = 5; // Setting test cases to 5 by default
    // // Implementing multiple test cases using rand()
    // for(int i = 0; i < testCount; i++){
    //     run_test_case(rand() % 100, rand() % 100);
    // }
    // Test cases for comparing it in TCL and for edge cases
    run_test_case(4,5);
    run_test_case(50,2);
    run_test_case(10, 0);  // Test case for dividing by 0
    run_test_case(0, 5);   // Test case for dividend  0

    return 0;
}
