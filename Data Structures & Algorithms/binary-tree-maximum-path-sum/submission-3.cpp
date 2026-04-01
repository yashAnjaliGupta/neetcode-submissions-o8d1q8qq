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
    int DFS(TreeNode* node,int &ans){
        if(node==NULL)return 0;
        int lSum=max(DFS(node->left,ans),0);
        int rSum=max(DFS(node->right,ans),0);
        ans=max(ans,lSum+rSum+node->val);
        return max(lSum,rSum)+node->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=root->val;
        ans=max(ans,DFS(root,ans));
        return ans;
    }
};
