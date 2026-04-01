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
    int utilIsBalanced(TreeNode* root, bool & balance){
        if(root==NULL)return 0;
        int leftHeight=utilIsBalanced(root->left,balance);
        int rightHeight=utilIsBalanced(root->right,balance);
        if(abs(leftHeight-rightHeight)>1)balance = false;
        return max(leftHeight,rightHeight)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool balance=true;
        utilIsBalanced(root,balance);
        return balance;
    }
};
