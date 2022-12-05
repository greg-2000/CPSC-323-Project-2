# CPSC-323-Project-2
Author: Gregory Martinez
Email: greg_2000@csu.fullerton.edu
Date: 2022-12-04
Files: Prog1.cpp, r.sh
The purpose of this program is to showcase the understanding of Predictive Parsing Table LL(1) with no backtracking through code implementation. The program will take in production rules after left recursion elimination from the user along with the follow and first of the rules, terminals, and nonterminals to establish itself in a parsing table.
The attached r.sh file may be ran with ./r/sh on the terminal to compile, link, and run automatically, or you may follow the command lines below in order to compile and link the file yourself manually.

Compile driver.cpp
g++ -c -m64 -Wall -fno-pie -no-pie -o Prog1.o Prog1.cpp -std=c++17

Link the object files
g++ -m64 -no-pie -no-pie -o Prog1.out Prog1.o -std=c++17

Run the Program
./Prog1.out
