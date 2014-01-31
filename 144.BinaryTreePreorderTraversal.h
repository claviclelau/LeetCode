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
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> answer;
        preorderTraversalRe(root, answer);
        return answer;
    }
	void preorderTraversalRe(TreeNode * root, vector<int> & answer)
	{
		if (root==NULL)
			return;
		answer.push_back(root->val);
		preorderTraversalRe(root->left, answer);
		preorderTraversalRe(root->right, answer);
	}
	vector <int> preorderTraversalIter(TreeNode * root)
	{
		vector <int> answer;
		if (root == NULL)
			return answer;
		
		vector<TreeNode *> stk;
		stk.push_back(root);
		while (!stk.empty())
		{
			TreeNode * node = stk.back();
			stk.pop_back();
			answer.push_back(node->val);
			if (node->right != NULL)
				stk.push_back(node->right);
			if (node->left != NULL)
				stk.push_back(node->left);
		}
		return answer;
	}
};