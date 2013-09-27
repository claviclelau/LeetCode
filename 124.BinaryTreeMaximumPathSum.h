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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i_max, i_max_root;
        PathSumRe (root, i_max_root, i_max);
        return i_max;
    }
    void PathSumRe(TreeNode * root, int & i_max_root, int & i_max)
    {
        if (root==NULL)
        {
            i_max_root = INT_MIN;
            i_max = INT_MIN;
            return;
        }

        int i_max_root_left, i_max_root_right, i_max_left, i_max_right;
        PathSumRe(root->right, i_max_root_right, i_max_right);
        PathSumRe(root->left, i_max_root_left, i_max_left);
        i_max_root = max(0, max(i_max_root_left, i_max_root_right)) + root->val;
        i_max = max(max(i_max_right, i_max_left), (max(0, i_max_root_left) + max(0 ,i_max_root_right) + root->val));
    }
};