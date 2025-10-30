#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;         // Assume current i is largest
    int left = 2 * i + 1;    // Left child index
    int right = 2 * i + 2;   // Right child index

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected subtree
    }
}

void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();

    // Start from the last internal node and move to the root
    for (int i = (n - 2) / 2; i >= 0; i--) {
        heapify(arr, n, i);
    }
}