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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > answer;
		if (!root)
		    return answer;

		vector<TreeNode*> my_queue[2];
		vector<int> v_level;
		int i_current = 0, i_next = 1;
		my_queue[i_current].push_back(root);
		while (!my_queue[i_current].empty())
		{
			my_queue[i_next].clear();
			v_level.clear();
			for (int i = 0; i<my_queue[i_current].size(); i++)
			{
				if (my_queue[i_current][i]->left)
					my_queue[i_next].push_back(my_queue[i_current][i]->left);
				if (my_queue[i_current][i]->right)
					my_queue[i_next].push_back(my_queue[i_current][i]->right);
				v_level.push_back(my_queue[i_current][i]->val);
			}
			answer.push_back(v_level);
			i_next ^= 1;
			i_current ^= 1;
		}
		return answer;
    }
};