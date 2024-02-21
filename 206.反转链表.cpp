/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    // 迭代法
    // ListNode* reverseList(ListNode* head) {
    //     ListNode *prev = new ListNode(0);
    //     ListNode *cur = head;
    //     prev->next = nullptr;
    //     while(cur){
    //         ListNode *temp = cur->next;
    //         cur->next = prev->next;
    //         prev->next = cur;
    //         cur = temp;
    //     }   
    //     return prev->next;
    // }

    ListNode *reverseList(ListNode *head){
        if(head == nullptr || head->next == nullptr){
            return head;
        } 

        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return new_head;
    }

};
// @lc code=end

