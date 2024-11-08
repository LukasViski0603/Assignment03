#include "insertion_sort.h"
#include <vector>

void insertionSort(Queue<int>& queue) {
    // Convert queue to vector for easier sorting
    std::vector<int> arr;

    // Copy all elements to vector
    while (!queue.empty()) {
        arr.push_back(queue.front());
        queue.pop();
    }

    // Perform insertion sort on vector
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // Copy sorted elements back to queue
    for (int value : arr) {
        queue.push(value);
    }
}