/*
A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

Examples:

Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible corrct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
Input: words[] = ["caa", "aaa", "aab"]
Output: true
Explanation: A possible corrct order of letters in the alien dictionary is "cab".
The pair "caa" and "aaa" suggests 'c' appears before 'a'.
The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary. 
So, 'c' → 'a' → 'b' is a valid ordering.
Input: words[] = ["ab", "cd", "ef", "ad"]
Output: ""
Explanation: No valid ordering of letters is possible.
The pair "ab" and "ef" suggests "a" appears before "e".
The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.
Constraints:
1 ≤ words.length ≤ 500
1 ≤ words[i].length ≤ 100
words[i] consists only of lowercase English letters.
*/


class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, unordered_set<char>> adj; // adjacency list
        unordered_map<char, int> indegree; // indegree count
        
        // collect all unique characters
        for (const string &word : words) {
            for (char c : word) {
                adj[c]; // ensures every char gets a slot
            }
        }
    
        // build graph constraints
        for (int i = 0; i < words.size() - 1; ++i) {
            string &w1 = words[i], &w2 = words[i+1];
            int minLen = min(w1.size(), w2.size());
            int j = 0;
            for (; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    // w1[j] comes before w2[j]
                    if (adj[w1[j]].count(w2[j]) == 0) {
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
            if (j == minLen && w1.size() > w2.size())
                // prefix edge case: invalid
                return "";
        }
    
        // topological sort (Kahn's algorithm)
        queue<char> q;
        string ret;
        for (auto &entry : adj) {
            if (indegree[entry.first] == 0)
                q.push(entry.first);
        }
        while (!q.empty()) {
            char u = q.front(); q.pop();
            ret += u;
            for (char v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
    
        // if not all nodes are processed, cycle detected
        if (ret.size() != adj.size())
            return "";
        return ret;
    }
};