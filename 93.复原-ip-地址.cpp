/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> results;
    // startIndex: 搜索的起始位置，pointNum:添加逗点数量
    void backtracking(string &s, int startIndex, int pointNum){
        if (pointNum == 3)
        {
            if (isValid(s,startIndex, s.size()-1)){
                results.push_back(s);
            }
            return;  
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isValid(s,startIndex,i))
            {
                s.insert(s.begin()+i+1,'.');
                pointNum++;
                backtracking(s,i+2,pointNum);
                pointNum--;
                s.erase(s.begin()+i+1);
            }else break;
            
        }
        
        
    }
    bool isValid(const string& s,int start, int end){
        if (start> end)
        {
           return false;
        }
        if (s[start] == '0' && start != end)
        {
            return false;
        }
        int num=0;
        for (int  i = start; i <= end; i++)
        {
            if (s[i] > '9' || s[i] < '0')
            {
               return false;
            }
            num = num*10 + (s[i] - '0');
            if (num >255)
            {
                return false;
            }
        }
        return true; 
    }
    vector<string> restoreIpAddresses(string s) {
        results.clear();
        if (s.size() < 4||s.size() >12)
        {
            return results;
        }
        backtracking(s,0,0);
        return results;
    }
};
// @lc code=end

