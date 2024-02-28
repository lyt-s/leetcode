/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size();
        }

        unordered_set<int> nums_set;
        for(auto i : nums) {
            nums_set.insert(i);
        }
        int result = 1;
        for(int i : nums_set) {
            if(nums_set.count(i -1) == 0){
                int t = i+1;
                while(nums_set.count(t) != 0){
                    t++;
                }
                result = max(result,t -i);
            }else {
                continue;
            }
        }
        return result;
    }
};
// @lc code=end

