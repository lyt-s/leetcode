/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1){
            return n;
        }

        vector<int> dp(n +1,0);
        dp[2] =2;   
        dp[1] =1;

        for(size_t i = 3; i <= n  ; ++i){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];

    }
};
// @lc code=end

