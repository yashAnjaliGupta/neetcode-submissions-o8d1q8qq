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
    void dfs(TreeNode* node,int &k,int &ans){
        if(!node)return;
        dfs(node->left,k,ans);
        k--;
        if(k==0)ans= node->val;
        dfs(node->right,k,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        dfs(root,k,ans);
        return ans;
    }
};
