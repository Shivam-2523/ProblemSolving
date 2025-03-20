/*
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        std::unordered_map<int, int> freq;
        for (int card : hand) freq[card]++;

        std::sort(hand.begin(), hand.end());  // Sort once

        for (int card : hand) {
            if (freq[card] == 0) continue;  // Skip if already used

            int count = freq[card];  // Get frequency of the starting card
            for (int i = 0; i < groupSize; i++) {
                if (freq[card + i] < count) return false;  // Check if group can be formed
                freq[card + i] -= count;  // Reduce count from all group elements
            }
        }
        return true;
    }
};