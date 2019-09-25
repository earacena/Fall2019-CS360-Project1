#include "Assembly.hpp"
Assembly::Assembly() {
    
}

Assembly::Assembly(const std::string& codeinstruction,
                   const std::string& dest,
                   int datavalue,
                   int addr)
{
    code_instruction = codeinstruction;
    destination = dest;
    data_value = datavalue;
    address = addr;
}

void Assembly::translate_logic(LogicOperation logic)
{
    if(logic.operation == "+")
        assembly.push_back("add   " + logic.destination + "  " + logic.operand2);
    else if(logic.operation == "-")
        assembly.push_back("sub   " + logic.destination + "  " +logic.operand2);
}

void Assembly::translate_declaration(Declaration declare)
{
    if(declare.data_type == "int")
    {
        assembly.push_back("mov  " + declare.data_name);
    }
}



void Assembly::print() {
    for(std::string translated : assembly)
        std::cout<<translated<<std::endl;
}
