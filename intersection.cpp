/* 两个数组的交集
Given two arrays, write a function to compute their intersection.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]

Note:

Each element in the result must be unique.
The result can be in any order.
*/

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		// 用unordered_set对nums1中的元素去重
		unordered_set<int> s1;
		for (auto e : nums1)
			s1.insert(e);
		
        // 用unordered_set对nums2中的元素去重
		unordered_set<int> s2;
		for (auto e : nums2)
			s2.insert(e);
		
        // 遍历s1，如果s1中某个元素在s2中出现过，即为交集
		vector<int> vRet;
		for (auto e : s1)
		{
			if (s2.find(e) != s2.end())
				vRet.push_back(e);
		}
		return vRet;
	}
};
