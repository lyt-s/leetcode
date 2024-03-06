/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*> que;
        int result = 0;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* temp = que.front();
                que.pop();
                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }
            }
            result++;
        }
        return result;
    }
};
// @lc code=end

