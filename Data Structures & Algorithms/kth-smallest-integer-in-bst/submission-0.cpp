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
    void inorderTrav(TreeNode* node,int k, int &cnt,int &ans){
        if(node==NULL)return;
        inorderTrav(node->left,k,cnt,ans);
        cnt++;
        if(cnt==k){ans=node->val;return;} 
        inorderTrav(node->right,k,cnt,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans =0,cnt=0;
        inorderTrav(root,k,cnt,ans);
        return ans;
    }
};
