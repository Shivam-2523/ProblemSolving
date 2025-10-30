/*
You are given two strings ‘S’ and ‘T’. Your task is to find the minimum (Contiguous) substring ‘W’ of ‘S’, such that ‘T’ is a subsequence of ‘W’

A subsequence is a sequence that can be derived from another sequence by removing zero or more elements, without changing the order.

A substring is a contiguous part of a string.

For example:
For the given string “CodingNinjas”: “Ninja” is a substring while “dinas” is a subsequence. 
If there is no such Window in ‘S’ that covers all characters in ‘T’, return an empty string "". If there are multiple such minimum length windows, return the one with the smallest starting index.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= S <= 1000      
1 <= T <= 100

Time limit: 1 sec
Sample Input 1 :
2
rdew
u
abcdebdde
bde
Sample Output 1 :
""
bcde
Explanation For Sample Output 1 :
For test case 1 :
Since there is no window in ‘S’ which covers all characters of ‘T’ so therefore we returned an empty string.

For test case 2 :
“bcde” is the substring of minimum length in which we find “bde”. “bdde” is also a substring of minimum length however the index of “bcde” occurs first, therefore we returned bcde
Sample Input 2:
2
hello
eo
goodbye
dy
Sample Output 2:
ello
dby
*/

string minWindow(string S, string T) {
    int n = S.length(), m = T.length();
    int minLen = INT_MAX;
    int start = -1;

    for (int i = 0; i < n; ++i) {
        if (S[i] == T[0]) {
            int sIdx = i, tIdx = 0;
            
            // Move forward to find the subsequence match
            while (sIdx < n && tIdx < m) {
                if (S[sIdx] == T[tIdx]) {
                    tIdx++;
                }
                sIdx++;
            }

            // If complete T is matched
            if (tIdx == m) {
                // Now move backward to minimize window
                int end = sIdx - 1;
                tIdx = m - 1;
                while (sIdx >= i) {
                    if (S[sIdx] == T[tIdx]) {
                        tIdx--;
                        if (tIdx < 0) break;
                    }
                    sIdx--;
                }

                int winStart = sIdx;
                if (end - winStart + 1 < minLen) {
                    minLen = end - winStart + 1;
                    start = winStart;
                }
            }
        }
    }

    return start == -1 ? "" : S.substr(start, minLen);
}