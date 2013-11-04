#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void recoverTree(TreeNode *root) {
    if(root == NULL)
		return;

	stack<TreeNode*> stk;
	
	TreeNode* node = root;
	while(node != NULL){
		stk.push(node);
		node = node->left;
	}

	TreeNode* pre = NULL;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
	bool leftfound = false;
	while(!stk.empty()){
		TreeNode* node = stk.top();
		stk.pop();

		if(pre != NULL && leftfound == false){
			if(node->val <= pre->val){
				left = pre;
				leftfound = true;
			}
		}
		
		if(leftfound){
			if(node->val <= pre->val){
				right = node;
			}
		}

		pre = node;

		node = node->right;

		while(node != NULL){
			stk.push(node);
			node = node->left;
		}
	}

		int val = left->val;
		left->val = right->val;
		right->val = val;
}


//08/09/2013
void recoverTree1(TreeNode *root) {
	stack<TreeNode*> stk;
	if(root == NULL)
		return;

	TreeNode* node = root;
	while(node){
		stk.push(node);
		node = node->left;
	}

	TreeNode* pre = NULL;
	TreeNode* first = NULL;
	TreeNode* second = NULL;
    
	while(!stk.empty()){
		node = stk.top();
		stk.pop();

		if(pre && pre->val >= node->val){
			if(!first){
				first = pre;
				second = node;
			}else{
				second = node;
				break;
			}
		}

		pre = node;

		
		node = node->right;

		while(node){
			stk.push(node);
			node = node->left;
		}
	}

	if(first){
		int t = first->val;
		first->val = second->val;
		second->val = t;
	}
}

void mainrecoverTree(){
	TreeNode n1(0), n2(1);


}