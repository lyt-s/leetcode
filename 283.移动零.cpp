/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int result_i = 0;
        for (int i = 0; i < nums.size(); ++i){
            if(nums[i] != 0){
                nums[result_i++] = nums[i];
            }
        }
        for(; result_i < nums.size(); ++result_i){
            nums[result_i] = 0;
        }
        
    }
};
// @lc code=end

