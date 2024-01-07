/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for (int i=0; i<nums.size();i++){
            sum += nums[i];
        }
        if((sum + target ) % 2 != 0){
            return 0;
        }
        if(abs(target) > sum){
            return 0;
        }
        // left - right = target;
        // sum = left + right
        // 2 left - sum = target
        int left = (target +sum)/2;
        vector<int> dp(left +1,0);
        for(int i = 0; i < nums.size(); i++){
            for(int j = left; j >= nums[i];j--){
                dp[j] += dp[j - nums[i]];
            }
        }
    }
};
// @lc code=end

