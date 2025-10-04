/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/


#include <unordered_set>
#include <queue>
#include <string>
#include <vector>

class Solution {
public:
    void addToQueue(std::queue<std::string> &q, const std::string &word, std::unordered_set<std::string> &wordlist) {
        for (int i = 0; i < word.size(); ++i) {
            std::string temp = word;
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                if (temp[i] == ch) continue;
                temp[i] = ch;
                if (wordlist.count(temp)) {
                    q.push(temp);
                    wordlist.erase(temp); // removes from set and acts as visited
                }
            }
        }
    }

    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> wordlist(wordList.begin(), wordList.end());

        if (!wordlist.count(endWord)) return 0;

        std::queue<std::string> q;
        q.push(beginWord);
        int count = 1;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                std::string node = q.front(); q.pop();
                if (node == endWord) return count;
                addToQueue(q, node, wordlist);
            }
            count++;
        }
        return 0;
    }
};