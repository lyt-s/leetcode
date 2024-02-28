/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> hashmap;
        for(int i = 0; i< nums.size(); i++){
            auto it = hashmap.find(target - nums[i]);
            if(it == hashmap.end()){
                hashmap[nums[i]] = i; // 将当前遍历的节点的位置记录下来
            }else{
                result.push_back(i);
                result.push_back(hashmap[target - nums[i]]);
            }
        }
        return result;
    }
};
// @lc code=end

