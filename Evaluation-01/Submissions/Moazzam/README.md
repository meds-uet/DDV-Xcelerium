# Restoring Division Algorithm Project

## Project Structure
- `Sample_files/division.c`: Implement the restoring division algorithm and basic tests
- `Sample_files/Makefile`: Create build automation
- `Sample_files/test.tcl`: Develop TCL script for advanced testing

## Run C file with Make 
1. Write the command:`make` to make the division.c file
2. Run the excutable file myprogram by using command `./myprogram  args1 dividend divisor` <br>
   Where:<br>
    if `args1 = 1` (for give your own input and take answer.) <br>
    if `args1 = 2` (for test on random inputs.) <br>
    if `args1 = any other number` (run myprogram on given input arguments.) <br>
    `Note` Give all 3 things to run program **otherwise** code will show *Segmentation fault (core dumped)*
3. 
4. To clean the outputs to make file run on cammand: `make clean`

## Run C file with tcl 
1. Run the command on terminal:`tclsh test.tcl`
2. it will generate random number and test the code.