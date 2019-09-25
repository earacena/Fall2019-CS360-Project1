// CSCI 360 - Project 1 - Group 2
// Created on September 14, 2019

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>

#include "Parser.hpp"
#include "Function.hpp"

void print_splash_screen() {
  std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
  std::cout << "+\t\tC++ to x86_64 TRANSLATOR\t\t+" << std::endl;
  std::cout << "+\t\t\tBy Group 2\t\t\t+\n";
  std::cout << "+.......................................................+\n";
}

void menu() {
  std::cout << "+.......................................................+\n";
  std::cout << "-\t\t\tMain Menu\t\t\t-\n";
  std::cout << "-\t\t\t\t\t\t\t-\n";
  std::cout << "- 0. Load source code\t\t\t\t\t-\n";
  std::cout << "- 9. Quit\t\t\t\t\t\t-\n";
  std::cout << "\nChoice: ";
}

// Helper functions

// Checks if keyword is somewhere inside string
bool contains(const std::string& str, const std::string& keyword) {
  return (str.find(keyword) != std::string::npos);
}


// Load source code choice
// Initiates process to start parser
void start_process() {
  std::string filename;
  std::cout << "Source code filename?: ";
  std::cin >> filename;

  // Load source
  std::ifstream file(filename);
  std::string line;
  std::vector<std::string> source;
  while (std::getline(file, line))
    source.push_back(line);

  // Print source to confirm
  std::cout << "\nSource code loaded:\n.\n";
  for (std::string line : source)
    std::cout << ".  "  << line << std::endl;

  std::cout << ".\n.\n";
  
  // Start Parser
  Parser parser(source);

  // Organize source code into functions
  int parenthesis_stack = 0;
  bool inside_function = false;
  std::vector<std::string> function_block;
  std::cout << ". Searching for functions..." << std::endl;
  for (size_t i = 0; i < parser.source.size(); ++i) {
    std::cout << ". Checking line " << i+1 << ",\tsource[i]= " << source[i]
              << ", " << "inside_function=" << inside_function
              << ", parenthesis_stack=" << parenthesis_stack << " ..." << std::endl;

    if (contains(parser.source[i], "{") && !inside_function) {
      std::cout << ". Function detected, processing..." << std::endl;
      ++parenthesis_stack;
      inside_function = true;
    } else if (contains(parser.source[i], "{")) {
      ++parenthesis_stack;
    }   
    if (contains(parser.source[i], "}")) {
      --parenthesis_stack;
      
      if (parenthesis_stack == 0) {
        inside_function = false;
        function_block.push_back(source[i]);
        parser.source_functions.push_back(function_block);
        function_block.clear();
      }
    }

    if (inside_function) {
      function_block.push_back(source[i]);
    }
  }

  // Clear, no longer needed
  function_block.clear();
  
  std::cout << ".\n. Processing acquired data..." << std::endl;
  std::cout << ". Number of functions processing: " << parser.source_functions.size()
            << "..." << std::endl;

  
  for (size_t i = 0; i < parser.source_functions.size(); ++i) {
    // Parse source code
    // Python version in comments:
    // head = read_head(source[0])
    const auto& head = parser.read_head(parser.source_functions[i][0]);

    Function function;
    // functionClass["returnType"] = head[0]
    function.return_type = head[0];
  
    // functionClass["functionName"] = head[1]
    function.function_name = head[1];

    // functionClass["parameter"] = {
    //     "type": head[2],
    //     "name": head[3],
    //     "codeType": "declaration",
    //     "address": -(declaration*4)
    // }
    function.parameter = std::make_tuple(head[2], head[3], "declaration",
                                         (-4 * parser.num_of_declarations));
    // # ignore the first line
    // functionClass["instruction"] = read_instruction(1, source)["statement"]

    auto instructions = parser.read_instruction(1, parser.source_functions[i]);
    function.instructions = instructions.second;

    // Store what we parse
    std::cout << ". Storing parsed function..." << std::endl;
    parser.parsed_source.push_back(function);
  }
  // final_result = json.dumps(functionClass, indent=4)
  // print(final_result)
  parser.print_parsed_source();
    
}

int main() {
  //Parser parser;
  int choice = 0;

  print_splash_screen();
  
  while(choice != 9) {
    menu();
    std::cin >> choice;
    if (choice == 0)
      start_process();
  }
  
  return 0;
}
