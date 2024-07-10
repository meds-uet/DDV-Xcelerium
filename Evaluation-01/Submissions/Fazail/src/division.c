#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

void restoring_division(uint32_t dividend, uint32_t divisor, uint32_t *quotient, uint32_t *remainder) {
    
    // Implement the non-restoring division algorithm

    // initialization
    uint32_t Q = dividend;              // dividend
    uint32_t M = divisor;               // Divisor
    uint32_t A = 0;                     // store partial and final Remainders 

    int n = sizeof(Q)*8;                // size of the integer 
    uint32_t restA = 0;                 // Restore value of A

    for(int i=n; i>0; i--){
        A = A << 1;
        
        // shifting the A with respect to msb of Q
        if ( (Q & 0x80000000) == 0x80000000 ){
            A = A | 0x00000001;
        }
        else if ( (Q & 0x80000000) == 0x00000000 )
        {
            A = A & 0xFFFFFFFE;
        }

        Q = Q << 1;

        restA = A;              // restore the previous value of A
        A = restA & 0xFFFFFFFF;

        A = A - M;

        if ((A & 0x80000000) == 0x80000000) {
            Q = Q & 0xFFFFFFFE;
            A = restA;
        }
        else {
            Q = Q | 0x00000001;
        }
    }

    *remainder = A;
    *quotient = Q;
}

// Implement test cases
void run_test_case(uint32_t dividend, uint32_t divisor) {
    
    // restoring_division and verify the results
    uint32_t quotient;
    uint32_t remainder;
    if (divisor != 0)
    {
        restoring_division(dividend, divisor,&quotient,&remainder);
    
        // Checker
        if ((quotient == (dividend / divisor)) && (remainder == (dividend % divisor)) ) {
            printf("SUCESS :) \n");
        }
        else {
            printf(" Not Pass :( \n");
            printf("rem %d qou %d div %d mod %d\n" , remainder, quotient, (dividend / divisor), (dividend % divisor));
        }
    }
    else {
        printf("Divisor should not to be zero. ;) \n");
    }
}

int main() {
    uint32_t dividend;
    uint32_t divisor;

    srand(time(NULL));

    // generating the random values
    dividend = rand();
    divisor = rand (); 

    run_test_case(dividend, divisor);

    //printf("%ld \n",sizeof(uint32_t)*8);
    return 0;
}
