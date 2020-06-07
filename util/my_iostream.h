#pragma once
#ifndef MY_IOSTREAM_H__
#define MY_IOSTREAM_H__

#include <iostream>
#include <string>
#include <vector>

std::ostream &my_print(std::ostream &, const std::vector<std::string> &);
std::ostream &my_print(std::ostream &, const std::vector<std::vector<std::string>> &);

#endif  // MY_IOSTREAM_H__