#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<vector<int> > levelOrderBottom(TreeNode *root) {
	vector<vector<int> > res;
	if(!root)
		return res;

	queue<TreeNode*> que;

	que.push(root);
	que.push(NULL);

	vector<int> level;
	while(!que.empty()){
		TreeNode* node = que.front();
		que.pop();

		if(!node && que.empty()){
			res.insert(res.begin(), level);
			break;
		}
		else if(!node){ 
			que.push(NULL);
			res.insert(res.begin(), level);
			level.clear();
			continue;
		}
		
		int val = node->val;
		level.push_back(val);

		if(node->left != NULL)
			que.push(node->left);

		if(node->right != NULL)
			que.push(node->right);
	}

	return res;
    
}

void mainlevelOrderBottom(){

	TreeNode root(1);
	levelOrderBottom(&root);

}