// CSCI 360 - Project 1 - Group 2
// Created on September 14, 2019

#ifndef STATEMENTS_HPP
#define STATEMENTS_HPP

#include <string>
#include "Declaration.hpp"
#include "LogicOperation.hpp"

struct Statements {
  std::string type;
  Declaration dec_ptr;
  LogicOperation lo_ptr;
  struct Statements* next = nullptr;
};

#endif
