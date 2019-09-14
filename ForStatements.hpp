// CSCI 360 - Project 1 - Group 2
// Created on September 14, 2019

// This structure is specifically for For loops, since using
// struct Statements provokes type looping.


#ifndef FORSTATEMENT_HPP
#define FORSTATEMENT_HPP

#include <string>
#include "Declaration.hpp"
#include "LogicOperation.hpp"

struct ForStatements {
  std::string type;
  Declaration dec_instr;
  LogicOperation lo_instr;
  struct ForStatements* next = nullptr;
};

#endif // FORSTATEMENT_HPP