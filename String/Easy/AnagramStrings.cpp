/*
Given two strings s and t, return true if t is an 
anagram
 of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;

        vector<int> v(26,0);

        for(auto i: s)
            v[i-'a']++;
        for(auto i: t)
            v[i-'a']--;

        for(auto i:v)
        {
            if(i!=0)
                return false;
        }
        return true;
    }
};