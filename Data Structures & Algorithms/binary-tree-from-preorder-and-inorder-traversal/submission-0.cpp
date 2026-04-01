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
    TreeNode* recurBuildTree(vector<int>& preorder, vector<int>& inorder,
    int preStart,int preEnd,int inStart,int inEnd,unordered_map<int,int>& inorderMap){
        if(preStart>preEnd||inStart>inEnd)return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inOrdIndex=inorderMap[preorder[preStart]];
        int size=inOrdIndex-inStart;
        root->left=recurBuildTree(preorder,inorder,preStart+1,preStart+size,inStart,inOrdIndex-1,inorderMap);
        root->right=recurBuildTree(preorder,inorder,preStart+size+1,preEnd,inOrdIndex+1,inEnd,inorderMap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorderMap;
        for(int i=0;i<inorder.size();i++)inorderMap[inorder[i]]=i;
        TreeNode* root= recurBuildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,inorderMap);
        return root;
    }
};
