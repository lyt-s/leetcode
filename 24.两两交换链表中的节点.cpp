/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    // ListNode* swapPairs(ListNode* head) {
    //     if (head == nullptr || head->next == nullptr) {
    //         return head;
    //     }
    //     ListNode *dummy = new ListNode(0);

    //     dummy->next = head;
    //     ListNode* pre = dummy;
    //     ListNode* cur = head;
    //     ListNode* tail = cur->next;
    //     while(tail && cur){
    //         // 防止断链
    //         ListNode *tmp = tail->next;

    //         // 两两交换
    //         pre->next = tail;
    //         tail->next = cur;
    //         cur->next = tmp;

    //         // 进行下一轮的交换
    //         pre = cur;
    //         if(tmp == nullptr) {
    //             cur->next = nullptr;
    //             return dummy->next;
    //         }
    //         cur = tmp;
    //         tail = cur->next;
    //     }
    //     return dummy->next;
    // }

    // 1. 防止断链
    // 2. temp 记着检测是否为空，否则next指针会出问题
    

    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* pre = new ListNode(0);
        ListNode* dummy = pre;
        dummy->next = head;
        ListNode* cur = head;
        ListNode* next = cur->next;

        while(cur && cur->next){
            // 防止断链
            ListNode* temp = next->next;

            // 进行交换
            pre->next = next;
            next->next = cur;
            cur->next = temp;

            // 下一轮准备
            pre = cur;
            if(temp == nullptr){
                cur->next = nullptr;
                return dummy->next;
            }
            cur = temp;
            next = cur->next;
        }
        return dummy->next;
    }
};
// @lc code=end

