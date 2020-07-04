/* 剑指 Offer 61.扑克牌中的顺子
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

示例 1:
输入: [1,2,3,4,5]
输出: True
 
示例 2:
输入: [0,0,1,2,5]
输出: True
*/

/* 排序之后我们就可以直接判断相邻两张牌之间需要多少个大王或小王来填补。

如果需要填补大小王的数量，大于已有大小王的数量，则返回 false.
相反，如果需要填补大小王的数量，小于或等于已有大小王的数量，则返回 true */


class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zero = 0;
        for (int i = 0; i < 4; i ++) {
            if (nums[i] == 0) 
            {
                zero++;
                continue;
            } 
            if (nums[i] == nums[i+1]) 
            {
                return false;
            }
            zero -= nums[i+1]-nums[i] - 1;
        }
        return zero >= 0;
    }
};
