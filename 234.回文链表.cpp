/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 时间O(n),空间O(n)
    // bool isPalindrome(ListNode* head) {
    //     vector<int> vec;
    //     while(head){
    //         vec.emplace_back(head->val);
    //         head = head->next;
    //     }
    //     for(int i = 0, j = vec.size()-1; i <= j; i++,j--){
    //         if(vec[i] == vec[j]) {
    //             continue;
    //         }else{
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    ListNode * reverseList(ListNode *head){
        ListNode *pre = new ListNode(-1);
        ListNode *cur = head;
        pre->next = nullptr;
        while(cur){
           ListNode *temp = cur->next;
           cur->next = pre->next;
           pre->next = cur;
           cur = temp;
        }
        return pre;
    }
    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast){
            if(fast->next != nullptr && fast->next->next != nullptr){
                fast = fast->next->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        int length = 0;
        ListNode *cur = head;
        // 记录链表节点数量
        while(cur){
            cur = cur->next;
            length++;
        }
        if(length <= 1){
            return true;
        }
        // 反转前半段
        ListNode *pre = new ListNode(-1);
        cur = head;
        pre->next = nullptr;
        for(int i = 0 ; i < length/2 ; i++){
            ListNode *temp = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = temp;
        }
        // 处理节点数为奇数的情况
        if(length%2){
            cur = cur->next;
        }
        while(cur){
            if(cur->val != pre->next->val){
                return false;
            }
            cur = cur->next;
            pre = pre->next;
        }
        return true;
    }
};
// @lc code=end

