#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode *root) {
	if(root == NULL){
		return true;
	}
	
	stack<TreeNode*> stk;
	
	TreeNode* node = root;
	while(node != NULL){
		stk.push(node);
		node = node->left;
	}

	int preval = stk.top()->val - 1;
	while(!stk.empty()){
		TreeNode* node = stk.top();
		stk.pop();
		if(node->val <= preval)
			return false;

		preval = node->val;

		node = node->right;

		while(node != NULL){
			stk.push(node);
			node = node->left;
		}

	}

	return true;
}


//08/09/2013  preorder: wrong! use inorder
bool isValidBST1(TreeNode *root) {
	if(root == NULL)
		return true;
	stack<TreeNode*> stk;
	
	TreeNode* node = root;
	while(node){
		stk.push(node);
		node = node->left;
	}

	TreeNode* pre = NULL;

	while(!stk.empty()){
		node = stk.top();
		stk.pop();

		if(pre && pre->val >= node->val)
			return false;
		else
			pre = node;

		node = node->right;
		while(node){
			stk.push(node);
			node = node->left;
		}
	}

	return true;
}

bool helper(TreeNode* node, int& pre){
	if (!node)
		return true;

	if (!helper(node->left, pre))
		return false;

	if (node->val <= pre)
		return false;
	else
		pre = node->val;

	if (!helper(node->right, pre))
		return false;

	return true;
}

bool isValidBST2(TreeNode *root) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	if (!root)
		return true;

	int pre = INT_MIN;
	return helper(root, pre);
}
void mainisValidBST(){


}