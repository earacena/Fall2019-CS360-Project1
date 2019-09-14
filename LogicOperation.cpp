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

    
