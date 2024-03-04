/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode* curA = headA;
    //     ListNode* curB = headB;
    //     int lenA = 0,lenB =0;
    //     while(curA){
    //         curA = curA->next;
    //         lenA++;
    //     }
    //     while(curB){
    //         curB = curB->next;
    //         lenB++;
    //     }
    //     curA = headA;
    //     curB = headB;
    //     // 让curA为最长链表的头，lenA为其长度
    //     if (lenB > lenA) {
    //         swap (lenA, lenB);
    //         swap (curA, curB);
    //     }

    //     // 求长度差
    //     int gap = lenA - lenB;
    //     // 让curA和curB在同一起点上（末尾位置对齐）
    //     while (gap--) {
    //         curA = curA->next;
    //     }
    //     while(curA){
    //         if(curA == curB){
    //             return curA;
    //         }
    //         curA = curA->next;
    //         curB = curB->next;
    //     }
    //     return NULL;
    // }

    // 1. 初始化两个指针 pA 和 pB，分别指向链表 headA 和 headB 的头节点。
    // 2. 同时遍历两个链表，当指针 pA和 pB都到达末尾时，它们走过的路径长度相等。如果链表相交，它们会在相交节点相遇；如果链表不相交，它们会在末尾节点null相遇。
    //      遍历过程中，如果 pA 到达链表末尾，将其重置为链表 headB 的头节点；如果 pB 到达链表末尾，将其重置为链表 headA 的头节点。
    //      这样，当 pA 和 pB 再次到达链表末尾时，它们走过的节点数相等，且它们所经过的末尾部分节点完全相同。因此，如果链表相交，它们会在相交节点相遇；如果链表不相交，它们会在末尾节点（null）相遇。
    // 3. 返回相交节点或 null。
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *nodeA = headA;
        ListNode *nodeB = headB;
        while(nodeA != nullptr || nodeB != nullptr) {
            if(nodeA == nullptr ){
                nodeA = headB;
            }
            if(nodeB == nullptr){
                nodeB = headA;
            }
            if(nodeA == nodeB){
                return nodeA;
            }
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        return nullptr;
    }
};
// @lc code=end

