#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode *root) {
	if(root == NULL)
		return 0;

	queue<TreeNode*> stk;

	stk.push(root);
	stk.push(NULL);

	int level = 1;
	while(!stk.empty()){
		TreeNode* node = stk.front();
		stk.pop();

		if(!node && stk.empty()){
			return level;
		}else if(!node){
			level++;
			stk.push(NULL);
			continue;
		}

		if(!node->left && !node->right){
			return level;
		}
		if(node->left)
			stk.push(node->left);

		if(node->right){
			stk.push(node->right);
		}
	}
    
}

void mainminDepth(){
	TreeNode n1(1);
	minDepth(&n1);

}