/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
string minWindow(string s, string t) {
    unordered_map<char,int> need,window;
    for(auto c : t) {
        need[c]++;
    }
    int left = 0;
    int right = 0;
    int len = INT_MAX;
    int start = 0;
    int valid = 0;
    while(right < s.size()){

        char c = s[right];
        // 右移窗口
        right++;

        // 判断是否有用
        if(need.count(c)){
            window[c]++;
            if(window[c] == need[c]){
                valid++;
            }
        }


        // 左侧窗口是否收缩
        while(valid == need.size()){
            // 先更新最小的字串
            if(right - left < len){
                start = left;
                len = right - left;
            }
            
            char d = s[left];
            left++;
            // 对窗口进行一系列更新
            if(need.count(d)){
                // 字串数量中某个字母相等的话，left左移后肯定就不相等了，所以valid--，
                if(window[d] == need[d]){
                    valid--;
                }
                window[d]--;
            }
        }
    }

    return len == INT_MAX ? "" : s.substr(start,len);
}

};
// @lc code=end

