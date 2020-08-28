/* 在排序数组中查找元素的第一个和最后一个位置
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) 
            return {-1,-1};

        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            int mid = (left + right) >> 1;
            if(nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if(nums[left] != target) 
            return {-1,-1};
        
        int start = left;
        left = 0;
        right = nums.size() - 1;
        while(left < right) {
            int mid = (left + right + 1) >> 1;
            if(nums[mid] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        if(nums[left] != target) 
            return {-1,-1};
        int end = right;
        
        return {start,end};
    }
};
