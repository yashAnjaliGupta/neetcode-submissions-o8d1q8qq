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
    int isBalancedUtil(TreeNode* root,bool &flag){
        if(root==NULL)return 0;
        int left=isBalancedUtil(root->left,flag);
        int right=isBalancedUtil(root->right,flag);
        if(abs(left-right)>1)flag = false;
        return max(left,right)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool flag=true;
        isBalancedUtil(root,flag);
        return flag;
    }
};
