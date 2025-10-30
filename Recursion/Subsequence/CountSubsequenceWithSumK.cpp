class Solution {
  public:
    void helper(vector<int> & arr, int target, int index, int sum,int & count)
    {
        if(index == arr.size())
        {
            if (sum == target) { // Check if sum equals target
                count++;
            }
            return;
        }
        
        helper(arr,target,index+1,sum+arr[index],count);
        //don't count sum
        helper(arr,target,index+1,sum,count);
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int count = 0;
        helper(arr,target,0,0,count);
        return count;
    }
};