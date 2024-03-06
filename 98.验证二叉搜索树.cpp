/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    vector<int> vec;
    void traversal(TreeNode* root){
        if(root == nullptr){
            return ;
        }
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        traversal(root);
        for(int i = 1; i < vec.size(); i++) {
            if(vec[i] <= vec[i-1]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

