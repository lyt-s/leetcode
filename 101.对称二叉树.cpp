/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool compare(TreeNode *left, TreeNode *right) {
        if(left == nullptr && right != nullptr) return false;
        else if(left != nullptr && right == nullptr) return false;
        else if(left == nullptr && right == nullptr) return true;
        else if(left->val != right->val) return false;


        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right,right->left);
        bool isSame = outside && inside;
        return isSame;
    }
public:
    // bool isSymmetric(TreeNode* root) {
    //     if(root == nullptr) return true;
    //     return compare(root->left,root->right);
    // }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);

        while(!que.empty()) {
            TreeNode* leftNode = que.front(); 
            que.pop();
            TreeNode* rightNode = que.front();
            que.pop();
            if(leftNode == nullptr && rightNode == nullptr){
                continue;
            }

            if(leftNode == nullptr || rightNode == nullptr || (leftNode->val != rightNode->val)){
                return false;
            }
            que.push(leftNode->left);
            que.push(rightNode->right);
            que.push(leftNode->right);
            que.push(rightNode->left);
        }
        return true;
    }
};
// @lc code=end

