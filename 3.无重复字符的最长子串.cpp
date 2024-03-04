/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     // 滑动窗口，先定义窗口
    //     unordered_set<char> un_set;
    //     // 定义窗口右指针,初始窗口为0
    //     int right_point = -1;
    //     int result = 0 ; // 记录最长的字串长度
    //     for(int i = 0; i < s.size(); ++i){
    //         // 序列不符合不重复时， 会从while中跳出，然后左指针进行向右移动
    //         if(i != 0){
    //             un_set.erase(s[i - 1]); // 移动时，删除窗口中对应的内容
    //         }
    //         // 这里的条件时，右指针，不能超过整的字符的长度，并且窗口内的元素不能重复
    //         while(right_point + 1 < s.size() && un_set.count(s[right_point + 1]) == 0){
    //             un_set.insert(s[right_point + 1]); // 之移动 右指针，当不符合时，在移动左指针
    //             right_point += 1; // 窗口进行增加，
    //         }
    //         // 当不重复的字符的窗口最大时，记录result，
    //         result = max(result,right_point - i +1);
    //     }
    //     return result;

    // }


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

    int lengthOfLongestSubstring(string s) {
        unordered_set<char> un_set;
        int right_k = -1;
        int result = 0;
        for(int i = 0; i < s.length(); ++i){
            if( i != 0){
                un_set.erase(s[i-1]);
            }
            while(right_k +1 <s.length() && un_set.count(s[right_k + 1]) == 0){
                un_set.insert(s[right_k + 1]);
                right_k++;
            }
            result = max(result, right_k - i +1);
        }
        return result;
    }
};
// @lc code=end

