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
private: 
    int dfs(TreeNode* node,int maxVal){
        if(node==NULL)return 0;
        int res=(node->val>=maxVal)? 1:0;
        maxVal=max(maxVal,node->val);
        res+=dfs(node->left,maxVal);
        res+=dfs(node->right,maxVal);
        return res;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};
