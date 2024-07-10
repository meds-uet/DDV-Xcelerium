!/bin/bash

# Function to build the project
build_project() {
    echo "Building the project..."
    make || { echo "Build failed!"; exit 1; }
}

# Function to run basic C tests
run_basic_tests() {
    echo "Running basic C tests..."
    ./basic_tests || { echo "Basic tests failed!"; exit 1; }
}

# Function to run TCL-based advanced tests
run_advanced_tests() {
    echo "Running TCL-based advanced tests..."
    tclsh advanced_tests.tcl || { echo "Advanced tests failed!"; exit 1; }
}

# Function to clean up build artifacts
clean_up() {
    echo "Cleaning up build artifacts..."
    make clean
}

# Function to report overall results
report_results() {
    echo "Reporting overall results..."
    echo "Basic and advanced tests completed successfully."
}

# Main script execution
echo "Starting full test automation script..."

build_project
run_basic_tests
run_advanced_tests
clean_up
report_results

echo "Test automation script completed."

