#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode *root) {
	if(root == NULL)
		return true;

	stack<TreeNode*> stk1, stk2;

	TreeNode* node = root;

	while(node != NULL){
		stk1.push(node);
		node = node->left;
	}

	node = root;
	while(node != NULL){
		stk2.push(node);
		node = node->right;
	}

	while(!stk1.empty() && !stk2.empty()){
		if(stk1.size() != stk2.size())
			return false;
		
		TreeNode* node1 = stk1.top();
		stk1.pop();

		TreeNode* node2 = stk2.top();
		stk2.pop();

		if(node1->val != node2->val)
			return false;

		node1 = node1->right;
		while(node1 != NULL){
			stk1.push(node1);
			node1 = node1->left;
		}

		node2 = node2->left;
		while(node2 != NULL){
			stk2.push(node2);
			node2 = node2->right;
		}

	}

	if(stk1.empty() && stk2.empty())
		return true;
	
	return false;
}

void mainisSymmetric(){

}