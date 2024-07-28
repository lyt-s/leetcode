/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int temp = 0;
        for(int i =0; i < k; i++) {
            temp = max(temp,nums[i]);
        }
        result.push_back(temp);
        if(nums.size() <= k){
            return result;
        }
        for(int i = k; i < nums.size(); ++i){
            if(temp <= nums[i]){
                temp = nums[i];
                result.push_back(temp);
            }else if(temp == nums[i-k]){
                temp = INT_MIN;
                for(int j = i -k + 1; j < i +1;j++){
                    temp = max(temp,nums[j]);
                }
                result.push_back(temp);
            }else{
                result.push_back(temp);
            }
        }
        return result;
    }
};
// @lc code=end

