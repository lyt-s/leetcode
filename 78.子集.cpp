/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
    vector<vector<int>> results;
    vector<int> path;

    void backtrack(vector<int>& nums,int startIndex){
        if(path.size() > nums.size()){
            return;
        }
        results.emplace_back(path);

        for(int i = startIndex; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtrack(nums,i + 1);
            path.pop_back();
        }
    }
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        results.clear();
        path.clear();
        backtrack(nums,0);
        return results;
    }
};
// @lc code=end

