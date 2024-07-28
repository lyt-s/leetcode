/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() -2;++i){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            // if(nums[i] > 0){
            //     return result;
            // }

            int left = i +1;
            int right = nums.size() - 1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }else if(nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }else{
                    result.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    while(left < right && nums[left] == nums[left+1]){
                        left++;
                    }
                    while(right > left && nums[right] == nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};
// @lc code=end

