#include "LogicOperation.hpp"

LogicOperation::LogicOperation() {}

LogicOperation::LogicOperation(const std::string& codetype,
                               const std::string& dest,
                               const std::string& oprnd1,
                               const std::string& op,
                               const std::string& oprnd2) {
    code_type = codetype;
    destination = dest;
    operand1 = oprnd1;
    operation = op;
    operand2 = oprnd2;
}

void LogicOperation::print() {
    std::cout << "..\tCode type: " << code_type << std::endl;
    std::cout << "..\tDestination: " << destination << std::endl;
    std::cout << "..\tOperand1: " << operand1 << std::endl;
    std::cout << "..\tOperator: " << operation << std::endl;
    std::cout << "..\tOperand2: " << operand2 << std::endl;
}
