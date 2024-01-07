/*
 * @lc app=leetcode.cn id=2109 lang=cpp
 *
 * [2109] 向字符串添加空格
 */

/**
std::string addSpaces(std::string s, std::vector<int>& spaces) {
        size_t old_size = s.size();
        size_t n = spaces.size();
         s.resize(n + old_size);
         size_t new_size = s.size();

        for (int i = new_size -1, j = old_size -1; j < i ; i--){
            if ( n >= 0 && spaces[n-1] == j){
                s[i--] = s[j];
                j--;
                s[i] = ' ';
                n--;
            }else{    
                s[i] = s[j];
                j--;
            }
        }
        return s;
}


int main(){
    std::string str = "LeetcodeHelpsMeLearn";
    std::vector<int> vec{8,13,15};
    auto result = addSpaces(str,vec);
    std::cout << result << std::endl;
    return 0;
}
*/
// @lc code=start
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        size_t old_size = s.size();
        size_t n = spaces.size();
         s.resize(n + old_size);
         size_t new_size = s.size();

        for (int i = new_size -1, j = old_size -1; j < i ; i--,j--){
            if ( n >= 0 && spaces[n-1] == j){
                s[i--] = s[j];
                s[i] = ' ';
                n--;
            }else{    
                s[i] = s[j];
            }
        }
        return s;
    }
};
// @lc code=end

