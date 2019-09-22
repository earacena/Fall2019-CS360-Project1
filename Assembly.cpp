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

void Assembly::print() {
    std::cout<<"push rbp"<<std::endl;
    std::cout<<"mov rbp, rsp"<<std::endl;
    //std::cout << "instrction: " << code_instruction << //std::endl;
    //std::cout << "destination: " << destination << std::endl;
    //std::cout << "value: " << data_value << std::endl;
    //std::cout << "address: " << address << std::endl;
    
}
