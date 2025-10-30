/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        vector<int> left(n), right(n);

        stack<pair<int, int>> s1; // {value, count}
        stack<pair<int, int>> s2;

        // For left: strict >
        for (int i = 0; i < n; ++i) {
            int count = 1;
            // Pop strictly greater values
            while (!s1.empty() && s1.top().first > arr[i]) {
                count += s1.top().second;
                s1.pop();
            }
            left[i] = count;
            s1.push({arr[i], count});
        }

        // For right: >= (to handle duplicates correctly)
        for (int i = n-1; i >= 0; --i) {
            int count = 1;
            // Pop greater or equal values
            while (!s2.empty() && s2.top().first >= arr[i]) {
                count += s2.top().second;
                s2.pop();
            }
            right[i] = count;
            s2.push({arr[i], count});
        }

        // Compute answer
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + (long long)arr[i] * left[i] * right[i]) % MOD;
        }
        return (int)ans;
    }
};
/*Subarrays Ending at i (the 'left' loop):

For every index i, we want to know how many subarrays END at i where arr[i] is the minimum element.

Step-by-step, maintaining the monotonic stack:
Initialize
left = [?, ?, ?, ?],

stack s = empty

i = 0: arr[0] = 3
Stack is empty, nothing to pop.
Count = 1 (just the subarray [3])
left[0] = 1
Push (3,1) to stack.
i = 1: arr[1] = 1
Stack’s top is (3,1); 3 > 1, so pop (3,1).
Count (starts at 1) += stack top’s count (1) ⇒ count = 2
left[1] = 2
Push (1,2) to stack.
Interpretation:

There are 2 subarrays ending at position 1 ([3,1] and [1]) where 1 is the minimum.

- [3,1]: Minimum is 1
- [1]: Minimum is 1
i = 2: arr[2] = 2
Stack's top is (1,2); 1 < 2, so no pop.
Count = 1 (just [2])
left[2] = 1
Push (2,1) to stack.
Interpretation:

Only [2] ends at index 2 with 2 as the minimum.

i = 3: arr[3] = 4
Stack's top is (2,1); 2 < 4, so no pop.
Count = 1 ([4])
left[3] = 1
Push (4,1) to stack.
Interpretation:

Only [4] ends at index 3 with 4 as the minimum.

Summary of left array:

left = [1, 2, 1, 1]

Subarrays Starting at i (the 'right' loop):

For every index i, count how many subarrays START at i where arr[i] is the minimum element.

We process from right to left.

Initialize
right = [?, ?, ?, ?],

stack s = empty

i = 3: arr[3] = 4
Stack is empty, nothing to pop.
Count = 1 ([4])
right[3] = 1
Push (4,1) to stack.
i = 2: arr[2] = 2
Stack's top is (4,1); 4 >= 2 so pop (4,1)
Count (starts at 1) += 1 (from popped) ⇒ count = 2
right[2] = 2
Push (2,2) to stack.
Interpretation:

2 subarrays start at position 2 with 2 as minimum: [2], [2,4]

i = 1: arr[1] = 1
Stack's top is (2,2); 2 >= 1 so pop (2,2)
Now stack is empty.
Count (starts at 1) += popped 2 ⇒ count = 3
right[1] = 3
Push (1,3) to stack.
Interpretation:

3 subarrays start at position 1 with 1 as minimum: [1], [1,2], [1,2,4]

i = 0: arr[0] = 3
Stack’s top is (1,3), 1 < 3 so no pop.
Count = 1
right[0] = 1
Push (3,1) to stack.
Interpretation:

Only [3] starts at index 0 with 3 as minimum.

Summary of right array:

right = [1, 3, 2, 1]*/
