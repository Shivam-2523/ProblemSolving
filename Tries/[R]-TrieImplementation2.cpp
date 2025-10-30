/*
Implement "TRIE” data structure from scratch with the following functions.



Trie(): Initialize the object of this “TRIE” data structure.


insert(“WORD”): Insert the string “WORD” into this “TRIE” data structure.


countWordsEqualTo(“WORD”): Return how many times this “WORD” is present in this “TRIE”.


countWordsStartingWith(“PREFIX”): Return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.


erase(“WORD”): Delete one occurrence of the string “WORD” from the “TRIE”.

Examples:
Input : ["Trie", "insert", "countWordsEqualTo", "insert", "countWordsStartingWith", "erase", "countWordsStartingWith"]

[ "apple", "apple", "app", "app", "apple", "app" ]



Output : [null, null, 1, null, 2, null, 1]



Explanation :

Trie trie = new Trie()

trie.insert("apple")

trie.countWordsEqualTo("apple")  // return 1

trie.insert("app") 

trie.countWordsStartingWith("app") // return 2

trie.erase("apple")

trie.countWordsStartingWith("app")   // return 1

Input : ["Trie", "insert", "countWordsEqualTo", "insert", "erase", "countWordsStartingWith"]

[ "mango", "apple", "app", "app", "mango" ]



Output : [null, null, 0, null, null, 1]



Explanation :

Trie trie = new Trie()

trie.insert("mango")

trie.countWordsEqualTo("apple")  // return 0

trie.insert("app") 

trie.erase("app")

trie.countWordsStartingWith("mango") // return 1
*/

class TrieNode
{
public:
    TrieNode()
    {
        cntEnd = 0;  // Number of words ending here
        cntPrefix = 0; // Number of words passing through here
        for(int i = 0; i<26; ++i)
            child[i] = nullptr;
    }
    TrieNode * child[26];
    int cntEnd;
    int cntPrefix;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode * curr = root;
        for(char c: word)
        {
            int index  = c-'a';
            if(!curr->child[index])
                curr->child[index] = new TrieNode();
            curr = curr->child[index];
            curr->cntPrefix++;
        }
        curr->cntEnd++;
    }

    int countWordsEqualTo(string word) {
        TrieNode* curr = root;
        for(char c: word)
        {
            int index = c-'a';
            if(!curr->child[index])
                return 0;
            curr = curr->child[index];
        }
        return curr->cntEnd;
    }

    int countWordsStartingWith(string prefix) {
        TrieNode* curr = root;
        for(char c: prefix)
        {
            int index = c-'a';
            if(!curr->child[index])
                return 0;
            curr = curr->child[index];
        }
        return curr->cntPrefix;
    }

    void erase(string word) {
    TrieNode* curr = root;
    TrieNode* nodes[word.size()+1]; // To track path; nodes[0] = root
    int indices[word.size()];       // To track child index at each step
    nodes[0] = root;

    // Traverse the Trie, store nodes and indices
    for (int i = 0; i < word.size(); ++i) {
        int ind = word[i] - 'a';
        if (!curr->child[ind])
            return; // Word not present, nothing to erase
        curr = curr->child[ind];
        nodes[i+1] = curr;
        indices[i] = ind;
    }

    // Only erase if word is present
    if (curr->cntEnd == 0)
        return;

    curr->cntEnd--; // Decrement end count

    // Backtrack and decrement cntPrefix, delete nodes if needed
    for (int i = word.size(); i > 0; --i) {
        nodes[i]->cntPrefix--;

        // If cntPrefix and cntEnd are zero, safe to delete node
        if (nodes[i]->cntPrefix == 0 && nodes[i]->cntEnd == 0) {
            delete nodes[i];
            nodes[i-1]->child[indices[i-1]] = nullptr;
        } else {
            // If node is still needed, stop cleanup
            break;
        }
    }
}
private:
    TrieNode * root;
};