/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        int n = strs.size();

        if(n==1)
            return strs[0];
        
        for(int i = 1; i<n; i++)
        {
            int l = 0, r = 0;
            while(l<prefix.size() && r<strs[i].size())
            {
                if(prefix[l]!=strs[i][r])
                    break;
                l++;r++;
            }
            if(l==1)
               prefix=prefix.substr(0,1); 
            else
                prefix=prefix.substr(0,l);
        }
        return prefix;
    }
};