/*
We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/

class Solution {
public:
    bool diffSigns(int a, int b)
    {
        return (a>0 && b<0);
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s;
        
        for(int i = 0; i<n; ++i)
        {
            bool flag = true;
            while(!s.empty() && diffSigns(asteroids[s.top()],asteroids[i]))
            {
                int a = asteroids[s.top()];
                int b = asteroids[i];
                if(abs(a) == abs(b))
                {
                    s.pop();
                    flag = false;
                    break;
                }
                else if(abs(a)>abs(b))
                {
                    flag = false;
                    break;
                }else
                {
                    s.pop();
                }
            }
            if(flag)
                s.push(i);
        }

        vector<int> ans;
        while(!s.empty())
        {
            ans.push_back(asteroids[s.top()]);
            s.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};


