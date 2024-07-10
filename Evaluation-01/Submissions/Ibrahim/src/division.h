#ifndef DIVISION_H
#define DIVISION_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// Define the number of bits in a uint32_t integer
#define BITS_IN_UINT32 32

/*
 * Function: restoring_division
 * Implements the restoring division algorithm.
 */
void restoring_division(uint32_t dividend, uint32_t divisor, uint32_t *quotient, uint32_t *remainder);

/*
  Function: run_test_case
  Runs a test case to verify the restoring division algorithm.
 */
void run_test_case(uint32_t dividend, uint32_t divisor);

#endif // DIVISION_H
