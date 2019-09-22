// CSCI 360 - Project 1 - Group 2
// Created on September 14, 2019

#ifndef LOGICALOPERATION_HPP
#define LOGICALOPERATION_HPP

#include <iostream>
#include <string>

class LogicOperation {
public:
    LogicOperation();
    
    LogicOperation(const std::string& codetype,
                   const std::string& dest,
                   const std::string& oprnd1,
                   const std::string& op,
                   const std::string& oprnd2);
    
    void print();
    
    std::string code_type;
    std::string destination;
    std::string operand1;
    std::string operation;
    std::string operand2;
};

#endif // LOGICALOPERATION_HPP
