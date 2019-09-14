// CSCI 360 - Project 1 - Group 2
// Created on September 14, 2019

#include "Parser.hpp"

Parser::Parser() {

}

std::vector<std::string> Parser::read_head(const std::string& line) {
  std::vector<std::string> words {"", "", "", ""};
  int i = 0;
  for (char ch : line) {
    if (ch != ' ' && ch != '(' && ch != ')') {
      words[i] = words[i] + ch;
    } else { 
      i = i + 1;
      if (ch == ')')
        break;
    }
  }

  return words;
}

Declaration Parser::read_declaration(const std::string& line) {
  std::vector<std::string> words {"", "", ""};
  int i = 0;
  for (char ch : line) {
    if (ch != ' ' && ch != '=' && ch != ';') {
      words[i] = words[i] + ch;
    } else {
      i = i + 1;
    }
  }
  num_of_declarations = num_of_declarations + 1;
  Declaration new_declaration("declaration", words[0], words[1], atoi(words[2].c_str()),
                               (-4 * num_of_declarations));
  
  return new_declaration;
  
}

LogicOperation read_logic(const std::string& line) {
  std::vector<std::string> words {"", "", "", ""};
  int i = 0;
  for (char ch : line) {
    if (ch == '+' || ch == '-' || ch == '/') {
      i = i + 1;
      words[i] = ch;
      i = i + 1;
    } else if (ch != '=' && ch != ';') {
      words[i] = words[i] + ch;
    } else {
      i = i + 1;
    }
  }

  LogicOperation new_logicop("logicOperation", words[0], words[1], words[2], words[3]);
  
  return new_logicop;
}

