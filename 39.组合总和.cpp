/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
    vector<vector<int>> result;
    vector<int> path;

    void backtrack(vector<int>& nums, int target,int start){
        if(target == 0){
            result.push_back(path);
            return;
        }
        if(target < 0){
            return;
        }

        for(int i = start; i < nums.size(); ++i){
            target -= nums[i];
            path.push_back(nums[i]);
            backtrack(nums,target,i);
            target += nums[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target,0);
        return result;
    }
};
// @lc code=end

