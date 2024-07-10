# TODO: Implement a TCL script that:
# 1. Defines additional test cases
# 2. Runs the C program with these test cases
# 3. Collects and formats the results
# 4. Generates a summary report of passed/failed tests

puts "TODO: Implement advanced testing script"

set LOWER 0
set UPPER 1000
set outfile [open 'test.txt' w]

#set output [exec ./run]

puts "Input number of tests: "
gets stdin count

set nextLine $count
puts $outfile $nextLine

for {set i 0} {$i < $count} {incr i} {
    set dividend [expr {(int(int(rand()) % ($UPPER - $LOWER +1)) + $LOWER)}]
    set divisor [expr {(int(int(rand()) % ($UPPER - $dividend +1)) + $dividend)}]

    set output [exec ./myprogram $dividend $divisor]

    puts $output
    }