/*
You are given a string 'str' and an integer ‘K’. Your task is to find the length of the largest substring with at most ‘K’ distinct characters.

For example:
You are given ‘str’ = ‘abbbbbbc’ and ‘K’ = 2, then the substrings that can be formed are [‘abbbbbb’, ‘bbbbbbc’]. Hence the answer is 7.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= K <= 26
1 <= |str| <= 10^6

The string str will contain only lowercase alphabets.    

Time Limit: 1 sec
Note:
You do not need to print anything. It has already been taken care of. Just implement the function.
Sample Input 1:
2
2
abbbbbbc
3
abcddefg
Sample Output 1:
7
4
Explanation:
For the first test case, ‘str’ = ‘abbbbbbc’ and ‘K’ = 2, then the substrings that can be formed are [‘abbbbbb’, ‘bbbbbbc’]. Hence the answer is 7.

For the second test case, ‘str’ = ‘abcddefg’ and ‘K’ = 3, then the substrings that can be formed is [‘cdde’, ‘ddef’]. Hence the answer is 4.
Sample Input 2:
2
3
aaaaaaaa
1
abcefg
Sample Output 2:
8   
1   


Hints:
1. Try to think of a brute force approach.
2. Try to think of a two-pointer solution.
*/

#include <climits>         // For INT_MIN
#include <unordered_map>   // For unordered_map
#include <string>          // For std::string
#include <algorithm>       // For std::max

int kDistinctChars(int k, std::string &str)
{
    int l = 0, r = 0, n = str.size(), ans = INT_MIN;
    std::unordered_map<int, int> m;

    while (r < n)
    {
        m[str[r] - 'a']++;
        while (m.size() > k)
        {
            m[str[l] - 'a']--;
            if (m[str[l] - 'a'] == 0)
                m.erase(str[l] - 'a');
            l++;
        }
        ans = std::max(ans, r - l + 1);
        r++;
    }
    return ans;
}
