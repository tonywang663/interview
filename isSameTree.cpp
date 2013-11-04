#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool resame(TreeNode *p, TreeNode *q){
	if(p == NULL && q == NULL)
		return true;

	if(p == NULL || q == NULL || p->val != q->val)
		return false;

	bool left = resame(p->left, q->left);

	bool right = resame(p->right, q->right);

	return left && right;

}

bool isSameTree(TreeNode *p, TreeNode *q) {
	if(p == NULL || q == NULL)
		return false;

	return resame(p, q);

}


bool helper(TreeNode* p, TreeNode* q){
	if(p == NULL && q == NULL)
		return true;
	
	if(p == NULL)
		return false;

	if(q == NULL)
		return false;

	if(p->val != q->val)
		return false;

	return helper(p->left, q->left) && helper(p->right, q->right);

}

//08/09/2013
bool isSameTree1(TreeNode *p, TreeNode *q) {
	
    return helper(p, q);
}

void mainisSameTree(){

}