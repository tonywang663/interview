#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 
void postorder(TreeNode* root){
	if(root == NULL)
		return;

	stack<TreeNode*> stk;
	stk.push(root);

	TreeNode* pre = NULL;
	while(!stk.empty()){
		TreeNode* node = stk.top();
		//traverse down
		if(!pre || pre->left == node || pre->right == node){
			if(node->left)
				stk.push(node->left);
			else if(node->right)
				stk.push(node->right);
			else{
				stk.pop();
				cout<<"node :"<<node->val<<endl;
			}
			pre = node;
			continue;
		}

		//traverse up from left
		if(pre == node->left){
			if(node->right)
				stk.push(node->right);
			else{
				stk.pop();
				cout<<"node :"<<node->val<<endl;
			}
			pre = node;
			continue;
		}

		if(pre == node->right){
			stk.pop();
			cout<<"node :"<<node->val<<endl;
			pre = node;
			continue;
		}
	}

}

//10/12/2013
void posterorder1(TreeNode* root){
	if(root == NULL)
		return;

	stack<TreeNode*> stk;

	stk.push(root);

	TreeNode* pre = NULL;

	while(!stk.empty()){
		TreeNode* node = stk.top();

		//traverse down
		if(!pre || pre->left == node || pre->right == node){
			if(node->left)
				stk.push(node->left);
			else if(node->right)
				stk.push(node->right);
			else{
				stk.pop();
				cout<<"node: "<<node->val<<endl;
			}
		}

		//traverse up from left
		else if(node->left == pre){
			if(node->right)
				stk.push(node->right);
			else{
				stk.pop();
				cout<<"node: "<<node->val<<endl;
			}

		}
		//traverse up from right
		else{
			stk.pop();
			cout<<"node :"<<node->val<<endl;
		}

		pre = node;

		
	}
}

void  preorder(TreeNode* root){
	if(!root)
		return;

	stack<TreeNode*> stk;
	stk.push(root);

	while(!stk.empty()){
		TreeNode* node = stk.top();
		stk.pop();
		cout<<"node :"<<node->val<<endl;

		if(node->right)
			stk.push(node);

		if(node->left)
			stk.push(node);
	}
}

void inorder(TreeNode* root){
	if(!root)
		return;

	stack<TreeNode*> stk;
	TreeNode* node = root;
	while(node){
		stk.push(node);
		node = node->left;
	}

	while(!stk.empty()){
		node = stk.top();
		stk.pop();

		cout<<"node: "<<node->val<<endl;

		if(node->right){
			node = node->right;
			while(node){
				stk.push(node);
				node = node->left;
			}
		}
	}

}

void mainpostorder(){
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
	n1.left = &n2;
	n1.right = &n3;
	n2.right = &n4;
	n3.left = &n5;
	postorder(&n1);
		
	system("pause");
}