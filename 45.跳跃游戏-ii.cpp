/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return 0;
        }
        int curDistance = 0; // 当前覆盖最远距离下标
        int ans =0;             //记录走的最大步数
        int nextDistance =0; // 下一步覆盖最远距离下标
        for (int  i = 0; i < nums.size(); i++)
        {
           nextDistance = max(nums[i] +i,nextDistance); // 更新下一步覆盖最远距离下标
           if (i == curDistance)        // 遇到当前覆盖最远距离下标
           {
            ans ++;
            curDistance = nextDistance;
            if (nextDistance >= nums.size()-1)
            {
                break;
            }
            
           }
        }
        return ans;
    }
};
// @lc code=end

