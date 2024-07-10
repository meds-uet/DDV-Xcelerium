/*
 * File: division.c
 * Title: Evaluation 1
 * Author: Misbah Rani
 * Date: 2024-07-06
 * Description: This file contains the implementation of tasks of Restoring Divion Algorithm
 *              for the evaluation of basics of C language and usage of productivity tools.
 */



#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//Function to print the bits of decimal number give to it as input varibale
void PrintBits(int* a,int size){
    for(int i=0;i<size;i++){
        printf("%d",a[i]);
    }
    printf("\n");
}

//Calculating the number of bits 
int bits(int a){
    int count = 0;
    while(a!=0){
        a = a/2;
        count++;
    }
    return count;
}
//Converting binary number back to decimal
int BinaryConversion(int* a, int size){
    int num = 0;
    for(int i = size;i>=0;i--){
        if(a[i-1]  == 1){
            num = num + pow(2, i);
            i++;
        }
    }
    return num;
}
//Function converting decimal number to pointer using pointer function
int *DecimalConversion(int a, int size){
    int *binary;
    binary = (int*)malloc((size)*sizeof(int));
    int count = bits(a);
    int i = size - 1;
    if(a!=0){
        binary[i] = a%2;
        a = a/2;
        i--;
    }
    if(i>=0){
        binary[i] = 0;
        i--;
    }
    return binary;
}

int *TwosComplement(int a, int size){
    int *binary;
    binary = (int*)malloc((size)*sizeof(int));
    binary = DecimalConversion(a, size);
    for(int i = 0; i<size; i++){
        if(binary[i] == 0){
            binary[i] = 1;
        }
        else{
            binary[i] = 0;
        }
    }
    return binary;
}

void LeftShift(int* a,int* qq,int size){

    for(int j = 0;j<size-1;j++){
        a[j] = a[j+1];
    }
    a[size-1] = qq[0];
    for(int j = 0;j<size-1; j++){
        qq[j] = qq[j+1];
    }
}

void Addition(int* a, int* b, int* q, int size){
    int c = 0;
    for(int i=size;  i<1; i++){
        for(int j=size-1;j>=0;j--){
            if( a[j] == 1 ){
                if( b[j]==1 && c==1){
                    a[j] = 1; c = 1;
                }
                else if( b[j]==0 && c==0){
                    a[j] = 1; c = 0;
                }
                else if( b[j]==1 && c==0){
                    a[j] = 0; c =1 ;
                }
                else{
                    a[j] = 0; c = 1;
                }
            }
            else{
                if( b[j]==1 && c==1){
                    a[j] = 0; c = 1;
                }
                else if( b[j]==0 && c==0){
                    a[j] = 0; c = 0;
                }
                else if( b[j]==1 && c==0){
                    a[j] = 1; c = 0;
                }
                else{
                    a[j] = 1; c = 0;
                }
            }
        }   
    }
}

void RestoringDivision(int* a, int* b, int* q,int size){
    int temp[size];
    for(int i = 0; i<size; i++){
        LeftShift(a, q, size);
    }
    for(int j=0;j < size;j++){
                temp[j] = a[j];
            }
        Addition(a,b,q,size);
        if( a[0]==1 ){
            q[size-1] = 0;
            for(int j = 0;j<size;j++){
                a[j] = temp[j];
            }
        }
    if( a[0]==1 )
    a = temp;
}

int main(void){
    srand(time(NULL));
    unsigned int var_dividend = 10;
    unsigned int var_divisor = 7;
    int size = bits(var_dividend);
    int *dividend,*divisor,*divisor2,*acc;
    acc = (int*)malloc(size*sizeof(int));
    for(int i =0;i<size;i++){
        acc[i] = 0;
    }
    printf("Divisor in binary:  ");
    divisor = DecimalConversion(var_divisor, size);
    PrintBits(divisor, size);
    printf("\nIts 2's Complement: ");
    divisor2 = TwosComplement(var_divisor, size);
    PrintBits(divisor2, size);

    printf("\nDividend in Binary: ");
    dividend = DecimalConversion(var_dividend, size);
    PrintBits(dividend, size);
    printf("\n");
    printf("\nImplementing Restoring Algorithm\n");
    RestoringDivision(acc,divisor2,dividend,size);
    printf("\nQuotient = ");
    PrintBits(dividend,size);
    printf("which is equivalent to %d",var_dividend/var_divisor);
    printf("\nRemainder = ");
    PrintBits(acc,size);
    printf("which is equivalent to %d",var_dividend%var_divisor);

