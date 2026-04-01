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
    bool checkTree(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL)return true;
        if(p==NULL)return false;
        if(q==NULL)return false;

        return p->val==q->val && checkTree(p->left,q->left) && checkTree(p->right,q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)return false;
        bool flag=false;
        if(root->val==subRoot->val){
            flag=checkTree(root,subRoot);
        }
        return flag||isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};
