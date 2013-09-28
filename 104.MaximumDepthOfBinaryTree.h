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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return maxDepthStack(root);
    }
	int maxDepthStack(TreeNode * root)
	{
		if (!root)
			return 0;
		stack<TreeNode *> stk;
		stk.push(root);
		int max_depth = 0;
		TreeNode * my_node = root;
		TreeNode * top;
		while(!stk.empty())
		{
			top = stk.top();
			if (top->left==NULL&&top->right==NULL)
			{
				my_node = top;
				max_depth = stk.size()>max_depth?stk.size():max_depth;
				stk.pop();			
				continue;
			}
			if (my_node==top->right)
			{
				my_node = top;
				stk.pop();
				continue;
			}
			if (my_node==top->left)
			{
				if (top->right)
					stk.push(top->right);
				else
				{
					my_node = top;
					stk.pop();
				}
				continue;
				continue;
			}
			if (top->left)
				stk.push(top->left);
			else
				stk.push(top->right);
		}
		return max_depth;
	}
	int maxDepthRe(TreeNode * root)
	{
		if (!root)
			return 0;
		int max_left = maxDepthRe(root->left), max_right = maxDepthRe(root->right);
		return max(max_left, max_right)+1;
	}
};