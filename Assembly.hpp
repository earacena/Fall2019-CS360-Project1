#ifndef ASSEMBLY_HPP
#define ASSEMBLY_HPP

#include <stdio.h>
#include <iostream>
#include <string>
//#include "ForStatements.hpp"

class Assembly {
    
public:
    Assembly();
    
    Assembly(const std::string& codeinstruction,
             const std::string& dest,
             int datavalue,
             int addr);
    
    void print();
    
    std::string code_type;
    std::string code_instruction;
    std::string destination;
    int data_value;
    int address;
    
    
    
};

#endif // ASSEMBLY_HPP
