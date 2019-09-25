// CSCI 360 - Project 1 - Group 2
// Created on September 14, 2019

#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Function.hpp"
#include "Declaration.hpp"
#include "LogicOperation.hpp"
#include "ForLoop.hpp"
#include "Statements.hpp"

class Parser {
 public:
  Parser();
  Parser(const std::vector<std::string>& source_code);

  // Helper functions
  std::vector<std::string> split(std::string str, const std::string& delimiter);
  void print_parsed_source();
  
  // Parser functions
  std::vector<std::string> read_head(const std::string& line);
  Declaration read_declaration(const std::string& line);
  LogicOperation read_logic(const std::string& line);
  std::pair<int, ForLoop> read_for_loop(int i, const std::vector<std::string>& segment);
  std::pair<int, Statements> read_instruction(size_t i, const std::vector<std::string>& segment);
  std::pair<int, ForStatements> read_instruction_for_loop(size_t i, const std::vector<std::string>& segment);
  
  

  std::vector<std::string> source;
  // This will contain the block of lines for every function
  std::vector< std::vector<std::string> > source_functions;
  std::vector<Function> parsed_source;
  int num_of_declarations = 0;
  
};

#endif // PARSER_HPP
