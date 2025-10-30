/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
*/


class Solution {
public:
    bool rotateString(string s, string goal) {
        int gl = goal.size();
        if(gl!=s.size())
            return false;
        if(gl==1)
            return s==goal;
        if(s==goal)
            return true;
        
        for(int i = 0; i<gl; i++)
        {
            s = s.substr(1,gl-1)+s[0];
            if(goal==s)
                return true;
        }
        return false;
    }
};