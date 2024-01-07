#include <iostream>
#include <vector>

std::string addSpaces(std::string s, std::vector<int>& spaces) {
        size_t old_size = s.size();
        size_t n = spaces.size();
         s.reserve(n + old_size);
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