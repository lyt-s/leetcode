/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(true){
            // 这里假设 a为环之前的节点数，b为环的节点数.
            // 这里 fast 总共走了 f = 2s  = s + nb
            // slow  总共走了  s = nb
            if(fast == NULL || fast->next == NULL){
                return NULL;
            }
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                break;
            }
        }
        // 找到 环的起始节点，就是 a + nb 的节点位置，就是环的起始节点，所以f 和 s 重合后，
        // 再走 a 步，就是环的终止节点。
        slow = head;
        while(slow!= fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
// @lc code=end

