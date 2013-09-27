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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i_biggest, i_smallest;
        return isValidBSTRecursive(root, i_biggest, i_smallest);
    }
    bool isValidBSTRecursive(TreeNode * root, int & i_biggest, int & i_smallest)
    {
        if (root==NULL)
            return true;
        int i_biggest_left, i_smallest_left;
        int i_biggest_right, i_smallest_right;
        if (root->left==NULL)
        {
            i_smallest = root->val;
        }
        else
        {
            if (!isValidBSTRecursive(root->left, i_biggest_left, i_smallest_left))
                return false;
                
            if (i_biggest_left>=root->val)
                return false;
                
            i_smallest = i_smallest_left;
        }
        
        if (root->right==NULL)
        {
            i_biggest = root->val;
        }
        else
        {
            if (!isValidBSTRecursive(root->right, i_biggest_right, i_smallest_right))
                return false;
                
            if (i_smallest_right<=root->val)
                return false;
                
            i_biggest = i_biggest_right;
        }
        return true;
    }
};