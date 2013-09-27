class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return MakeTree(num, 0, num.size()-1);
    }
    TreeNode *MakeTree(vector<int> & num, int i_begin, int i_end)
    {
        if (i_begin>i_end)
            return NULL;
       
        
        if (i_begin==i_end)
        {
            return new TreeNode(num[i_begin]);
        }
            
        
        int i_root = (i_begin+i_end)/2;
        TreeNode * root = new TreeNode(num[i_root]);
        root->val = num[i_root];
        root->left = MakeTree(num, i_begin, i_root-1);
        root->right = MakeTree(num, i_root+1, i_end);
        return root;
    }
};