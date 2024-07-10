
#  Implement a TCL script that:
# 1. Defines additional test cases
# 2. Runs the C program with these test cases
# 3. Collects and formats the results
# 4. Generates a summary report of passed/failed tests

# Name: test.tcl
# Author: Muhammad Tayyab
# Date: 10-7-2024
# Description: Tcl script for testing restoring division c program.

# Open file
set log [open "testlog.log" w]

# Define test cases
set NUMOFTESTS 5

set TESTVAL1(0) 0;     set TESTVAL2(0) 6
set TESTVAL1(1) 2;     set TESTVAL2(1) 0
set TESTVAL1(2) 999;   set TESTVAL2(2) 999
set TESTVAL1(3) 1000;  set TESTVAL2(3) 999
set TESTVAL1(4) 82;    set TESTVAL2(4) 90

# Run tests
for {set i 0} {$i<$NUMOFTESTS} {incr i} {
    set error [exec ./division $TESTVAL1($i) $TESTVAL2($i)]
    puts $log $error
}

puts "Tests run. Check log file.\n"
