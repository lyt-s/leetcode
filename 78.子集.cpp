/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> results;
    vector<int> path;
    void backtracking(vector<int>& nums,int startIndex){
        results.push_back(path);
        if(startIndex > nums.size()){
            return;
        }
        for (int  i = startIndex; i < nums.size(); i++) {
           path.push_back(nums[i]);
           backtracking(nums,i+1);
           path.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        results.clear();
        path.clear();
        backtracking(nums,0);
        return results;
    }
};
// @lc code=end

