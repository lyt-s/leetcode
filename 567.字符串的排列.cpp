/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> need, window;
        int left =0, right = 0;
        int valid = 0;
        for(auto i : s1){
            need[i]++;
        }

        while(right < s2.size()){

            char c = s2[right];
            right++;

            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c]){
                    valid++;
                }
            }

            // 左侧收缩
            while(right - left == s1.size()){
                if(valid == need.size()){
                    return true;
                }
                char d = s2[left];
                left++;
                if(need.count(d)){
                    if(window[d] == need[d]){
                        valid--;  
                    }
                    window[d]--;
                }
            }
        }
        return false;
    }
};
// @lc code=end

