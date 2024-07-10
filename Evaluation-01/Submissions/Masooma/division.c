// Description: Xcelerium Training Lab 1 --C language
// Author: Masooma Zia
// Date: 02-07-2024
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
// TODO: Implement the restoring_division function
// It should take dividend and divisor as inputs and return quotient and remainder
void restoring_division(uint32_t dividend, uint32_t divisor) {
    signed int A=0;
    
    int n=32;
    while (n!=0){
        u_int64_t combined = 0;
        combined = combined | A;
        printf("A:%d\n",A);
        printf("Q:%d\n",dividend);
        printf("Combined before shifting%d\n",combined);
        combined = combined << n;
        u_int64_t final = combined | dividend;
        u_int64_t shift = final << 1;
        u_int64_t var_0 = 0;
        var_0=(~var_0)<<32;
        var_0=(shift & var_0)>>32;
        A =  var_0;
        u_int64_t var_1 = 0;
        var_1=(~var_1)>>32;
        var_1=shift & var_1;
        dividend=var_1;

        printf("new A %d\n",A);
        printf("new Q%d\n",dividend);
        
        //int *conv = inttobin(combined,64);
        //conv = inttobin(A,32);
        printf("Combined %ld\n",combined);
        printf("Final %ld\n",final);
        printf("Shift %ld\n",shift);
        signed int previous_A=A;
        A = A-divisor;
        printf("A after Subtraction%d\n",A);
        int check=1<<31;
        printf("Check %d\n",check);
        int msb_bit;
        if (check && A){
            msb_bit=1;
        }
        else{
            msb_bit=0;
        }
        if (msb_bit==0){
            int MSB_one=1<<31;
            printf("Zero");
            printf("%d\n",MSB_one);
            dividend = MSB_one | dividend;
            printf("Dividend after MSB set to 1%d\n",dividend);
        }
        else {
            
            int zero=0;
            zero=~zero;
            int MSB_zero=zero>>1;
            dividend=MSB_zero & dividend;
            A=previous_A;
            printf("One");
            printf("Dividend after MSB set to 0%d\n",dividend);
        }
        n--;
        
    }
    printf("Dividend is:%d\n",dividend);
    printf("REmainder is:%d\n",A);


    
    
}

// TODO: Implement test cases
void run_test_case(uint32_t dividend, uint32_t divisor) {
    // TODO: Call restoring_division and verify the results
}

int main() {
    
    // run_test_case(20, 3);
    restoring_division(4,2);
    return 0;
}
