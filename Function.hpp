// CSCI 360 - Project 1 - Group 2
// Created on September 14, 2019
#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <tuple>
#include <string>

#include "Statements.hpp"

class Function {
public:
    Function();
    
    Function(const std::string& returntype,
             const std::string& functionname,
             const std::tuple<std::string, std::string, std::string, int>& param,
             const struct Statements& instr);
    
    std::string return_type;
    std::string function_name;
    // type, name, codeType, addr
    std::tuple<std::string, std::string, std::string, int> parameter;
    struct Statements instructions;
};

#endif
