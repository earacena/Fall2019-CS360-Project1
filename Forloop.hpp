// CSCI 360 - Project 1 - Group 2
// Created September 14, 2019

#ifndef FORLOOP_HPP
#define FORLOOP_HPP

#include "Declaration.hpp"
#include "LogicOperation.hpp"
#include "ForStatements.hpp"
#include "Assembly.hpp"


class ForLoop {
public:
    ForLoop();
    
    ForLoop(const std::string& codetype,
            Declaration init,
            const std::string& term,
            LogicOperation inc,
            Assembly trans,
            struct ForStatements statement);
    
    void print();
    
    Assembly translation;
    std::string code_type;
    Declaration initialization;
    std::string termination;
    LogicOperation increment;
    struct ForStatements statements;
};

#endif
