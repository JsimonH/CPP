/* 重复N次的元素
In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.
Return the element repeated N times.

Example 1:
Input: [1,2,3,3]
Output: 3

Example 2:
Input: [2,1,2,5,3,2]
Output: 2

Example 3:
Input: [5,1,5,2,5,3,5,4]
Output: 5
*/

class Solution {
public:
	int repeatedNTimes(vector<int>& A) {
		size_t N = A.size() / 2;
		// 用unordered_map统计每个元素出现的次数
		unordered_map<int, int> m;
		for (auto e : A)
			m[e]++;
		// 找出出现次数为N的元素
		for (auto& e : m)
		{
			if (e.second == N)
				return e.first;
		}
        return -1;
	}
};
