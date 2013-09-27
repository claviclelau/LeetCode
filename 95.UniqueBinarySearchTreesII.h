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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode *> answer;
        if (n<=0)
        {
            answer.push_back(NULL);
            return answer;
        }
        generateTreesRe(1, n, answer);
        return answer;
    }
    void generateTreesRe(int i_begin, int i_end, vector<TreeNode *> & root)
    {
        if (i_begin==i_end)
        {
            root.push_back(new TreeNode(i_begin));
            return;
        }
        if (i_begin>i_end)
        {
            root.push_back(NULL);
            return;
        }
        vector<TreeNode *> left;
        vector<TreeNode *> right;
        for (int i = i_begin; i<=i_end; i++)
        {
            left.clear();
            right.clear();
            generateTreesRe(i_begin, i-1, left);
            generateTreesRe(i+1, i_end, right);
            for (int i_left = 0; i_left<left.size(); i_left++)
            {
                for (int i_right = 0; i_right<right.size(); i_right++)
                {
                    TreeNode * temp = new TreeNode(i);
                    temp->left = left[i_left];
                    temp->right = right[i_right];
                    root.push_back(temp);
                }
            }
        }
    }
};