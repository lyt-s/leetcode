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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *dummyHeade = dummy;

        while (n--&&dummy!=NULL){
            dummy=dummy->next;
            if(dummy == nullptr && n) {
                return nullptr;
            }
        }
        // 这里dummy->next != nullptr ,就是为了让pre指向删除节点的上一个节点。
        while(dummy->next!=NULL){
            pre=pre->next;
            dummy=dummy->next;
        }

        ListNode *temp = pre->next;
        pre->next = temp->next;
        delete temp;
        return dummyHeade->next;
    }
};
// @lc code=end

