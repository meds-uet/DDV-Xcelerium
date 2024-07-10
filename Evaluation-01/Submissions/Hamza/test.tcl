# Author: Hamza
# Date: 10 July 2024
# TCL File for verifying the C results


# Define test cases
set testCases {
    {4 5}
    {50 2}
    {10 0}
    {0 5}
}

# Writing test cases to a file
set fileId [open "test_cases.txt" "w"]
foreach testCase $testCases {
    puts $fileId $testCase
}
close $fileId

# Creating function to run the C program thorugh terminal and fetching the results
proc run_c_program {} {
    set cmd [format "./divisionProgram"]
    set result [exec $cmd]
    return $result
}

# Function to parse the C program output and extract quotient and remainder=
proc parse_result {result} {
    set lines [split $result "\n"]

    # Ignoring Test result passed and failed line and fetching quotient and remainder from another line
    foreach line $lines {
        if {[regexp {The quotient of (\d+) and (\d+) is (\d+)} $line -> num1 num2 q]} {
            set quotient $q
        } elseif {[regexp {The remainder of (\d+) and (\d+) is (\d+)} $line -> num1 num2 r]} {
            set remainder $r
        }
    }

    return [list $quotient $remainder]
}


# Creating Function to compare results
proc compare_results {expected actual} {
    set expectedResults [split $expected]
    set actualResults [split $actual]


    # Checking if any variable mis matches with the result
    foreach {e a} [list $expectedResults $actualResults] {
        if {$e != $a} {
            return "fail"
        }
    }
    return "pass"
}


# Reading test cases from file and generate results
set fileId [open "test_cases.txt" "r"]
set summaryFileId [open "summary_report.txt" "w"]

while {[gets $fileId line] >= 0} {

    # Assigning the value of each line in numerator and denominator
    lassign $line numerator denominator

    # Calling the function to fetch result from cmd and then parse them
    set result [run_c_program]
    set parsedResult [parse_result $result]

    if {$denominator == 0} {
        set expectedQuotient 0
        set expectedRemainder 0
    } else {
        set expectedQuotient [expr {$numerator / $denominator}]
        set expectedRemainder [expr {$numerator % $denominator}]
    }

    # Setting the Expected Quotient and Remainder in Expected Result to compare it with actual result
    set expectedResult [list $expectedQuotient $expectedRemainder]

    # Comparing the results
    set comparisonResult [compare_results $expectedResult $parsedResult]

    # Adding the report data in summary file
    puts $summaryFileId "Test Summary Report\n"
    puts $summaryFileId "====================\n"
    puts $summaryFileId "Test case: $numerator / $denominator"
    puts $summaryFileId "Expected quotient: $expectedQuotient, remainder: $expectedRemainder"
    puts $summaryFileId "Actual quotient: [lindex $parsedResult 0], remainder: [lindex $parsedResult 1]"
    puts $summaryFileId "Test result: $comparisonResult"
}

# Closing the files
close $fileId
close $summaryFileId


# Displaying message that report is generated successfully
puts "Summary report generated: summary_report.txt"

