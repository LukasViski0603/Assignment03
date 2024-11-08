#include "recursive_search.h"

int lastOccurrence(const std::vector<int>& arr, int target, int index) {
    // Base case: if we've looked through the entire array
    if (index < 0) {
        return -1;
    }

    // If we find the target, this could be the last occurrence
    if (arr[index] == target) {
        return index;
    }

    // Recursive case: check the rest of the array
    return lastOccurrence(arr, target, index - 1);
}

int findLastOccurrence(const std::vector<int>& arr, int target) {
    // Start from the last index
    return lastOccurrence(arr, target, arr.size() - 1);
}