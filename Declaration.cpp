// CSCI 360 Project 1, Group 2
// Created on September 14, 2019
#include "Declaration.hpp"

Declaration::Declaration() {
  
}

Declaration::Declaration(const std::string& codetype,
                         const std::string& datatype,
                         const std::string& dataname,
                         int datavalue,
                         int addr) {
  code_type = codetype;
  data_type = datatype;
  data_name = dataname;
  data_value = datavalue;
  address = addr;
}

void Declaration::print() {
  std::cout << "..\tCode type: " << code_type << std::endl;
  std::cout << "..\tData type: " << data_type << std::endl;
  std::cout << "..\tData name: " << data_name << std::endl;
  std::cout << "..\tData value: " << data_value << std::endl;
  std::cout << "..\tAddress: " << address << std::endl;
}
