/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {

public:
    // 定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };
    MyLinkedList() {
        m_dummyHead = new LinkedNode(0);
        m_size = 0;
    }
    
    int get(int index) {
        if (index > (m_size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* cur = m_dummyHead->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = m_dummyHead->next;
        m_dummyHead->next = newNode;
        m_size++;

    }
    
    void addAtTail(int val) {
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *curr = m_dummyHead->next;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        newNode->next = nullptr;
        curr->next = newNode;
        m_size++;
    }
    
    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则在头部插入节点
    void addAtIndex(int index, int val) {
        if(index <= 0) {
            addAtHead(val);
        }else if(index == m_size -1){
            addAtTail(val);
        }else{
            LinkedNode* newNode = new LinkedNode(val);
            LinkedNode* cur = m_dummyHead;
            while(index--) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
            m_size++;
        }

    }
    
    void deleteAtIndex(int index) {
        if (index >= m_size || index < 0) {
            return;
        }
        LinkedNode* cur = m_dummyHead;
        while(index--) {
            cur = cur ->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        //delete命令指示释放了tmp指针原本所指的那部分内存，
        //被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
        //如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
        //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
        tmp=nullptr;
        m_size--;
    }

    private:
    int m_size;
    LinkedNode* m_dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

