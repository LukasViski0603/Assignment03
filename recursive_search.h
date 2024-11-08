#pragma once
#include <vector>

// Function to find the last occurrence of target in the vector
// Returns -1 if target is not found
int lastOccurrence(const std::vector<int>& arr, int target, int index);

// Helper function that initializes the recursive search
int findLastOccurrence(const std::vector<int>& arr, int target);