/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    int result = 1;
    vector<int> dp(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i - 1]) { // 连续记录
        dp[i] = dp[i - 1] + 1;
      }
      if (dp[i] > result)
        result = dp[i];
    }
    return result;
  }
};
// @lc code=end
