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
    void traverse(vector<int> &traversal, TreeNode* copy){
        if(copy==NULL){return;}
        traversal.push_back(copy->val);
        traverse(traversal, copy->left);
        traverse(traversal, copy->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* copy = root;
        vector<int> traversal;
        traverse(traversal, copy);
        return traversal;
    }
};