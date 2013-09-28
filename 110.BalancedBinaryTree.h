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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int depth;
		return isBalancedRe(root, depth);
    }
	bool isBalancedRe(TreeNode * root, int & depth)
	{
		if (root==NULL)
		{
			depth = 0;
			return true;
		}
		int i_left_depth, i_right_depth;
		if (isBalancedRe(root->left, i_left_depth)&&isBalancedRe(root->right, i_right_depth))
		{
		    depth = max(i_right_depth, i_left_depth) + 1;
		    return abs(i_right_depth-i_left_depth)<=1;
		}
		return false;
	}
};