/* Kth Largest Element in an  Array
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth 
distinct element.

Input: [3,2,1,5,6,4] and k = 2
Output: 5

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
*/

// 方法一:
// 时间复杂度O(N*logN)
// 空间复杂度O(N)
class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto num : nums)
        {
            pq.push(num);
        }
        
        while(--k)
        {
            pq.pop();
        }
        return pq.top();
    }
};

// 方法二:
// 时间复杂度O(N*logN)
// 空间复杂度O(1)
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

// 方法三:
// 时间复杂度O(N*logk)
// 空间复杂度O(k)
class Solution3 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 建立k个数的小堆
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int i;
        for(i = 0; i < k; ++i)
            minHeap.push(nums[i]);
        
        for(i = k; i < nums.size(); ++i)
        {
            if(nums[i] > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};
