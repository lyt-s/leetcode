/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int n = s.size();
        int right_k = -1, ans = 0;
        for(int i  =0; i< n; ++i){
            if(i != 0){
                occ.erase(s[i-1]);  
            }
            while(right_k + 1 < n && !occ.count(s[right_k +1])){
                occ.insert(s[right_k +1]);
                ++right_k;
            }
            ans = max(ans, right_k -i +1);
        }
        return ans;
    }
    
};
// @lc code=end

