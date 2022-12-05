#!/bin/bash

# Author: Gregory Martinez
# Email: greg_2000@csu.fullerton.edu
# Date: 2022-12-04
# Files: Prog1.cpp, r.sh

#Delete some un-needed files
rm *.o
rm *.lis
rm *.out

echo "Bash: The script file for Validate Integer Input has begun"

echo "Bash: Compile driver.cpp"
g++ -c -m64 -Wall -fno-pie -no-pie -o Prog1.o Prog1.cpp -std=c++17


echo "Bash: Link the object files"
g++ -m64 -no-pie -no-pie -o Prog1.out Prog1.o -std=c++17

echo "Bash: Run the program Validate Integer Input:"
./Prog1.out

echo "The script file will terminate"