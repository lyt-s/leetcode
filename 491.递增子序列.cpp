/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution {
public:
        vector<vector<int>> result;
        vector<int> path;
        void backtracking(vector<int>&nums,int startIndex){
            if (path.size() > 1)
            {
               result.push_back(path);
            }
            unordered_set<int> uset;

            for (int i = startIndex; i < nums.size(); i++)
            {
                if (!path.empty()&& nums[i] < path.back()
                        || uset.find(nums[i]) != uset.end())
                {
                    continue;
                }
                uset.insert(nums[i]);
                path.push_back(nums[i]);
                backtracking(nums,i+1);
                path.pop_back();
            }
            
            
        }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
       backtracking(nums,0);
       return result;
    }
};
// @lc code=end

