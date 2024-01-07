/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;
        int i =0;
        int subLength = 0;
        int sum = 0;
        for(int j = 0; j < nums.size();j++){
            sum += nums[j];
            while(sum >= target){
                subLength = (j -i + 1) ;
                result = result < subLength ? result : subLength;
                sum -= nums[i++];
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};
// @lc code=end

