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
