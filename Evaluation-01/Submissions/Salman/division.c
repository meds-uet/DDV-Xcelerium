#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define UPPER 1000
#define LOWER 1

// Implementing function to count number of bits of a number
int bit_counter(uint32_t num){
    int count = 0;
    while (num)
        {
            num = num/2;
            count++;
        }
    return count;
}

// TODO: Implement the restoring_division function
// It should take dividend and divisor as inputs and return quotient and remainder
void restoring_division(uint32_t dividend, uint32_t divisor, uint32_t *quotient, uint32_t *remainder) {
    // TODO: Implement the non-restoring division algorithm
    // Remember to handle division by zero

    if (divisor == 0)
        {
            printf("Division by zero error!\n");
            exit(0);
        }

    // step 1: initialization
    uint32_t Q = dividend;
    uint32_t M = divisor;
    uint32_t A = 0;
    int n = bit_counter(dividend);
    int bits = n;

    while (n)
        {
            // step 2: shifting AQ to left as single unit
            // combining AQ into single unit of 64 bits
            uint64_t unit_AQ = ( ( ((uint64_t)A) << bits) | Q);                // single unit

            // shifting AQ to left by 1
            unit_AQ = (unit_AQ << 1);                                                        // single unit left shift by 1

            // separating unit_AQ into A and Q
            A = ((unit_AQ >> bits) & 0x0000FFFF);
            Q = ( (unit_AQ << (64-bits)) >> (64-bits) );

            // step 3: subtracting M from A
            uint32_t prev_A = A;
            A = A - M;

            // step 4: checking MSB of A
            if ( A & 0x80000000 )           // if MSB of A is 1
                {
                    Q = ( Q & 0xFFFFFFFE ); // LSB set to 0
                    A = prev_A;             // A restored to its previous value
                }
            else                            // if MSB of A is 0
                {
                    Q = ( Q | 0x00000001 ); // LSB set to 1
                    A = A;                  // A keeps its current value
                }
            // step 5: decrementing n
            n--;
        }
    // Step 7: Quotient = Q, Remained = A as answer
    *quotient = Q;
    *remainder = A;

    return;
}

// TODO: Implement test cases
void run_test_case(uint32_t dividend, uint32_t divisor,int* count_fails) {
    // TODO: Call restoring_division and verify the results
    uint32_t quotient;
    uint32_t remainder;

    restoring_division(dividend,divisor,&quotient,&remainder);
    if ( ((dividend/divisor) == quotient) & ((dividend%divisor) == remainder) )
        {
            printf("Test passed!\n");
        }
    else
        {
            printf("Test failed!\n, dividend = %d; divisor = %d, quotient = %d, remainder = %d",dividend,divisor,quotient,remainder);
            count_fails++;
        }
}

int main() {
    // TODO: Implement multiple test cases
    // Example:
    uint32_t dividend = 11;
    uint32_t divisor = 3;
    uint32_t quotient = 0;
    uint32_t remainder = 0;
    int test_count,i;
    int fail_counter = 0;

    restoring_division(dividend,divisor,&quotient,&remainder);
    printf("\nQuotient = %d; Remainder = %d\n",quotient,remainder);

    printf("\nInput number of tests: ");
    scanf("%d",&test_count);


    // testing for random cases except 0
    for (i=0; i<test_count; i++)
        {
            dividend = ( rand() % (UPPER-LOWER+1)) + LOWER;             // dividend range from lower to upper
            divisor  = ( rand() % (dividend - LOWER + 1)) + LOWER;      // divisor range from lower to value of dividend generated
            printf("Test #%d: ",i+1);
            run_test_case(dividend,divisor,&fail_counter);
        }
    // tests result
    if (fail_counter > 0)
        {
            printf("Total tests failed: %d\n",fail_counter);
        }
    else
        {
            printf("All tests passed!\n");
        }

    // to test division by zero
//    restoring_division(10,0,&quotient,&remainder);

    return 0;
}
