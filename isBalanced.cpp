#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool resbal(TreeNode* node, int &height){
	if(!node){
		height = 0;
		return true;
	}
	
	int hl = 0, hr = 0;

	if(!resbal(node->left, hl))
		return false;

	if(!resbal(node->right, hr))
		return false;

	if(abs(hl - hr) > 1) 
		return false;
	
	height = (hl > hr ? hl : hr) + 1;
	return true;
}

bool isBalanced(TreeNode *root) {
	int h = 1;
	bool x = resbal(root, h);
	return x;
}

void mainisBalanced(){
	TreeNode n1(1), n2(2), n3(3);
	n1.right = &n2;
	n2.left = &n3;
	isBalanced(&n1);

}