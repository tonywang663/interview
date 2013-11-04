#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<TreeNode*> restree(int left, int right){
	vector<TreeNode*> tree;

	if(left > right){
		tree.push_back(NULL);
	}

	if(left == right){
		TreeNode* leaf = new TreeNode(left);
		tree.push_back(leaf);
		return tree;
	}

	
	for(int i = left; i <= right; i++){
		vector<TreeNode*> ltrees = restree(left, i - 1);
		vector<TreeNode*> rtrees = restree(i + 1, right);
		
		for(int j = 0; j < ltrees.size(); j++){
			for(int k = 0; k < rtrees.size(); k++){
				TreeNode* root = new TreeNode(i);
				root->left = ltrees[j];
				root->right = rtrees[k];
				tree.push_back(root);
			}
		}
	}


	return tree;
}


vector<TreeNode *> generateTrees(int n) {

	vector<TreeNode *> res(1, NULL);

	if(n <= 0){
		return res;
	}

	return restree(1, n);
}



vector<TreeNode*> helper(int left, int right){
	vector<TreeNode*> tree;
	if(left > right){
		tree.push_back(NULL);
		return tree;
	}

	if(left == right){
		TreeNode* node = new TreeNode(left);
		tree.push_back(node);
		return tree;
	}

	for(int i = left; i <= right; i++){
		
		vector<TreeNode*> ltrees = helper(left, i - 1);
		vector<TreeNode*> rtrees = helper(i + 1, right);
		for(int j = 0; j < ltrees.size(); j++){
			for(int k = 0; k < rtrees.size(); j++){
				TreeNode* root = new TreeNode(i);
				root->left = ltrees[j];
				root->right = rtrees[k];
				tree.push_back(root);
			}
		}
	}

	return tree;
}

//08/08/2013
vector<TreeNode *> generateTrees1(int n) {

	return helper(1, n);
    
}

void maingenerateTrees(){
	generateTrees(2);
}