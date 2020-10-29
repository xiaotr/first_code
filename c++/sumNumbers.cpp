/**
题目：leetcode_129、求根到叶子节点数字之和

描述：给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

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
    void dfs(TreeNode* root, int& tmp, int& res)
    {
        if(!root)
            return;
        tmp = tmp*10 + root->val;
        if(!root->left && !root->right)
        {
            //cout<<res<<" "<<tmp<<endl;
            res += tmp;
            tmp = (tmp - root->val)/10;
            return;
        }
        if(root->left)
            dfs(root->left, tmp, res);
        if(root->right)
            dfs(root->right, tmp, res);
        tmp = (tmp - root->val)/10;
    }
    int sumNumbers(TreeNode* root) {
        int res = 0;
        int tmp = 0;
        dfs(root, tmp, res);
        return res;
    }
};