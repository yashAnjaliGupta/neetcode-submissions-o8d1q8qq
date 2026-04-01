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
        int lSum=DFS(node->left,ans);
        int rSum=DFS(node->right,ans);
        // cout<<node->val<<" "<<lSum<<" "<<rSum<<" "<<endl;
        // cout<<lSum+rSum+node->val<<endl;
        ans=max(ans,max(lSum+rSum+node->val,node->val));
        return max(max(lSum,rSum)+node->val,node->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=root->val;
        ans=max(ans,DFS(root,ans));
        return ans;
    }
};
