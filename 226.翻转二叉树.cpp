/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // TreeNode* invertTree(TreeNode* root) {
    //     if(root == NULL) return NULL;
    //     stack<TreeNode*> st;
    //     st.push(root);
    //     while(!st.empty()){
    //         TreeNode* node = st.top();
    //         st.pop();
    //         swap(node->left, node->right);
    //         if(node->right) st.push(node->right);
    //         if(node->left) st.push(node->left);
    //     }
    //     return root;
    // }

    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right);
                if(node->left) que.push(node->left); 
                if(node->right) que.push(node->right); 
            }
        }
        return root;
    }
};
// @lc code=end

