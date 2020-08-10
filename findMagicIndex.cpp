/* 魔术索引
A magic index in an array A[0...n-1] is defined to be an index such that A[i] = i. Given a sorted array of integers, write a method to find a magic index, 
if one exists, in array A. If not, return -1. If there are more than one magic index, return the smallest one.

Example1:
Input: nums = [0, 2, 3, 4, 5]
Output: 0

Example2:
Input: nums = [1, 1, 1]
Output: 1
*/

int findMagicIndex(vector<int>& nums) {
    int index = 0;
    int len = nums.size();
    while (index < len) {
        if (nums[index] == index)
            return index;
        else if (nums[index] > index)
            index = nums[index];
        else
            ++index;
    }
    return index >= len ? -1 : index;
}
