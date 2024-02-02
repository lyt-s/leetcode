/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    std::deque<int> deque;
    MyStack() {
    }
    
    void push(int x) {
        deque.push_back(x);
    }
    
    int pop() {
        int result = deque.back();
        deque.pop_back();
        return result;
    }
    
    int top() {
        int result = deque.back();
        return result;

    }
    
    bool empty() {
        return deque.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

