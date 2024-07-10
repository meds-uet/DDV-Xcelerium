#!/bin/bash

# TODO: Implement a shell script that:
# 1. Builds the project
# 2. Runs the basic C tests
# 3. Runs the TCL-based advanced tests
# 4. Cleans up build artifacts
# 5. Reports overall results

echo "TODO: Implement full test automation script"
# this runs c file
make all
#  runs tcl file
chmod +x test.tcl
tclsh 
