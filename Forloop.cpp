#include "ForLoop.hpp"

ForLoop::ForLoop() {}

ForLoop::ForLoop(const std::string& codetype,
                 Declaration init,
                 const std::string& term,
                 LogicOperation inc,
                 ForStatements statement) {
    code_type = codetype;
    initialization = init;
    termination = term;
    increment = inc;
    statements = statement;
}

void ForLoop::print() {
    std::cout << "..\tCode type: " << code_type << std::endl;
    initialization.print();
    std::cout << "..\tTerm. statement: " << termination << std::endl;
    increment.print();
    
    ForStatements* current = &statements;
    
    while(current != nullptr) {
        if (current->type == "declaration")
            current->dec_instr.print();
        else if (current->type == "logic")
            current->lo_instr.print();
        //else if (current->type == "for" )
        //current->for_instr.print();
        else if (current->type == "return")
            std::cout << "..\tINSTRUCTION: " <<  current->instr << std::endl;
        
        current = current->next;
    }
}
