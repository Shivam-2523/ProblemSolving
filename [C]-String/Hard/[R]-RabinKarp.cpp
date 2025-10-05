/*
Given a string text and a string pattern, implement the Rabin-Karp algorithm to find the starting index of all occurrences of pattern in text. If pattern is not found, return an empty list.


Examples:
Input: text = "ababcabcababc", pattern = "abc"



Output: [2, 5, 10]



Expalanation : The pattern "abc" is found at indices 2, 5, and 10 in the text.

Input: text = "hello", pattern = "ll"



Output: [2]



Explanation: The pattern "ll" is found at index 2 in the text.
*/

class Solution{
public:
    // Z-Function helper
    vector<int> searchUsingZFunction(const string& text, const string& pattern) {
        string concat = pattern + "$" + text;
        int n = concat.length(), pLen = pattern.length();
        vector<int> Z(n, 0), result;

        int l = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            if (i <= r)
                Z[i] = min(r - i + 1, Z[i - l]);
            while (i + Z[i] < n && concat[Z[i]] == concat[i + Z[i]])
                Z[i]++;
            if (i + Z[i] - 1 > r) {
                l = i;
                r = i + Z[i] - 1;
            }
        }
        for (int i = pLen + 1; i < n; ++i) {
            if (Z[i] == pLen)
                result.push_back(i - pLen - 1);
        }
        return result;
    }

    // Rabin-Karp helper
    vector<int> searchUsingRabinKarp(const string& text, const string& pattern) {
        const int d = 256;       // Number of characters in the input alphabet
        const int q = 101;       // A prime number for modulo operation
        int n = text.size(), m = pattern.size();
        vector<int> result;
        if (m > n) return result;

        int p_hash = 0; // hash value for pattern
        int t_hash = 0; // hash value for text
        int h = 1;

        // The value of h would be "pow(d, m-1)%q"
        for (int i = 0; i < m - 1; i++)
            h = (h * d) % q;

        // Calculate the hash value of pattern and first window of text
        for (int i = 0; i < m; i++) {
            p_hash = (d * p_hash + pattern[i]) % q;
            t_hash = (d * t_hash + text[i]) % q;
        }

        // Slide the pattern over text one by one
        for (int i = 0; i <= n - m; i++) {
            // Check the hash values of current window of text and pattern
            if (p_hash == t_hash) {
                // Check characters one by one for collision
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        match = false;
                        break;
                    }
                }
                if (match)
                    result.push_back(i);
            }
            // Calculate hash value for next window of text:
            // Remove leading digit, add trailing digit
            if (i < n - m) {
                t_hash = (d * (t_hash - text[i] * h) + text[i + m]) % q;
                // We might get negative value of t_hash, convert it to positive
                if (t_hash < 0) t_hash += q;
            }
        }
        return result;
    }

    // Main search function; you can pick which algorithm to use
    vector <int> search(string pat, string txt) {
        // Example: use Z-Function
        // return searchUsingZFunction(txt, pat);

        // Example: use Rabin-Karp
        return searchUsingRabinKarp(txt, pat);
    }
};