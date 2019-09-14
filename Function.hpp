// CSCI 360 - Project 1 - Group 2
// Created on September 14, 2019
#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <utility>
#include <string>

#include "Statements.hpp"

class Function {
 public:
  Function();

  Function(const std::string& returntype,
           const std::string& functionname,
           std::pair<std::string, std::string> param,
           const struct Statements& instr);
  
  std::string return_type;
  std::string function_name;
  std::pair<std::string, std::string> parameter; // type, name
  struct Statements instructions;
};

#endif
