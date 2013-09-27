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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.size()==0||postorder.size()==0)
            return NULL;
            
        return buildTreeRecursive(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode * buildTreeRecursive(vector<int> & inorder, int i_begin_in, int i_end_in, vector<int> & postorder, int i_begin_post, int i_end_post)
    {
        if (i_begin_in==i_end_in)
            return new TreeNode(inorder[i_begin_in]);
            
        TreeNode * root = new TreeNode(postorder[i_end_post]);
        int i;
        for (i = i_begin_in; i<=i_end_in; i++)
        {
            if (inorder[i]==postorder[i_end_post])
                break;
        }
        
        if (i==i_begin_in)
            root->left = NULL;
        else
            root->left = buildTreeRecursive(inorder, i_begin_in, i-1, postorder, i_begin_post, i_begin_post + i - 1 - i_begin_in);
            
        if (i==i_end_in)
            root->right = NULL;
        else
            root->right = buildTreeRecursive(inorder, i+1, i_end_in, postorder, i_end_post - i_end_in + i, i_end_post - 1);
    }
};