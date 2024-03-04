/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        results.clear();
        path.clear();
        backtracking(nums,0);
        return results;
    }
};
// @lc code=end

