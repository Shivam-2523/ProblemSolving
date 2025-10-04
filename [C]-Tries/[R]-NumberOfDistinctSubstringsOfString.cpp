/*
Given a string of length N of lowercase alphabet characters. The task is to complete the function countDistinctSubstring(), which returns the count of total number of distinct substrings of this string.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. Each test case contains a string str.

Output:
For each test case in a new line, output will be an integer denoting count of total number of distinct substrings of this string.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function countDistinctSubstring().

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 1000

Example(To be used only for expected output):
Input:
2
ab
ababa

Output:
4
10

Exaplanation:
Testcase 1: For the given string "ab" the total distinct substrings are: "", "a", "b", "ab".
*/

class TrieNode
{
public:
    TrieNode()
    {
        for (int i = 0; i < 26; ++i)
            child[i] = nullptr;
        // No need for end marker since we count all nodes
    }
    TrieNode* child[26];
};

int countDistinctSubstring(string s) {
    TrieNode* root = new TrieNode();
    int n = s.size();
    int count = 0; // will count new nodes created (distinct substrings)

    for (int i = 0; i < n; ++i) {
        TrieNode* curr = root;
        for (int j = i; j < n; ++j) {
            int idx = s[j] - 'a';
            if (!curr->child[idx]) {
                curr->child[idx] = new TrieNode();
                ++count;
            }
            curr = curr->child[idx];
        }
    }
    // Optionally, +1 for the empty substring.
    return count + 1;
}
/*
1. Why does adding a new node mean a new substring?

In a Trie (Prefix Tree), each unique path from the root represents a unique substring or prefix.

When we're adding substrings character by character to the Trie, we traverse existing paths if the substring (or its prefix) has been seen before.
If we create a new node at any point, it means this particular character sequence (i.e., substring) has never been inserted before.
0
0 1 2
s h i

1
1 2
h i

2
2
i
*/