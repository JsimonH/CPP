/* 最接近的三数之和
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size(); ++i) {
            int start = i + 1; 
            int end = nums.size() - 1;
            while(start < end) {
                int sum = nums[start] + nums[end] + nums[i];
                if(abs(target - sum) < abs(target - res))
                    res = sum;
                if(sum > target)
                    end--;
                else if(sum < target)
                    start++;
                else
                    return res;
            }
        }
        return res;
    }
};
