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
        if (root == NULL)
            return;
        TreeNode *tail;
        flattenRe(root, tail);
    }
    void flattenRe(TreeNode * root, TreeNode *& tail)
    {
    	TreeNode * leftTail, *rightTail;
    	if (root->right != NULL)
    	{
    		TreeNode * right = root->right;
    		if (root->left != NULL)
    		{
    			flattenRe(root->left, leftTail);
    			leftTail->right = root->right;
    			root->right = root->left;
    		}
    		flattenRe(right, rightTail);
    		tail = rightTail;
    		root->left = NULL;
    		return;
    	}

    	if (root-> left != NULL)
    	{
    		flattenRe(root->left, leftTail);
    		root->right = root->left;
    		tail = leftTail;
    		root->left = NULL;
    		return;
    	}

    	tail = root;
    	root->left = NULL;
    	return;
    }
};
