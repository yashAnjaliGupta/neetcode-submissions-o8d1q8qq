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
    void dfs(TreeNode* node,int maxInPath,int &ans){
        if(node==NULL)return;
        if(node->val>=maxInPath)ans++;
        dfs(node->left,max(maxInPath,node->val),ans);
        dfs(node->right,max(maxInPath,node->val),ans);
    }
public:
    int goodNodes(TreeNode* root) {
        int ans=0;
        dfs(root,root->val,ans);
        return ans;
    }
};
