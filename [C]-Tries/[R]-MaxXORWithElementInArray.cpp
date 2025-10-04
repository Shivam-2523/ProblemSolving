/*
You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

 

Example 1:

Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
Example 2:

Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
Output: [15,-1,5]
 

Constraints:

1 <= nums.length, queries.length <= 105
queries[i].length == 2
0 <= nums[j], xi, mi <= 109

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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        using gen = std::tuple<int, int, int>;
        priority_queue<gen,vector<gen>,greater<gen>> pq;

        for(int i = 0; i<queries.size(); ++i)
            pq.push({queries[i][1],queries[i][0],i});

        TrieNode * root = new TrieNode();
        vector<int> result (queries.size(),-1);
        int i = 0;
        while(!pq.empty())
        {
            auto [maxValue,element,index] = pq.top(); pq.pop();

            while(i<n && nums[i]<=maxValue)
                insert(root,nums[i++]);
            
            if(i>0)//at least one element is inserted in the trie
                result[index] = maxXOR(root,element);
        }

        return result;
    }
};