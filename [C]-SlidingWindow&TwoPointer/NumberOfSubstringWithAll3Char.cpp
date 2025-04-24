/*
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
*/


class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0, n = s.size(), count = 0;
		vector<int> v (3,0);
		
		while(r<n)
		{
			v[s[r]-'a']++;
			while(v[0]>0 && v[1]>0 && v[2]>0)
			{
				 // All substrings from left to right, left+1 to right, ..., are valid
				count += n - r;
				
				// Shrink the window from the left
				v[s[l] - 'a']--;
				l++;
			}
            r++;
		}
		
		return count;
    }
};