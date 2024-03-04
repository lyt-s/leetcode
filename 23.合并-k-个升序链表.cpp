/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        ListNode *prev = new ListNode(0);
        ListNode *dummy = prev;
        while(l1 && l2) {
            if(l1->val <= l2->val){
                prev->next = l1;
                l1 = l1->next;
                prev = prev->next;
            }else {
                prev->next = l2;
                l2 = l2->next;
                prev = prev->next;
            }
        }
        prev->next = l1 != nullptr ? l1 : l2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = nullptr;
        for( int i = 0; i < lists.size();++i){
            result = mergeTwoLists(result, lists[i]);
        }
        return result;
    }
};
// @lc code=end

