/* 两个数组的交集I
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
        // 利用unordered_map进行去重
        unordered_set<int> us1, us2;
        for (auto& e : nums1) 
            us1.insert(e);
        for (auto& e : nums2) 
            us2.insert(e);
        
        vector<int> res;
        for (auto& e : us1) {
            if (us2.find(e) != us2.end())
                res.push_back(e);
        }
        return res;
    }
};

/* 两个数组的交集II
Given two arrays, write a function to compute their intersection.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> us1, us2;
        for (auto& e : nums1) 
            us1.insert(e);
        for (auto& e : nums2) 
            us2.insert(e);
        
        vector<int> res;
        for (auto& e : us2) {
            auto it = us1.find(e);
            if (it != us1.end()) {
                us1.erase(it);
                res.push_back(e);
            }
        }
        return res;
    }
};
