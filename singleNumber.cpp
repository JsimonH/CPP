/* Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Input: [2,2,3,2]
Output: 3

Input: [0,1,0,1,0,1,99]
Output: 99
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 统计所有数32个位出现1的次数
        int bit_count[32] = {0};
        for(auto e : nums)
        {
            for(int i = 0; i < 32; ++i)
            {
                if((e >> i) & 1)
                {
                    ++bit_count[i];
                }
            }
        }

        int find = 0;
        for(int i = 0; i < 32; ++i)
        {
            if(bit_count[i] % 3 == 1)
            {
                find ^= (1 << i);
            }
        }
        return find;
    }
};
