# TODO: Implement a TCL script that:
# 1. Defines additional test cases
# 2. Runs the C program with these test cases
# 3. Collects and formats the results
# 4. Generates a summary report of passed/failed tests

puts "TODO: Implement advanced testing script"

set fp [open "test_case.txt" r]
set file_data [read $fp]
close $fp

set data [split $file_data "\n"]
lmap x $data {lindex $x 0}
puts "$x "
foreach line $data {
    puts $line
}

