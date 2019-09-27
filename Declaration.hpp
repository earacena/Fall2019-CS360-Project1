// CSCI 360 Project 1, Group 2
// Created on September 14, 2019


#ifndef DECLARATION_HPP
#define DECLARATION_HPP

#include <iostream>
#include <string>

class Declaration {
public:
    Declaration();
    
    Declaration(const std::string& codetype,
                const std::string& datatype,
                const std::string& dataname,
                int datavalue,
                int addr);
    
    void print();
    
    std::string code_type;
    std::string data_type;
    std::string data_name;
    int data_value;
    int address;
    
};

#endif // DECLARATION_HPP


