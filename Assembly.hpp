#ifndef ASSEMBLY_HPP
#define ASSEMBLY_HPP

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "ForLoop.hpp"
#include "LogicOperation.hpp"



class Assembly {
    
public:
    Assembly();
    
    Assembly(const std::string& codeinstruction,
             const std::string& dest,
             int datavalue,
             int addr);
    
    std::vector<std::string> assembly;
    void print();
    void translate_logic(LogicOperation logic);
    void translate_declaration(Declaration declare);
    
    
    std::string code_type;
    std::string code_instruction;
    std::string destination;
    int data_value;
    int address;
    int counter =0;
    
    
    
    
};

#endif // ASSEMBLY_HPP
