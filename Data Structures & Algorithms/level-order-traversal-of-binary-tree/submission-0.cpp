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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode* > qu;
        qu.push(root);
        while(!qu.empty()){
            int levelSize=qu.size();
            vector<int> temp;
            for(int i=0;i<levelSize;i++){
                TreeNode* currNode=qu.front();qu.pop();
                temp.push_back(currNode->val);
                if(currNode->left!=NULL)qu.push(currNode->left);
                if(currNode->right!=NULL)qu.push(currNode->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};
