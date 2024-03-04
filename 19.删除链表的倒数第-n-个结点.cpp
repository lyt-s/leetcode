/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     ListNode *dummyHead = new ListNode(0);
    //     dummyHead->next = head;
    //     // 应对 一个节点，且删除倒数第一的节点，所以其实要在头节点前一个结点
    //     ListNode *slow = dummyHead;
    //     ListNode *fast = dummyHead;
    //     for(int i = 0; i < n; i++) {
    //         if(fast != nullptr) {
    //             fast = fast->next;
    //         }
    //     }
    //     fast = fast->next;
    //     while(fast != nullptr){
    //         fast = fast->next;
    //         slow = slow->next;
    //     }
    //     ListNode *temp = slow->next;
    //     slow->next = temp->next;
    //     delete temp;
    //     return dummyHead->next;
    // }


    ListNode* removeNthFromEnd(ListNode* head, int n) {\
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        // 应对删除头节点情况
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while(n){
            fast = fast->next;
            n--;
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;
        // 返回不要返回head，head可能会删除
        return dummy->next;
    }
};
// @lc code=end

