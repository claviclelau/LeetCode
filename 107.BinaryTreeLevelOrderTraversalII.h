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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > answer;
        if (root==NULL)
            return answer;
            
        list <vector<int> > stack;   
        vector <int> one_level;
        vector<TreeNode *> level[2];
        int i_level_num = 0;
        level[i_level_num].push_back(root);
        while (!level[i_level_num].empty())
        {
            int i_next_level = i_level_num^1;
            for (int i = 0; i<level[i_level_num].size(); i++)
            {
                if (level[i_level_num][i]->left!=NULL)
                    level[i_next_level].push_back(level[i_level_num][i]->left);
                    
                if (level[i_level_num][i]->right!=NULL)
                    level[i_next_level].push_back(level[i_level_num][i]->right);
                    
                one_level.push_back(level[i_level_num][i]->val);
            }
            level[i_level_num].clear();
            stack.push_back(one_level);
            one_level.clear();
            i_level_num = i_next_level;
        }
        while(!stack.empty())
        {
            answer.push_back(stack.back());
            stack.pop_back();
        }
        return answer;
    }
};