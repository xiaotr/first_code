/**
题目：leetcode_144、二叉树前序遍历

描述：给定一个二叉树，返回它的 前序 遍历。


**/

//code

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root)
        {
            res.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return res;
    }
    */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* r = root;
        stack<TreeNode*> s;
        while(r || !s.empty())
        {
            while(r)
            {
                res.push_back(r->val);
                s.push(r);
                r = r->left;
            }
            if(!s.empty())
            {
                r = s.top();
                s.pop();
                r = r->right;
            }
        }
        return res;
    }
};