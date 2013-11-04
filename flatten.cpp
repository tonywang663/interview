#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




void flatten(TreeNode *root) {
	if(!root)
		return;

	stack<TreeNode*> stk;

	stk.push(root);

	TreeNode* pre = NULL;
	while(!stk.empty()){
		TreeNode* node = stk.top();
		stk.pop();

		if(pre){
			pre->left = NULL;
			pre->right = node;
		}

		pre = node;
		if(node->right)
			stk.push(node->right);

		if(node->left)
			stk.push(node->left);
	}
    
}


//08/09/2013
void flatten1(TreeNode *root) {
	if(root == NULL)
		return;

	stack<TreeNode*> stk;
	stk.push(root);

	TreeNode* pre = NULL;
	while(!stk.empty()){
		TreeNode* node = stk.top();
		stk.pop();

		if(pre){
			pre->left = NULL; //important
			pre->right = node;
		}
		pre = node;

		if(node->right)
			stk.push(node->right);

		if(node->left)
			stk.push(node->left);
	}
	    
}

void mainflatten(){

}