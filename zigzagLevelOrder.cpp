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


vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
	vector<vector<int>> res;

	if(root == NULL)
		return res;

	stack<TreeNode*> stk;

	stk.push(root);

	stk.push(NULL);

	vector<int> level;
	while(!stk.empty()){
		TreeNode* node = stk.top();
		stk.pop();

		if(node != NULL){
			level.push_back(node->val);

			if(node->left != NULL){
				stk.push(node->left);
			}

			if(node->right != NULL){
				stk.push(node->right);
			}
		}else{
			res.push_back(level);
			if(stk.empty())
				break;
			stk.push(NULL);
			level.clear();
		}

	}

	return res;
    
}

void mainzigzagLevelOrder(){

}