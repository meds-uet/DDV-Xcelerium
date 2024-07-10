#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void writeToFile(int n, char s[], const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(file, "%s\n", s);
    fclose(file);
    printf("Case no. %d's result stored in : %s\n",n , filename);
}


void printBinary(__uint32_t value) {
    // Create a string to store the binary representation
    char binary[32];

    // Iterate over each bit and set the corresponding character in the string
    for (int i = 32; i >= 0; i--) {
        binary[32 - i] = (value & (1 << i)) ? '1' : '0';
    }

    // Print the binary representation
    printf("%s\n", binary);
}


//The function represents the restoring division algorithm
void restoringDivision(__uint32_t dividend, __uint32_t divisor, __uint32_t *Q, __int32_t *A) {

    int n = sizeof(dividend) * 8; // Number of bits in dividend (assuming 32-bit integers)
    *A = 0; // Initialize remainder (accumulator) to 0
    *Q = dividend; // Initialize quotient with the dividend
    __uint32_t M = divisor; 

    if (M == 0) {
        printf("We can't divide by zero");
        return;
    }

    int i = n;

    do {
        // Shift A and Q left if they are single unit
        *A = (*A << 1); //| (Q >> (n - 1));
        *Q = *Q << 1;

        // Subtract divisor from A
        *A = *A - M;
        char temp = (*A & (1 << n)) ? '1' : '0';
        // Check the most significant bit of A
        if (temp == '0') {
            // Set the least significant bit of Q to 1
            *Q |= 1;
            // Restore A by adding the divisor back
            *A = *A + M;
        } else {
            // Set the least significant bit of Q to 0
            *Q &= ~1;
        }
        i = i - 1;
    } while (i!=0);
    
    printf("Quotient : ");
    printBinary(*Q);
    printf("Remainder : ");
    printBinary(*Q);
}
void test(int n) {
    __uint32_t dividend, divisor;
    printf("Enter dividend: ");
    scanf("%d", &dividend);
    printf("Enter divisor: ");
    scanf("%d", &divisor);
    __uint32_t Q;
    __int32_t A;
    restoringDivision(dividend, divisor, &Q, &A);
    if ((dividend/divisor == Q) && (dividend%divisor == A)) {
        printf("Normal\n");
        writeToFile(n,"Normal","cases.txt");
    }
    else { 
        printf("Corner Case\n"); 
        writeToFile(n,"Corner","cases.txt");
    }

}
int main() {
    
    for (int i = 1; i<=3; i++) {
        printf("Case No. %d\n", i);
        test(i);
        
    }

    return 0;
}