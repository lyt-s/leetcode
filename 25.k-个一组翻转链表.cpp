/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     // 链表是否为空或k是否为1
    //     if(head == nullptr || head->next == nullptr){
    //         return head;
    //     } 
    //     int count = 0;
    //     for (ListNode *cur = head; cur; cur = cur->next){
    //         ++count; // 统计节点个数
    //     }
    //     ListNode *dummy = new ListNode(0);
    //     ListNode *prev = new ListNode(0);
    //     dummy = prev;
    //     prev->next = nullptr;
    //     ListNode *curr = head , *temp;
    //     ListNode* next_start = curr;  // 下一次 k循环启动的节点

    //     while(count >= k){
    //         for(int i = 0; i < k; i++){
    //             temp = curr->next;
    //             curr->next = prev->next;
    //             prev->next = curr;
    //             curr = temp;
    //         }
    //         prev = next_start;
    //         next_start->next = curr;
    //         next_start = curr;
    //         count-=k;
    //     }
    //     return dummy->next;
    // }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // 统计节点个数
        int count = 0;  
        ListNode* count_node = head;
        while(count_node){
            count_node = count_node->next;
            count++;
        }

        ListNode* pre = new ListNode(-1);
        pre->next = nullptr;
        ListNode* dummy = pre;
        ListNode* next_k_start = head;
        ListNode* cur = head;
        for(;count >= k; count-=k){
            for(int j = 0; j < k; j++){
                ListNode* temp = cur->next;
                cur->next = pre->next;
                pre->next = cur;
                cur = temp;
            }
            // 防止断链
            next_k_start->next = cur;
            // 下一次k次反转，pre所在的位置
            pre = next_k_start;
            // 记录k次反转前，第一个节点
            next_k_start = cur;
        }
        return dummy->next;
    }

};
// @lc code=end

