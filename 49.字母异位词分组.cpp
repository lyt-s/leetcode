/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       std::map<string, vector<string>> groups;
       std::vector<vector<string>> result;
       for(auto str : strs) {
            std::string key = str;
            sort(key.begin(), key.end());
            groups.emplace_back(str);
       }
       for(auto i : groups) {
        result.emplace_back(i.second);
       }
       return result;
    }
};
// @lc code=end

