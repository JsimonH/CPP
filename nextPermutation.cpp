/* 下一个排列
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		//从后往前找，直到找到当前元素大于前一个元素为止
        int pos = nums.size() - 1;
		while (pos > 0 && nums[pos] <= nums[pos - 1])
			pos--;
		reverse(nums.begin() + pos, nums.end());  //逆序
		
        if (pos > 0) { //寻找第一个大于nums[pos - 1]的数
			for (int start = pos; start < nums.size(); ++start) { 
				if (nums[start] > nums[pos - 1]) {
					swap(nums[start], nums[pos - 1]); //交换
					break;
				}
			}
		}
	}
};
