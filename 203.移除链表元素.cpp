/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    // ListNode* removeElements(ListNode* head, int val) {
    //    while(head != nullptr && head->val == val) {
    //     ListNode *tmp = head;
    //     head = head->next;
    //     delete tmp;
    //    }

    //    ListNode *cur = head;
    //    while(cur != nullptr && cur->next != nullptr) {
    //     if(cur->next->val == val) {
    //         ListNode *tmp = cur->next;
    //         cur->next = cur->next->next;
    //         delete tmp;
    //     }else{
    //         cur = cur->next;
    //     }
    //    }
    //    return head;
    // }
    ListNode *removeElements(ListNode *head, int val){
        while(head!= nullptr && head->val == val){
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
        ListNode *cur = head;
        while(cur != nullptr && cur->next != nullptr){
            if(cur->next->val == val){
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }else{
                cur = cur->next;
            }
        }
        return head;
    }
};
// @lc code=end

