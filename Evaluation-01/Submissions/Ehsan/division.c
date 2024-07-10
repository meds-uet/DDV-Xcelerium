//Name : M.Ehsan
//file:restoring division algorithm
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


// TODO: Implement the restoring_division function
// It should take dividend and divisor as inputs and return quotient and remainder
void restoring_division(uint32_t dividend, uint32_t divisor, uint32_t *quotient, uint32_t *remainder) {
    //handle division by zero
    if (divisor == 0) {
        printf("Not_divisible_by_zero\n");
        return;
    }

    uint32_t A = 0;      
    uint32_t Q = dividend;  
    uint32_t M = divisor;
    int N = 8 * sizeof(uint32_t);
    uint64_t temp = (uint64_t)A ;
    uint64_t QA_combined = temp << 32 | Q; 
    uint32_t msb_A;

    for (int i = 0; i < N; i++) {

        QA_combined = (uint64_t)A << 32 ;
        QA_combined = QA_combined| Q;
        QA_combined = QA_combined << 1;
        A = (QA_combined >> 32) & 0xffffffff;
        Q = QA_combined & 0xffffffff;
        A = A + ((~M) + 1);
        msb_A = (A >> 31) & 1;
        if (msb_A == 1) {
            Q = Q & 0xFFFFFFFE;
            A = A + M;
        } else if (msb_A == 0) {
            Q = Q | 0x00000001;
        }
    }

    *quotient = Q;
    *remainder = A;

}

// TODO: Implement test cases
void run_test_case(uint32_t dividend, uint32_t divisor) {
    uint32_t quotient;
    uint32_t remainder;
    //testing using random numbers 
    uint32_t temp_quotient, temp_remainder;
    temp_quotient = dividend / divisor;
    temp_remainder = dividend % divisor;

    restoring_division(dividend, divisor, &quotient, &remainder);
    if (temp_quotient==quotient && temp_remainder==remainder) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    } 

//testing using test cases
//restoring_division(dividend, divisor, &quotient, &remainder);
//printf("Quotient : %d  remainder : %d", quotient,remainder);
    
} 

int main() {
//testing using random numbers
    srand(time(NULL));
    int i = 0;
    uint32_t temp_dividend, temp_divisor;
    while (i < 100) {
    temp_dividend = rand();
    temp_divisor = rand();
        run_test_case(temp_dividend, temp_divisor);
        i++;
    }    
    return 0;

//testing with test cases
//run_test_case(1,1);
//run_test_case(2,2);
//run_test_case(4,2);
//run_test_case(7,2);
}
