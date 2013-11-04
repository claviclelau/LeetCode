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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (preorder.size()==0||inorder.size()==0)
			return NULL;
		return buildTreeInAndPreRe(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
	TreeNode *buildTreeInAndPreRe(vector<int> &preorder, int i_start_pre, int i_end_pre, vector<int> &inorder, int i_start_in, int i_end_in)
	{
		if (i_start_pre>i_end_pre||i_start_in>i_end_in)
			return NULL;
		if (i_start_pre==i_end_pre)
			return new TreeNode(preorder[i_start_pre]);
			
		int elem = preorder[i_start_pre];
		int i = 0;
		for (; i<inorder.size(); i++)
			if (inorder[i]==elem)
				break;
		TreeNode * ret = new TreeNode(elem);
		ret->left = buildTreeInAndPreRe(preorder, i_start_pre + 1, i_start_pre + i - i_start_in, inorder, i_start_in, i - 1);
		ret->right = buildTreeInAndPreRe(preorder, i_start_pre + i - i_start_in + 1, i_end_pre, inorder, i + 1, i_end_in);
		return ret;
	}
};