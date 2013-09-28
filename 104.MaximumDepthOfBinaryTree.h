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
		TreeNode * my_node, * temp_node;
		while(!stk.empty())
		{
			my_node = stk.top();
			if (my_node->left)
				stk.push(my_node->left);
			else if (my_node->right)
				stk.push(my_node->right);
			else
			{
				max_depth = stk.size()>max_depth?stk.size():max_depth;
				stk.pop();
				temp_node = stk.top();
				if (temp_node->left == my_node&&temp_node->right)
					stk.push(temp_node->right);
				else
				{
					while ((!stk.empty())&&((temp_node = stk.top())->right==my_node||(temp_node = stk.top())->right==NULL))
					{
						my_node = temp_node;
						stk.pop();
					}
				}
			}
		}
		return max_depth;
	}
};