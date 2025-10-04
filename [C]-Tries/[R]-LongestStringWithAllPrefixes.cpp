/*
Given an array of strings words[], find the longest string such that every prefix of it is also present in words[]. If multiple strings have the same maximum length, return the lexicographically smallest one.

If no such string is found, return an empty string.

Examples:

Input: words[] = ["p", "pr", "pro", "probl", "problem", "pros", "process", "processor"]
Output: "pros" 
Explanation: "pros" is the longest word with all prefixes ("p", "pr", "pro", "pros") present.
Input: words[] = ["geeks", "gfg", "geeksforgeeks"]
Output: ""
Explanation: No valid strings for all their prefixes present in the words array.
Constraints:
1 <= words.size <= 1000
1 <= words[i].size <= 100
*/

class TrieNode {
public:
    TrieNode *children[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() { root = new TrieNode(); }
    void insert(const string &word) {
        TrieNode *curr = root;
        for(char c : word) {
            int idx = c - 'a';
            if(!curr->children[idx]) curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    // Checks if all prefixes of word are present in the trie
    bool allPrefixesPresent(const string &word) {
        TrieNode *curr = root;
        for(char c : word) {
            int idx = c - 'a';
            curr = curr->children[idx];
            if(!curr || !curr->isEnd) return false;
        }
        return true;
    }
};

class Solution {
public:
    string longestValidWord(vector<string>& words) {
        Trie trie;
        for(const string& word : words) trie.insert(word);

        string res = "";
        for(const string& word : words) {
            if(trie.allPrefixesPresent(word)) {
                // Update result if longer or lexicographically smaller
                if(word.size() > res.size() || (word.size() == res.size() && word < res)) {
                    res = word;
                }
            }
        }
        return res;
    }
};