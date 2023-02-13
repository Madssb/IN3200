#!/bin/bash

# Get the name of the .c file from the command line argument
source_file=$1

# Check if the .c file was provided as an argument
if [ -z "$source_file" ]; then
  echo "Error: Please provide the name of the .c file as an argument."
  exit 1
fi

# Compile the source file
gcc "$source_file" -Og -ggdb3 -Wall -Wextra -Wconversion -pedantic-errors -fsanitize=address,undefined -lm
# Check if the compilation was successful
if [ $? -eq 0 ]; then
  echo "Compilation was successful."
else
  echo "Compilation failed."
fi
