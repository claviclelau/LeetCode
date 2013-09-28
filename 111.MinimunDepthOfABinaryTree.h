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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root==NULL)
            return 0;
        
        return minDepthRe(root);
    }
    int minDepthRe(TreeNode * root)
    {
        if (root==NULL)
            return INT_MAX;
        if (root->left==NULL&&root->right==NULL)
            return 1;
        
        return min(minDepthRe(root->left), minDepthRe(root->right)) + 1;
    }
};