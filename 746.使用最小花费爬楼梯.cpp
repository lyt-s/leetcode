/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int dp_0 = 0;
        int dp_1 = 0;
        for(int i = 2 ;i<= cost.size() ;i++){
           int sum = min(dp_1 + cost[i-1],dp_0+ cost[i-2]);

           dp_0 = dp_1;
            dp_1 = sum;
        }
        return dp_1;
    }
};
// @lc code=end

