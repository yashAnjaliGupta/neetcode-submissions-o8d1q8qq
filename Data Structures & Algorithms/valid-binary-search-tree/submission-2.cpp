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
    bool isValidBSTUtil(TreeNode* node,int left,int right){
        if(node==NULL)return true;
        if(!(left<node->val && node->val<right))return false;
        return isValidBSTUtil(node->left,left,node->val)&&isValidBSTUtil(node->right,node->val,right);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        return isValidBSTUtil(root,INT_MIN,INT_MAX);
    }
};
