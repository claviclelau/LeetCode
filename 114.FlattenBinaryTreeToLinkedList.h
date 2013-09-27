/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        flattenRecursive(root);
    }
    TreeNode * flattenRecursive(TreeNode * root)
    {
        if (root==NULL)
            return NULL;
        
        TreeNode * left = flattenRecursive(root->left);
        TreeNode * right = flattenRecursive(root->right);
        
        TreeNode * traverse = root;
        traverse->right = left;
        while(traverse->right!=NULL)
        {
            traverse = traverse->right;
        }
        traverse->right = right;
        root->left = NULL;// This one is important.
        return root;
    }
};