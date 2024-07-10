#!/usr/bin/env tclsh

# Define the file to store test cases
set test_cases_file "test_cases.txt"
set results_file "results.txt"
set summary_report_file "summary_report.txt"

# Open the file to write test cases
set test_cases_fd [open $test_cases_file "w"]

# Define test cases
set test_cases {
    {122 6}
    {12 9}
    {443 722}
    {122 222}
    {10000 2000}
}

# Write test cases to file
foreach case $test_cases {
    lassign $case dividend divisor
    puts $test_cases_fd "$dividend $divisor"
}

# Close the test cases file
close $test_cases_fd

# Run the C program to get the results
exec ./division $test_cases_file > $results_file

# Function to parse the result files and validate
proc parse_and_validate {results_file test_cases_file summary_report_file} {
    set results [open $results_file "r"]
    set test_cases [open $test_cases_file "r"]
    set summary_report [open $summary_report_file "w"]
    
    # Create a list to store the test cases read from the file
    set test_cases_list [list]
    
    # Read the test cases file into a list
    while {[gets $test_cases line] != -1} {
        lassign [split $line] dividend divisor
        lappend test_cases_list [list $dividend $divisor]
    }
    
    # Close the test cases file
    close $test_cases
    
    # Read and validate results
    while {[gets $results line] != -1} {
        set result_line [string trim $line]
        
        # Example format: "Dividend: 122, Divisor: 6, Restored Quotient: 20, Restored Remainder: 2"
        if {[regexp {Dividend: (\d+), Divisor: (\d+), Restored Quotient: (\d+), Restored Remainder: (\d+)} $result_line dummy result_dividend result_divisor quotient remainder]} {
            # Find the expected results
            set expected_quotient 0
            set expected_remainder 0
            
            foreach case $test_cases_list {
                lassign $case case_dividend case_divisor
                if {$case_dividend == $result_dividend && $case_divisor == $result_divisor} {
                    set expected_quotient [expr {$case_dividend / $case_divisor}]
                    set expected_remainder [expr {$case_dividend % $case_divisor}]
                    break
                }
            }
            
            # Compare the results
            if {$quotient == $expected_quotient && $remainder == $expected_remainder} {
                puts $summary_report "Test case: Dividend $result_dividend, Divisor $result_divisor PASSED"
            } else {
                puts $summary_report "Test case: Dividend $result_dividend, Divisor $result_divisor FAILED"
                puts $summary_report "Expected Quotient: $expected_quotient, Remainder: $expected_remainder"
                puts $summary_report "Actual Quotient: $quotient, Remainder: $remainder"
            }
        } else {
            puts $summary_report "Invalid result format: $result_line"
        }
    }

    # Close the files
    close $results
    close $summary_report
}

# Call the parsing and validation function
parse_and_validate $results_file $test_cases_file $summary_report_file

puts "Summary report generated in $summary_report_file"
