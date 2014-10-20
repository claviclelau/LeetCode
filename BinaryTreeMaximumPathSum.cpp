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
    int maxPathSum(TreeNode *root) {
    	if (root == NULL)
    		return 0;
    	int max = INT_MIN;
        DFSRe(root, max);
        return max;
    }
    int DFSRe(TreeNode * root, int & max)
    {
    	if (root == NULL)
    		return 0;

    	int left = DFSRe(root->left, max);
    	int right = DFSRe(root->right, max);

    	int ret = root->val;
    	int temp_max = root->val;
    	if (!(left < 0 && right < 0))
    		ret += (left > right ? left : right);

    	temp_max += left > 0 ? left : 0;
    	temp_max += right > 0 ? right : 0;

    	max = temp_max > max ? temp_max : max;

    	return ret;
    }
};