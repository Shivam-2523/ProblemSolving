/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

 

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
 

Constraints:

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 231 - 1
*/

class Solution {
public:
    struct TrieNode {
        TrieNode* children[2];
        TrieNode() {
            children[0] = children[1] = nullptr;
        }
    };
    
    void insert(TrieNode *root, int num) {
        TrieNode *node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->children[bit])
                node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }
    
    int maxXOR(TrieNode *root, int num) {
        TrieNode *node = root;
        int xorNum = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int invertBit = 1 - bit;

            //if at ith index we find a inverted bit in the trie we can make that index in xorNum
            //as 1 (different values XORs to 1)
            if (node->children[invertBit]) {
                xorNum |= (1 << i);
                node = node->children[invertBit];
            } 
            //Because at each node we are bound to have 0 or 1 as we inserted all 32 bits for every number
            else {
                node = node->children[bit];
            }
        }
        return xorNum;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        int maxRes = 0;
        
        // Insert first number so we have at least one in the Trie
        insert(root, nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            // Find max XOR of this number with the trie
            maxRes = max(maxRes, maxXOR(root, nums[i]));
            // Insert number for future queries
            insert(root, nums[i]);
        }
        return maxRes;
    }
};