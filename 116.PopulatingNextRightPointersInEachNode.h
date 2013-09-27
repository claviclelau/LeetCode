/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        connectPerfectRecursive(root);
    }
    void connectPerfectRecursive(TreeLinkNode * root)
    {
        if (root==NULL)
            return;
            
        if (root->left==NULL)
        {
            root->next = NULL;
            return;
        }
        
        connectPerfectRecursive(root->left);
        connectPerfectRecursive(root->right);
        
        TreeLinkNode *left = root->left, *right = root->right;
        while(left!=NULL)
        {
            left->next = right;
            left = left->right;
            right = right->left;
        }
    }
};