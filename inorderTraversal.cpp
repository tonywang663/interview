#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *root) {
	vector<int> res;

	if(root == NULL){
		return res;
	}

	stack<TreeNode*> stk;

	stk.push(root);

	while(!stk.empty()){
		TreeNode* node = stk.top();
		if(node->left != NULL){
			stk.push(node->left);
			node->left = NULL;
		}else{
			res.push_back(node->val);
			stk.pop();
			if(node->right != NULL){
				stk.push(node->right);
				node->right = NULL;
			}
		}

	}

	return res;
}


vector<int> inorderTraversal1(TreeNode *root) {
	vector<int> res;

	if(root == NULL){
		return res;
	}

	stack<TreeNode*> stk;

	TreeNode* node = root;
	while(node != NULL){
		stk.push(node);
		node = node->left;
	}

	while(!stk.empty()){
		TreeNode* node = stk.top();
		stk.pop();
		res.push_back(node->val);

		TreeNode * newnode = node->right;
		while(newnode != NULL){
			stk.push(newnode);
			newnode = newnode->left;
		}
	}

	return res;

}

//08/08/2013
vector<int> inorderTraversal2(TreeNode *root) {
	vector<int> res;

	stack<TreeNode*> stk;

	TreeNode* node = root;

	while(node != NULL){
		stk.push(node);
		node = node->left;
	}

	while(!stk.empty()){
		TreeNode* node = stk.top();
		stk.pop();

		res.push_back(node->val);
	
		node = node->right;
		while(node != NULL){
			stk.push(node);
			node = node->left;
		}

	}

    return res;
}

void maininorderTraversal(){

}