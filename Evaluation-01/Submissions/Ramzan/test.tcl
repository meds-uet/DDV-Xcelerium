
#!/usr/bin/env tclsh

# Function to write test cases to a file
proc write_test_cases {run_tests.sh} {
    set fp [ open $run_tests.sh w ] 
    puts $fp "10 3"
    puts $fp "20 4"
    puts $fp "100 10"
    puts $fp "15 0"
    close $fp
}
puts "TCL script completed."
