/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(15001,0);
        int sum = accumulate(stones.begin(),stones.end(),0);
        int target = sum/2;

        for(int i = 0; i < stones.size();i++){
            for(int j = target;j>= stones[i];j--){
                dp[j] = max(dp[j],dp[j-stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};
// @lc code=end

