#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the floor of the given number in a sorted array
int floorValue(const vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1;
    int ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return arr[mid];  // If the element is found, it's both floor and ceil
        }
        else if (arr[mid] < x) {
            ans = arr[mid];  // This could be a valid floor, but continue searching to the right
            left = mid + 1;
        }
        else {
            right = mid - 1;  // Searching to the left if mid is greater than x
        }
    }
    return ans;  // The floor value after the loop completes
}

// Function to find the ceil of the given number in a sorted array
int ceilValue(const vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1;
    int ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return arr[mid];  // If the element is found, it's both floor and ceil
        }
        else if (arr[mid] > x) {
            ans = arr[mid];  // This could be a valid ceil, but continue searching to the left
            right = mid - 1;
        }
        else {
            left = mid + 1;  // Searching to the right if mid is smaller than x
        }
    }
    return ans;  // The ceil value after the loop completes
}

int main() {
    vector<int> arr = {1, 2, 4, 6, 8, 10, 12, 14};  // Sorted array

    int x = 5;
    int floorVal = floorValue(arr, x);
    int ceilVal = ceilValue(arr, x);

    cout << "Floor of " << x << " is: " << floorVal << endl;
    cout << "Ceil of " << x << " is: " << ceilVal << endl;

    x = 7;
    floorVal = floorValue(arr, x);
    ceilVal = ceilValue(arr, x);

    cout << "Floor of " << x << " is: " << floorVal << endl;
    cout << "Ceil of " << x << " is: " << ceilVal << endl;

    return 0;
}
