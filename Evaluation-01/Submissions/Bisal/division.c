/*
 * ============================================================================
 * Filename:    sequential_divisor.c 
 * Description: File consists of Division Algorithm implmentation
 * Author:      Bisal Saeed
 * Date:        7/5/2024
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


//print the bits of int by masking each element after shift 
//as 00000....001000 after shift is 0 at MSB comes to LSB and after masking print it as first element
void printBits(int *num){
    for (int i = sizeof(int)*8 -1 ; i>=0;i-- ){
        printf("%d", (*num >> i) & 1);
    }
    printf("\n");
}

// Function to add A and M arrays 
void addBits(int *A, int *M, int n) {
    *A+=*M;
}

// Function to calculate the 2's complement of an array (M -> -M) 
void twosComplement(int *M, int n) {
    //toggle the bits of M 
    *M=~(*M);
    //add 1 to toggled M 
    int one=1;
    addBits(M, &one , n);
}

// Function to shift A and Q to left 
void shiftValue(int *A, int *Q, int n) {

    //let lsbQ value by default be 0 which can be replaced later 
    int lsbQ=0;
    int msbQ=(*Q & 1);
    //shift Q to left 
    *Q=(*Q << 1 ) | (lsbQ);
    //save lsb of A to check shift 
    printf("MSB of Q: %d\n",msbQ);
    //shift each element of A to left 
    *A=(*A << 1) | (msbQ);

}

// Function to perform Booth's multiplication algorithm using arrays and pointers
void division(int dividend, int divisor) {
    int n = sizeof(divisor)*8;//bit_length(multiplicand);
    //testcase conditions on divisor and multiplicand
    int flag_sign=0;
    if ((dividend<0 && divisor>0) || (dividend>0 && divisor<0)){
        //if one negative and positive number are multiplied so let flag_sign be 1
        flag_sign=1;
    }
    else if (((dividend<0)&&(divisor<0))|| ((dividend>0 && divisor>0))){
        //if two negative numbers or two positive numbers are multiplied so let flag_sign be 0
        flag_sign=0;
    }

    //take absolute values of multiplicand and ,divisor in case of negative numbers to simplify computation
    int A=0;
    int Q = (dividend<0)? -dividend : dividend;
    int M= (divisor<0)? -divisor : divisor;
    //initialize another int with same values as M -->used during compliment to avoid overwriting
    int negM = M;
    
    // Print initial values
    printf("A: ");
    printBits(&A);
    printf("Q: ");
    printBits(&Q);
    printf("M: ");
    printBits(&M);
    
    // Iterate through each bit of divisor or multiplicant using a while loop
    int count = n;
    while (count > 0) {
        
        shiftValue(&A,&Q,n);
        //print values after shift
        printf("A after shift : "); 
        printBits(&A);
        printf("Q after shift : "); 
        printBits(&Q);
        printf("M after shift : "); 
        printBits(&M);
        //store shifted value of A into a temporary A for restoring vaolue later 
        int tempA=A;
        //take
        twosComplement(&negM,n);
        addBits(&A,&negM,n);
        //print the value 
        printf("A after A<-A-M : "); 
        printBits(&A);
        
        // Check division algorithm conditions and perform operations on arrays
        int msbA=(A >> (n-1)) & 1 ;
        int lsbQ=Q;
        //0 CASE
        if (msbA == 1) {
            lsbQ=0;
            A=tempA;
        }
         //1 CASE
         else {
            lsbQ=1;
        }
        
        count--;
    }

    // Calculate the final quotient from concatenated A and Q arrays
    int quotient=Q;
    int remainder=A;
    
    //if neg * pos then just add negative sign to quotient
    if (flag_sign==1){
        quotient=-quotient;
        //stays same for negative numebers
        remainder=remainder;
    }
    else if (flag_sign==0){
        quotient=quotient;
        remainder=remainder;
    }

    else{
        quotient=0;
        remainder=0;
    }

    printf("Quotient is given as : %d\n", quotient);
    printf("Remainder is given as : %d\n", remainder);

}

int main() {
    int num1, num2;
    /*
    int num1=(rand()%100)+1;
    int num2=(rand()%100+1);
    printf("Enter the first number: %d",num1);
    printf("Enter the first number: %d",num2);
    */
    printf("Enter the dividend: ");
    scanf("%d", &num1);
    printf("Enter the divisor: ");
    scanf("%d", &num2);

    division(num1, num2);
    /* if (originalQuotient == quotient){
        printf("PASSED..");
    }
    if (originalRemainder == remainder){
        printf("PASSED..");
    }
    */
    return 0;
}
