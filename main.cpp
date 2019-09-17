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

  // Start Parser
  Parser parser(source);

  // Parse source code
  // Python version in comments:
  // head = read_head(source[0])
  std::vector<std::string> head = parser.read_head(parser.source[0]);

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

  auto instructions = parser.read_instruction(1, parser.source);
  function.instructions = instructions.second;

  // Store what we parse
  parser.parsed_source.push_back(function);
  parser.print_parsed_source();
  // final_result = json.dumps(functionClass, indent=4)
  // print(final_result)
  
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
