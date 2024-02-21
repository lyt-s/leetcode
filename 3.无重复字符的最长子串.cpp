/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uset;
        int n = s.size();
        int right_k = -1;
        int result = 0;
        for (int i = 0; i < n;i++) {
            if(i != 0){
              uset.erase(s[i -1]);  
            }
            while(right_k + 1  < n && uset.count(s[right_k + 1]) == 0){
                uset.insert(s[right_k + 1]);
                ++right_k;
                result = max(result, right_k - i +1);
            }
        }
        return result;
    }


    // int lengthOfLongestSubstring(string s) {
    //     unordered_map<char,int> dic; // [字符，坐标]
    //     int left = -1, result = 0 , len = s.size();
    //     for (int i = 0; i < len ; i++){
    //         if(dic.find(s[i]) != dic.end()){
    //             left = max(left , dic.find(s[i])->second); // 更新左指针
    //         }
    //         dic[s[i]] = i; // 哈希记录
    //         result = max(result, i - left); // 更新结果
    //     }
    //     return result;
    // }
};
// @lc code=end

