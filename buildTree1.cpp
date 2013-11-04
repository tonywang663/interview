#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* resbuild1(vector<int> &inorder, int left, int right, vector<int> &postorder, int pleft, int pright){
	if(left > right)
		return NULL;

	int len = postorder.size();

	int rootind = -1, pind = -1;
	for(int i = pright; i >= pleft; i--){
		for(int j = left; j <= right; j++){
			if(postorder[i] == inorder[j]){
				rootind = j;
				pind = i;
				break;
			}
		}
		if(rootind != -1)
			break;
	}

	TreeNode* root = new TreeNode(inorder[rootind]);

	root->left = resbuild1(inorder, left, rootind - 1, postorder, pleft, pind - 1);
	root->right = resbuild1(inorder, rootind + 1, right, postorder, pleft, pind - 1);

	return root;


}

TreeNode *buildTree1(vector<int> &inorder, vector<int> &postorder) {
	int len = inorder.size();

	if(len == 0)
		return NULL;

	return 	resbuild1(inorder, 0, len - 1, postorder, 0, len - 1);
}

TreeNode* helper(vector<int> &postorder, int pend, vector<int> &inorder, int ibegin, int iend){
	if(ibegin > iend)
		return NULL;

	int iindex = -1, pindex = -1;
	for(int i = pend; i >= 0; i--){
		for(int j = ibegin; j <= iend; j++){
			if(postorder[i] == inorder[j]){
				pindex = i;
				iindex = j;
				break;
			}
		}
		if(pindex >= 0)
			break;
	}

	TreeNode* node = new TreeNode(postorder[pindex]);
	node->left = helper(postorder, pend - 1, inorder, ibegin, iindex - 1); 
	node->right = helper(postorder, pend - 1, inorder, iindex + 1, iend); 
	return node;
}

//08/13/2013
TreeNode *buildTree11(vector<int> &inorder, vector<int> &postorder) {
	int len = inorder.size();

	if(len <= 0)
		return NULL;

	return helper(postorder, len - 1, inorder, 0, len - 1);
}


static TreeNode* bhelper(vector<int> &postorder, int pindex, vector<int> &inorder, int ibegin, int iend){
	if (ibegin > iend)
		return NULL;

	int mid = -1;

	TreeNode* node = new TreeNode(postorder[pindex]);

	for (int i = ibegin; i <= iend; i++){
		if (inorder[i] == node->val){
			mid = i;
			break;
		}
	}

	node->left = bhelper(postorder, pindex - (iend - mid) - 1, inorder, ibegin, mid - 1);
	node->right = bhelper(postorder, pindex - 1, inorder, mid + 1, iend);
	return node;
}

//10/29/2013
static TreeNode *buildTree3(vector<int> &inorder, vector<int> &postorder) {
	int len = inorder.size();

	if (len <= 0)
		return NULL;

	return bhelper(postorder, len - 1, inorder, 0, len - 1);
}
void mainbuildTree1(){

}