/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//     bool hasCycle(ListNode *head) {
//         ListNode* pre = head;
//         ListNode* cur = head;
//         if (cur == NULL || cur->next == NULL) return false;
//         while (cur->next!= pre) {
//             if(cur->next){
//                 cur = cur->next;
//             }
//             if(cur->next){
//                 cur= cur->next;
//             }
//             if(cur->next == nullptr || cur == nullptr) {
//                 return false;
//             }
//             pre = pre->next;
//     }
//     return true;    
// }

// bool hasCycle(ListNode *head) {
//     if(head == nullptr) {
//         return false;
//     }    
//     ListNode *fast = head->next;
//     ListNode *slow = head;
//     while(fast != slow) {
//         if(fast == nullptr || fast->next == nullptr) {
//             return false;
//         }
//         fast = fast->next->next;
//         slow = slow->next;
//     }
//     return true;
// }

bool hasCycle(ListNode *head) {
    if(head == nullptr) return false;
    ListNode *fast = head->next;
    ListNode *slow = head;
    while(fast != slow){
        if(fast == nullptr || fast->next == nullptr) return false;
        fast = fast->next->next;
        slow = slow->next;
    }
    return true;
}
};
// @lc code=end

