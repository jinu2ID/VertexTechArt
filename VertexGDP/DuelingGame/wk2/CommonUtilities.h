#pragma once
#include <vector>
#include <string>

// This function add an integer to the last Index of vector reference
void AddIntToLastIndex(std::vector<int>& numbers, int IntToAdd);

// Print vector length
void PrintVectorSize(const std::vector<int> &vector);

int GetUserInt(std::string error_message);
