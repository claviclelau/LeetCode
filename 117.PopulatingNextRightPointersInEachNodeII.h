/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        connectIter(root);
    }
	void connectIter(TreeLinkNode * root)
	{
		if (root==NULL)
			return;
		TreeLinkNode * cur = (root->left==NULL)?root->right:root->left, * up_level = root;
		while (cur!=NULL)
		{
			TreeLinkNode * this_level = cur;
			while (up_level!=NULL)
			{
				if (cur == up_level->left && up_level->right!=NULL)
					cur->next = up_level->right;
				else
				{
					do{
						up_level = up_level->next;
					}
					while (up_level!=NULL && up_level->left == NULL && up_level->right == NULL)
						
					if (up_level==NULL)
						cur->next = NULL;
					else
						cur->next = up_level->left==NULL ? up_level->right : up_level->left;
				}
				cur = cur->next;
			}
			up_level = this_level;
			while (up_level!=NULL && up_level->left == NULL && up_level->right == NULL)
				up_level = up_level->next;
			if (up_level==NULL)
				cur = NULL;
			else
				cur = up_level->left==NULL ? up_level->right : up_level->left;
		}
	}
};