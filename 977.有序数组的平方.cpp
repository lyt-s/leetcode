/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int index = nums.size()-1;
        vector<int> result(nums.size(),0);
        for(size_t i = 0 , j = nums.size()-1; i <= j && index >= 0; ) {
            if(nums[i]* nums[i] > nums[j]*nums[j]){
                result[index--] = nums[i]*nums[i];
                i++;
            }else {
                result[index--] = nums[j]*nums[j];
                j--;
            }
        }
        return result;

    }
};
// @lc code=end

