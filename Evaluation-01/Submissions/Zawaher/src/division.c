//author : Zawaher Bin Asim
//Date : 10 Jul 2024
//This file is the C code file of the restoring division  agorithm



#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// TODO: Implement the restoring_division function
// It should take dividend and divisor as inputs and return quotient and remainder
void restoring_division(uint32_t dividend, uint32_t divisor, uint32_t *quotient, uint32_t *remainder) {
    // TODO: Implement the non-restoring division algorithm
    // Remember to handle division by zero

    //Initializing the registers
    uint32_t Q = dividend ; // Q represents the quotient
    uint32_t M = divisor ; // M represents the divisor 
    uint32_t A = 0; // A represents the remainder
    uint32_t n = 32 ; // n represents the number of bits in the dividend

    if ((Q == 0)){
        printf("The dividend is zero\n");
        *quotient = 0;
        *remainder = Q;
    }
    else if ( M == 0){

        printf("The Divisor is zero\n");
        printf("The quotient and reaminder both are undefined\n");
        *quotient =  2147483647;  //Assiging the quotient and reaminder the max value of integer data type 
        *remainder = 2147483647;



    }
    else {

    
        do{
            uint32_t temp; 
            A = A<<1; //left  shifting A by 1
            Q = Q<<1; // left shifting Q by 1
            temp = A;
            A = (A - M) ; // subtracting divisor from remainder
            printf("The vale of A before checking %d \n", A);
            if ( (((A >> 31) & 1) == 0) ) // checking the MSB of A
            {
                Q = (Q | 1); //least significant bit of Q is set to 1
                printf("value of Q and A if MSB 0 is: %d %d\n",Q,A);
            }
            else{
                Q = (Q & 0); //least significant bit of Q is set to 0 
                A = temp;
                printf("value of Q and A if MSB 1 is: %d %d\n",Q,A);
            }

            n--; // decrementing the n by 1

        }while(n != 0);

        *remainder = A;
        *quotient = Q;

    }


}

// TODO: Implement test cases
void run_test_case(uint32_t dividend, uint32_t divisor) {
    // TODO: Call restoring_division and verify the results
    
    uint32_t quotient;
    uint32_t remainder;

    restoring_division(dividend,divisor,&quotient,&remainder);   
    
    uint32_t restoringQuotient = quotient;
    uint32_t restoringRemainder = remainder;

    uint32_t standardQuotient = dividend/divisor;
    uint32_t standardRemainder = dividend % divisor;

    

    
        // Check if the results match
        if ((restoringQuotient == standardQuotient) && (restoringRemainder == standardRemainder)) {
            printf("Test passed.\n\n");
            printf("The value of quotient is : %d \n", restoringQuotient);
            printf("The value of remainder is : %d \n ", restoringRemainder);

        } else {
            printf("Test failed.\n\n");
            printf("The value of quotient is : %d \n", restoringQuotient);
            printf("The value of remainder is : %d \n", restoringRemainder);
            printf("The value of acquotient is : %d \n", standardQuotient);
            printf("The value of acremainder is : %d \n", standardRemainder);
        }
    }


int main() {
    // TODO: Implement multiple test cases
    // Example:
    // run_test_case(20, 3);

    run_test_case(20,3);
    return 0;
}
