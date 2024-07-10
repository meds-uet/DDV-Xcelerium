# Restoring Division Algorithm

This repository contains an implementation of the Restoring Division Algorithm in C. The Restoring Division Algorithm is a classic method for performing division of unsigned integers. This project includes the source code for the algorithm, as well as a set of test cases to validate its correctness.

## File Structure

- `division.c`: Contains the implementation of the Restoring Division Algorithm and the test cases.
- `division.h`: Header file with function declarations.
- `Makefile`: Build script for compiling the program.
- `README.md`: Project documentation.

## Getting Started

### Prerequisites

To build and run this project, you'll need:
- GCC (GNU Compiler Collection)
- Make

### Building the Project

Clone the repository to your local machine:
```bash
git clone https://github.com/meds-uet/DDV-Xcelerium.git
cd Evaluation-01
cd Submissions
cd Ibrahim
```
Build the project using the Makefile:

```bash
make
```
This will compile the source code and generate an executable named division

### Running the Program
To run the program, use the following command:

```bash
make run
```
This will execute the compiled program and run the test cases included in division.c.

### Cleaning Up
To remove the compiled files and clean the directory, use:

```bash
make clean
```
## Implementation Details

The core of this project is the `restoring_division` function, which performs division using the Restoring Division Algorithm. The function takes four parameters:

- **`dividend`**: The dividend (numerator) for the division.
- **`divisor`**: The divisor (denominator) for the division.
- **`quotient`**: Pointer to store the computed quotient.
- **`remainder`**: Pointer to store the computed remainder.

### Algorithm Steps

1. **`Initialize Registers`**: Set `Q` (quotient) to the dividend, `M` (divisor) to the divisor, `A` (remainder) to 0, and the bit counter `n` to the number of bits in the dividend.
2. **`Shift Left`**: Shift the combined value of `A` and `Q` left by 1 bit.
3. **`Subtract`**: Subtract `M` from `A`.
4. **`Check MSB`**: 
   - If the most significant bit (MSB) of `A` is 1, restore `A` and set the least significant bit (LSB) of `Q` to 0.
   - Otherwise, set the LSB of `Q` to 1.
5. **`Repeat`**: Repeat steps 2-4 until `n` reaches 0.
6. **`Result`**: The final values of `Q` and `A` represent the quotient and remainder, respectively.

