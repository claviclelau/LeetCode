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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        return postorderTraversalIter(root);
    }
	void postorderTraversalRe(TreeNode * root, vector <int> & answer)
	{
		if (root == NULL)
			return;
		
		postorderTraversalRe (root->left, answer);
		postorderTraversalRe (root->right, answer);
		answer.push_back(root->val);
	}
	vector <int> postorderTraversalIter(TreeNode * root)
	{
		vector <int> answer;
		
		vector <TreeNode *> stk;
		TreeNode * node = root;
		TreeNode * last_pop = NULL;
		while (node || !stk.empty())
		{
			while (node)
			{
				stk.push_back(node);
				node = node->left;
			}
			node = stk.back();
			if (node->right == NULL || node->right == last_pop)
			{
				answer.push_back(node->val);
				stk.pop_back();
				last_pop = node;
				node = NULL;	//This is subtle. Pay special attention to it.
			}
			else
			{
				node = node->right;		//This is subtle.
			}
		}
		return answer;
	}
};

