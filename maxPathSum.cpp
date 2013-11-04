#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int postorder(TreeNode* node, int& max){
	if(node == NULL)
		return 0;


	int lm = postorder(node->left, max);
	int rm = postorder(node->right, max);

	int nm = node->val;

	int ret = node->val;

	if(lm >= 0 && rm >= 0){
		nm += lm + rm;
		ret += (lm > rm) ? lm : rm; 
	}

	if(lm > 0 && rm < 0){
		nm += lm;
		ret = nm;
	}

	if(lm < 0 && rm > 0){
		nm += rm;
		ret = nm;
	}


	if(nm > max)
		max = nm;

	return ret; 
}

int maxPathSum(TreeNode *root) {
	if(root == NULL)
		return 0;

	int max = root->val;

	postorder(root, max);
	
	return max;
}



static int helper(TreeNode* node, int& max){
	if(node == NULL){
		return 0;
	}

	int t1 = helper(node->left, max);
	int t2 = helper(node->right, max);

	int res = node->val;
	if(t1 + node->val > res)
		res = t1 + node->val;
	
	if(t2 + node->val > res)
		res = t2 + node->val;

	if(node->val > max)
		max = node->val;

	if(t1 + node->val > max)
		max = t1 + node->val;

	if(t2 + node->val > max)
		max = t2 + node->val;

	if(t1 + t2 + node->val > max)
		max = t1 + t2 + node->val;

	return res;
}

//08/10/2013
int maxPathSum1(TreeNode *root) {
	if(root == NULL)
		return 0;

	int max = root->val;
	helper(root, max);
    return max;
}

void mainmaxPathSum(){

}