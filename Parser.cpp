// CSCI 360 - Project 1 - Group 2
// Created on September 14, 2019

#include "Parser.hpp"

Parser::Parser() { }

Parser::Parser(const std::vector<std::string>& source_code) {
  source = source_code;
}

bool Parser::startswith(const std::string& line, const std::string& keyword) {
  std::string trim_line = line;
  trim_line = trim_line.substr(0, trim_line.find(' '));
  return keyword == trim_line;
}

std::vector<std::string> Parser::split(std::string str, const std::string& delimiter) {
  std::vector<std::string> split_words;
  std::string token;
  size_t position = str.find(delimiter);
  while(position != std::string::npos) {
    token = str.substr(0, position);
    split_words.push_back(token);
    str = str.substr(position + delimiter.length());
    position = str.find(delimiter);
  }

  return split_words;
}

void Parser::print_parsed_source() {
  std::cout << "... SOURCE CODE IN PARSED FORMAT";
  Statements* current = nullptr;
  for (Function function : parsed_source) {
    current = &function.instructions;
    while(current != nullptr) {
      if (current->type == "declaration")
        current->dec_instr.print();
      else if (current->type == "logic")
        current->lo_instr.print();
      else if (current->type == "for" )
        current->for_instr.print();
      else if (current->type == "return") 
        std::cout << "..\tINSTRUCTION: " <<  current->instr << std::endl;

      current = current->next;
    }
  }
    
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

LogicOperation Parser::read_logic(const std::string& line) {
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

std::pair<int, ForLoop> Parser::read_for_loop(int i, const std::vector<std::string>& segment) {
  std::string line = segment[i];
  std::vector<std::string> header = split(line.substr(3), ";");

  ForLoop new_forloop;
  new_forloop.code_type = "for";
  new_forloop.initialization = read_declaration(header[0] + ";");
  new_forloop.termination = header[1];
  new_forloop.increment = read_logic(header[2] + ";");
  i = i + 1;
  auto result = read_instruction_for_loop(i, segment);
  new_forloop.statements = result.second;
  
  return {result.first, new_forloop};
}

std::pair<int, Statements> Parser::read_instruction(size_t i, const std::vector<std::string>& segment) {
  Statements instruction;
  Statements* current = &instruction;
  std::string line = "";
  std::string keyword = "";
  while (i < segment.size()) {
    line = segment[i];

    if (line == "}")
      break;

    // Remove tab or whitespace 
    while(line[0] == ' ' || line[0] == '\t')
    	line = line.substr(1);

    keyword = line.substr(0, line.find(' '));

    if (keyword == "int") {
      // Append
      std::cout << "DECLARATION DETECTED ("<< keyword <<"), processing...\n";
      current->type = "declaration";
      current->dec_instr = read_declaration(line);
      current->next = new Statements;
      current = current->next;
      i = i + 1;
      
    } else if (keyword == "for") {
      std::cout << "FOR LOOP DETECTED ("<< keyword <<"), processing...\n";
      current->type = "for";
      auto result = read_for_loop(i, segment);
      current->for_instr = result.second;
      current->next = new Statements;
      current = current->next;
      i = result.first;
      
    } else if (keyword == "return") {
      std::cout << "RETURN DETECTED"<< keyword <<", processing...\n";
      current->type = "return";
      current->instr = line;
      current->next = new Statements;
      break;
    } else {
      std::cout << "LOGIC DETECTED("<< keyword <<"), processing...\n";
      current->type = "logic";
      current->lo_instr = read_logic(line);
      current->next = new Statements;
      current = current->next;
      i = i+1;
    }
  }
    
  return {i+1, instruction};
}

std::pair<int, ForStatements> Parser::read_instruction_for_loop(size_t i, const std::vector<std::string>& segment) {
  ForStatements instruction;
  ForStatements* current = &instruction;
  std::string line;
  while (i < segment.size()) {
    line = segment[i];

    if (line == "}")
      break;

    if (startswith(line, "int")) {
      // Append
      current->type = "declaration";
      current->dec_instr = read_declaration(line);
      current->next = new ForStatements;
      current = current->next;
      i = i + 1;
      
    }
    // ForStatements is a special condition, cannot reference for loops otherwise
    // type definition looping occurs
    //
    //else if (startswith(line, "for")) {
    //current->type = "for";
    // auto result = read_for_loop(i, segment);
    //current->for_instr = result.second;
    //current->next = new ForStatements;
    //current = current->next;
    //i = result.first;  
    //}
    else if (startswith(line, "return")) {
      current->type = "return";
      current->instr = line;
      current->next = new ForStatements;
      current = current->next;
    } else {
      current->type = "logic";
      current->lo_instr = read_logic(line);
      current->next = new ForStatements;
      current = current->next;
    }
  }
  return {i+1, instruction};
}
