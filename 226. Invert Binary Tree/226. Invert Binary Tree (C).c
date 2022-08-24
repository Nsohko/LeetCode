#include <stdio.h>

 
struct TreeNode {
	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 };
 


struct TreeNode* invertTree(struct TreeNode* root){
	
	if(root == NULL)
	{
    	return root;
	}
	
	struct Treenode* temp = root->left;
	root->left = invertTree(root->right);
	root->right = invertTree(temp);
	
	return root;

}

int main() {
    return 0;
}
