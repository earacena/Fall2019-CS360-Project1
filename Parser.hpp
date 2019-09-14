// CSCI 360 - Project 1 - Group 2
// Created on September 14, 2019

#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>

#include "Declaration.hpp"
#include "LogicOperation.hpp"
#include "ForLoop.hpp"
#include "Statements.hpp"

class Parser {
 public:
  Parser();
  std::vector<std::string> read_head(const std::string& line);
  Declaration read_declaration(const std::string& line);
  LogicOperation read_logic(const std::string& line);
  ForLoop read_for_loop(int i, std::vector<std::string> segment);
  
  
  int num_of_declarations;
  
};

#endif // PARSER_HPP
