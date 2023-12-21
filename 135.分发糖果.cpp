/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(),1);
        // 从前往后
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i-1])
            {
               candyVec[i] = candyVec[i-1] + 1;
            }
            
        }
        // 从后向前
        for (int i = ratings.size(); i >= 0; i--)
        {
            if (ratings[i] > ratings[i+1])
            {
                candyVec[i] = max(candyVec[i],candyVec[i+1] +1);
            }
            
        }
        int result = 0;
        for (int  i = 0; i < cnadyVec.size(); i++)
        {
           result+=candyVec[i];
        }
        return result ;
    }
};
// @lc code=end

