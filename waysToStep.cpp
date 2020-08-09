/* 三步问题
A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many possible ways the child 
can run up the stairs. The result may be large, so return it modulo 1000000007.

Example1:
Input: n = 3 
Output: 4

Example2:
Input: n = 5
Output: 13
*/

class Solution {
public:
    int waysToStep(int n) {
        if(n <= 2)
            return n;
        vector<int> vec(n+1,0);
        vec[1] = 1;
        vec[2] = 2;
        vec[3] = 4;
        for(int i=4;i<=n;i++)
            vec[i] = (vec[i-1] + (vec[i-2] + vec[i-3]) % 1000000007) % 1000000007;
        return vec[n];
    }
};
