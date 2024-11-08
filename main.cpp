#include <iostream>
#include "queue.h"
#include "recursive_search.h"
#include "insertion_sort.h"

void testInsertionSort() {
    std::cout << "\n=== Testing Insertion Sort ===\n";

    Queue<int> numbers;
    int test_array[] = { 64, 34, 25, 12, 22, 11, 90 };

    // Display and fill original queue
    std::cout << "Original queue: ";
    for (int num : test_array) {
        numbers.push(num);
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Sort the queue
    insertionSort(numbers);

    // Display sorted result
    std::cout << "Sorted queue: ";
    while (!numbers.empty()) {
        std::cout << numbers.front() << " ";
        numbers.pop();
    }
    std::cout << "\n";
}

// Function to demonstrate queue operations for Q1
void testQueue() {
    std::cout << "\n=== Testing Queue Implementation ===\n";

    // Create a queue of integers
    Queue<int> q;

    // a) Push 10 values into the queue
    std::cout << "\nPushing 10 values into queue...\n";
    for (int i = 1; i <= 10; i++) {
        q.push(i);
        std::cout << "Pushed: " << i << std::endl;
    }

    // b) Display all elements using only queue operations
    std::cout << "\nDisplaying all elements (using queue operations):\n";
    int size = q.size();  // Store size since it will change as we pop
    for (int i = 0; i < size; i++) {
        int value = q.front();
        std::cout << value << " ";
        q.pop();
        q.push(value);  // Push back to preserve queue contents
    }
    std::cout << "\n";

    // c) Test move_to_rear
    std::cout << "\nTesting move_to_rear:\n";
    std::cout << "Before move_to_rear - Front element is: " << q.front() << std::endl;
    q.move_to_rear();
    std::cout << "After move_to_rear - Front element is: " << q.front() << std::endl;
}

void testRecursiveSearch() {
    std::cout << "\n=== Testing Recursive Last Occurrence Search ===\n";

    // Test case 1: Multiple occurrences
    std::vector<int> arr1 = { 1, 2, 3, 2, 4, 2, 5 };
    int target1 = 2;
    std::cout << "\nArray: ";
    for (int num : arr1) std::cout << num << " ";
    int result1 = findLastOccurrence(arr1, target1);
    std::cout << "\nLast occurrence of " << target1 << " is at index: " << result1 << std::endl;

    // Test case 2: Single occurrence
    std::vector<int> arr2 = { 1, 2, 3, 4, 5 };
    int target2 = 3;
    std::cout << "\nArray: ";
    for (int num : arr2) std::cout << num << " ";
    int result2 = findLastOccurrence(arr2, target2);
    std::cout << "\nLast occurrence of " << target2 << " is at index: " << result2 << std::endl;

    // Test case 3: Target not found
    int target3 = 6;
    int result3 = findLastOccurrence(arr2, target3);
    std::cout << "\nSearching for " << target3 << " (not in array)";
    std::cout << "\nResult: " << result3 << " (expected: -1)" << std::endl;
}

int main() {
    try {
        testQueue();
        testRecursiveSearch();
        testInsertionSort();

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}