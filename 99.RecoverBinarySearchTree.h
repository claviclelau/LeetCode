class Solution {
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *p_last, *p_small, *p_big;
        bool b_big = true;
    	p_small = p_big = NULL;
        int i_last = INT_MIN;
        Traverse(root, i_last, p_last, p_small, p_big, b_big);
        i_last = p_small->val;
        p_small->val = p_big->val;
        p_big->val = i_last;
    }
    void Traverse(TreeNode * root, int & i_last, TreeNode * & p_last, TreeNode *& p_small, TreeNode *& p_big, bool & b_big)
    {
        if (root==NULL)
            return;
            
        if (root->left)
            Traverse(root->left, i_last, p_last, p_small, p_big, b_big);  

		if (i_last>root->val)
        {
            if (b_big)
            {
                p_big = p_last;
                b_big = !b_big;
                p_small = root;// Doing this is because the swapped two may be adjacent.
            }
            else
            {
                p_small = root;
                return;
            }
        }
        i_last = root->val;
        p_last = root;
        if (root->right)
            Traverse(root->right, i_last, p_last, p_small, p_big, b_big);
    }
};