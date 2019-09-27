// CSCI 360 - Project 1 - Group 2
// Created on September 14, 2019

#ifndef STATEMENTS_HPP
#define STATEMENTS_HPP

#include <string>
#include "Declaration.hpp"
#include "LogicOperation.hpp"
#include "ForLoop.hpp"
#include "Assembly.hpp"

struct Statements {
    std::string type = "";
    
    // return statements
    std::string instr;
    
    Declaration dec_instr;
    LogicOperation lo_instr;
    Assembly a_instr;
    ForLoop for_instr;
    struct Statements* next = nullptr;
};

#endif
