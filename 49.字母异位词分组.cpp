/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> groups;

        for(auto &str : strs){
            string key = str;
            sort(key.begin(), key.end());
            groups[key].push_back(str);
        }

        for(auto i : groups){
            result.push_back(i.second);
        }
        return result;
    }
};
// @lc code=end

