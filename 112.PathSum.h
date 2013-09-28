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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root==NULL)
            return false;
        return DFS(root, sum);
    }
    bool DFS (TreeNode * root, int sum)
	{
	    if (root==NULL)
	        return false;
	        
	    if (root->right==NULL&&root->left==NULL)
	        return sum==root->val;
	        
		if (DFS(root->left, sum - root->val))
			return true;
		
		return DFS(root->right, sum - root->val);
	}
};