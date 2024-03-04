/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
    vector<vector<int>> result();
    vector<int> path;
    void backtract(vector<int>& nums,vector<bool>& used){
        if(path.size() == nums.size()){
            result.emplace_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == false){
                used[i] = true;
                path.emplace_back(nums[i]);
                backtract(nums,used);
                used[i] = false;
                path.pop_back();
            }
        }
    }
public:
  vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        vector<bool> used(nums.size(),false);
        backtract(nums,used);
        return result;
    }
};
// @lc code=end

