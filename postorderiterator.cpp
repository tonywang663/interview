#include <stack>
#include <iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int _val) :val(_val), left(NULL), right(NULL){}
};

class PostIter{
	stack<TreeNode*> stk;
	TreeNode* pre;

public:
	PostIter(TreeNode* root){
		TreeNode* node = root;
		while (node){
			stk.push(node);
			node = node->left;
		}
		pre = NULL;
	}

	TreeNode* next(){
		if (stk.empty())
			return NULL;
		TreeNode* ret = NULL;
		while (1){
			TreeNode* node = stk.top();
			if (!pre || pre->left == node || pre->right == node){
				if (node->left){
					stk.push(node->left);
				}
				else if (node->right)
					stk.push(node->right);
				else{
					stk.pop();
					ret = node;
				}
			}
			else if (node->left == pre){
				if (node->right)
					stk.push(node->right);
				else{
					stk.pop();
					ret = node;
				}
			}
			else if (node->right == pre){
				stk.pop();
				ret = node;
			}

			pre = node;
			if (ret)
				return ret;
		}
	}

};

void mainPostIter(){

	TreeNode n1(1), n2(2), n3(3), n4(4);
	n1.left = &n2;
	n2.right = &n3;
	n1.right = &n4;
	PostIter it(&n1);
	TreeNode* node = NULL;
	while ((node = it.next()) != NULL)
		cout << node->val << endl;
	system("pause");
}