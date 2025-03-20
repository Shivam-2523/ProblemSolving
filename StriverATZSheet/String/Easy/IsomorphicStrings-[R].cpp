/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true

 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/




    bool isIsomorphic(string s, string t) {
        int l1=s.length();
        int l2=t.length();
        if(l1!=l2)return false;
        vector<int>index1(200,0);
        vector<int>index2(200,0);
        for(int i=0;i<l1;i++){
            if(index1[s[i]]!=index2[t[i]])return false;
            index1[s[i]]=i+1;
            index2[t[i]]=i+1;
        }return true;
    }

if each character that is mapped to each other is given a specific value. Then next time when it is mapped with other value we will know. Also If one of the characters in either of the strings is used previously the value will be greater than 0 and it will not match.

"bad", "bab" should be false too.