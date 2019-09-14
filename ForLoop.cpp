#include "ForLoop.hpp"

ForLoop::ForLoop() {}

ForLoop::ForLoop(const std::string& codetype,
                 Declaration init,
                 const std::string& term,
                 LogicOperation inc,
                 Statements statement) {
  code_type = codetype;
  initialization = init;
  termination = term;
  increment = inc;
  statements = statement;
}
