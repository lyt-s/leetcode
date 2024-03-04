/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    // 单调栈
    // int trap(vector<int>& height) {
    //     if(height.size() <= 2){
    //         return 0;
    //     }
    //     stack<int> st;
    //     st.push(0);
    //     int sum =0;
    //     for(int i = 1; i < height.size(); i++){
    //         if(height[i] < height[st.top()]){
    //             st.push(i);
    //         }else if( height[i] == height[st.top()]){
    //             st.push(i);
    //         }else{
    //             while(!st.empty() && height[i] > height[st.top()]){
    //                 int mid = st.top();
    //                 st.pop();
    //                 if(!st.empty()){
    //                     int h = min(height[i], height[st.top()]) - height[mid];
    //                     int w = i - st.top() - 1;
    //                     sum += h*w;
    //                 }
    //             }
    //             st.push(i);
    //         }
    //     }
    //     return sum;
    // }

    int trap(vector<int>& height) {
        if(height.size() <= 2){
            return 0;
        }
        vector<int> LeftHeight(height.size(),0);
        vector<int> RightHeight(height.size(),0);

        LeftHeight[0] = height[0];
        for(int i = 1; i < height.size(); ++i) {
            LeftHeight[i] = max(height[i], LeftHeight[i-1]);
        }

        RightHeight[height.size() -1] = height[height.size() - 1];
        for(int i = height.size() - 2; i >= 0; i--) {
            RightHeight[i] = max(height[i],RightHeight[i + 1]);
        }

        int sum = 0;
        for(int i = 0; i < height.size(); i++){
            int count = min(RightHeight[i],LeftHeight[i]) - height[i];
            if(count > 0){
                sum += count;
            }
        }
        return sum;
    }
};
// @lc code=end

