/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    // 单调栈
    int trap(vector<int>& height) {
       if(height.size() <= 2){
        return 0;
       }

       stack<int> st;
       st.push(0); // 放的是下标
       int sum =0;
      for(int i = 1; i < height.size();++i){
        if(height[i] < height[st.top()]){
            st.push(i);
        }else if(height[i] == height[st.top()]){
            st.push(i);
        }else{
            while(!st.empty() && height[i] > height[st.top()]){
                int middle = st.top();
                st.pop();
                if(!st.empty()){
                    int h = min(height[i] , height[st.top()]) - height[middle];
                    int w = i - st.top() -1;
                    sum += h * w;
                }
            }
            st.push(i);
        }
      }   
      return sum;
    }
    // int trap(vector<int>& height) {
    //     if(height.size() < 2){
    //         return 0;
    //     }
    //     int size = height.size();
    //     vector<int> maxRightHeight(size,0);
    //     vector<int> maxLeftHeight(size,0);

    //     maxRightHeight[size-1] = height[size-1];
    //     for(int i = size -2; i >= 0; i--){
    //         maxRightHeight[i] = max(maxRightHeight[i+1],height[i]);
    //     }

    //     maxLeftHeight[0] = height[0];
    //     for(int i = 1; i < size; i++){
    //         maxLeftHeight[i] = max(maxLeftHeight[i-1],height[i]);
    //     }

    //     int sum = 0;
    //     for(int i = 0; i < size; i++){
    //         int count = min(maxRightHeight[i],maxLeftHeight[i]) - height[i];
    //         if(count > 0){
    //             sum += count;
    //         }
    //     }
    //     return sum;
    // }
};
// @lc code=end

