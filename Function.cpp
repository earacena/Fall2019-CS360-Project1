// CSCI 360 - Project 1 - Group 2
// Created on September 14, 2019

#include "Function.hpp"

Function::Function() {}

Function::Function(const std::string& returntype, const std::string& functionname,
                   const std::tuple<std::string, std::string, std::string, int>& param,
                   const struct Statements& instr) {
    
    return_type = returntype;
    function_name = functionname;
    parameter = param;
    instructions = instr;
}
