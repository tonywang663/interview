#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool respath(TreeNode* node, int& psum, int sum){
	if(!node->left && !node->right){
		if(node->val + psum == sum){
			return true;
		}else{
			return false;
		}
	}
	
	if(node->left){
		int t = node->val + psum;
		if(respath(node->left, t, sum))
			return true;
	}

	if(node->right){
		int t = node->val + psum;
		if(respath(node->right, t, sum))
			return true;
	}

	return false;
}

bool hasPathSum(TreeNode *root, int sum) {
	if(!root)
		return false;

	int t = 0;
	return respath(root, t, sum);
}


bool helper(TreeNode* node, int val, int sum){
	val += node->val;

	if(node->left == NULL && node->right ==NULL && sum == val)
		return true;

	if( (node->left &&helper(node->left, val, sum)) ||  (node->right && helper(node->right, val, sum)))
		return true;

	return false;
}

//08/09/2013
bool hasPathSum1(TreeNode *root, int sum) {
	if(root == NULL)
		return false;

	return helper(root, 0, sum);  
}

void mainhasPathSum(){
	TreeNode n1(-2), n2(-3);
	n1.right = &n2;

	hasPathSum(&n1, -2);

}