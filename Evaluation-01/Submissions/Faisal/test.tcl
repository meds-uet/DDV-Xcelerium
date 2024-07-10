
# Function to write test cases to a file
proc write_test_cases {filename} {
    set f [open $filename w]
    puts $f "7 3"
    puts $f "100 25"
    puts $f "1234 432"
    puts $f "0 3"
    puts $f "3 0"
    close $f
}

# Main script
set test_file "test_cases.txt"


write_test_cases $test_file

