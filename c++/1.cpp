/**
 *算法题目
102、二叉树的层序遍历
 */

//TODO:code
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        TreeNode* r = root;
        if(!r)
            return res;
        queue<TreeNode*> q;
        q.push(r);
        int sum = 0;
        vector<int> in;
        while(!q.empty())
        {
            r = q.front();
            in.push_back(r->val);
            q.pop();
            if(r->left)
                q.push(r->left) , sum++;
            if(r->right)
                q.push(r->right), sum++;
            if(q.size() == sum)
            {
                res.push_back(in);
                in.erase(in.begin() , in.end());
                sum = 0;
            }
        }
        return res;
    }
};