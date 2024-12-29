#include <vector>
#include <iostream>
using namespace std;

// Function to find the lower bound of k
int lowerBound(vector<int>& v, int k) {
    int l = 0, r = v.size() - 1;
    int ans = v.size(); // Initialize to size of array, which is an invalid index.

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (v[mid] >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    // If k is not found, ans will point to the first index where k could be inserted
    return ans;
}

// Function to find the upper bound of k
int upperBound(vector<int>& v, int k) {
    int l = 0, r = v.size() - 1;
    int ans = v.size(); // Initialize to size of array, an invalid index.

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (v[mid] <= k) {
            l = mid + 1;
        } else {
            ans = mid;
            r = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> v {1, 2, 4, 5, 8};
    
    // Find and print the lower and upper bounds for 5
    cout << "LOWER BOUND: " << lowerBound(v, 5) << endl;
    cout << "UPPER BOUND: " << upperBound(v, 5) << endl;

    // Example for an element not in the array (e.g., 6)
    cout << "LOWER BOUND of 6: " << lowerBound(v, 6) << endl;
    cout << "UPPER BOUND of 6: " << upperBound(v, 6) << endl;

    return 0;
}
