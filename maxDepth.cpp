#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int maxDepth(TreeNode *root) {
	if(root == NULL)
		return 0;

	queue<TreeNode*> que;

	que.push(root);
	que.push(NULL);

	int level = 0;

	while(1){
		TreeNode* node = que.front();
		que.pop();

		if(node){
			if(node->left)
				que.push(node->left);
			if(node->right)
				que.push(node->right);
		}else{
			level++;
			if(que.empty())
				break;
			que.push(NULL);
		}

	}
	return level;
    
}

static void helper(TreeNode* root, int i, int &max){
	if(root == NULL)
		return;

	i++;
	if(i > max)
		max = i;

	helper(root->left, i, max);
	helper(root->right, i, max);
}

//08/09/2013
int maxDepth1(TreeNode *root) {
	
    int i = 0, max = 0;
	helper(root, i, max);
	return max;
}


void mainmaxDepth(){

}