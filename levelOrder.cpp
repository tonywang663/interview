#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode *root) {
	vector<vector<int>> res;

	if(root == NULL)
		return res;

	queue<TreeNode*> que;

	que.push(root);

	que.push(NULL);

	
	vector<int> level;
	while(!que.empty()){
		TreeNode* node = que.front();
		que.pop();

		if(node != NULL){
			level.push_back(node->val);
			if(node->left != NULL)
				que.push(node->left);
			if(node->right != NULL)
				que.push(node->right);
		}else{
			res.push_back(level);
			if(que.empty())
				break;
			que.push(NULL);
			level.clear();
		}
	}

	return res;

}




//08/09/2013
vector<vector<int> > levelOrder1(TreeNode *root) {
	vector<vector<int>> res;
	if(root == NULL)
		return res;

	queue<TreeNode*> que;
	que.push(root);
	que.push(NULL);

	vector<int> level;
	while(1){
		TreeNode* node = que.front();
		que.pop();
		
		if(node == NULL ){
			res.push_back(level);
			level.clear();
			if(que.empty()){
				break;
			}else{
				que.push(NULL);
			}
		}else{
			level.push_back(node->val);
			if(node->left)
				que.push(node->left);
			if(node->right)
				que.push(node->right);
		}
	}

	return res;
}

void mainlevelOrder(){

}