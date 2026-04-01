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
    int utilDiameterOfBinaryTree(TreeNode* root,int &ans){
        if(root==NULL)return 0;

        int leftDepth = utilDiameterOfBinaryTree(root->left,ans);
        int rightDepth = utilDiameterOfBinaryTree(root->right,ans);
        ans=max(ans,leftDepth+rightDepth);
        return max(leftDepth,rightDepth)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        utilDiameterOfBinaryTree(root,ans);
        return ans;
    }
};
