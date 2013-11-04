#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void ressum(TreeNode* root, int pathsum, int& sum){
	if(root == NULL){
		return;
	}

	int val = root->val;
	pathsum = pathsum * 10 + val;
	if(root->left)
		ressum(root->left, pathsum, sum);
	
	if(root->right)
		ressum(root->right, pathsum, sum);

	if(root->left == NULL && root->right == NULL){
		sum += pathsum;
	}

}

int sumNumbers(TreeNode *root) {
	if(root == NULL)
		return 0;

	int sum = 0;
	ressum(root, 0, sum);

	return sum;
    
}

static void helper(TreeNode* node, int cur, int& sum){
	if(node->left == NULL && node->right == NULL){
		cur = cur * 10 + node->val;
		sum += cur;
		return;
	}

	cur = 10 * cur + node->val;
	if(node->left)
		helper(node->left, cur, sum);
	if(node->right)
		helper(node->right, cur, sum);
}

//08/10/2013
int sumNumbers1(TreeNode *root) {
	if(root == NULL)
		return 0;

	int sum = 0;
	helper(root, 0, sum);
    return sum;
}

void mainsumNumbers(){

}