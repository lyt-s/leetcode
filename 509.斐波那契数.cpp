/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if(n ==0 || n == 1) return n;
        vector<int> vec(n + 1);
        vec[0] =0;
        vec[1] =1;
        for (size_t i = 2; i <= n; i++) {
            vec[i] = vec[i-1] + vec[i-2];
        }
        return vec[n];
    }
};
// @lc code=end

