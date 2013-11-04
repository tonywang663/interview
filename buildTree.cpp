#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* resbuild(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie){

	if(is > ie)
		return NULL;
	
	int pd = 0, id = 0;
	bool isfind = false;
	for(int i = ps; i <= pe; i++){
		for(int j = is; j <= ie; j++){
			if(preorder[i] == inorder[j]){
				pd = i;
				id = j;
				isfind = true;
				break;
			}
		}

		if(isfind)
			break;
	}


	TreeNode* root = new TreeNode(inorder[id]);

	root->left = resbuild(preorder, pd + 1, pe,  inorder, is, id - 1);	
	root->right = resbuild(preorder, pd + 1, pe, inorder, id + 1, ie);
	return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	
	if(preorder.empty())
		return NULL;

	return 	resbuild(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}


static TreeNode* helper(vector<int> &preorder, int pbegin, vector<int> &inorder, int ibegin, int iend){
	if(ibegin > iend)
		return NULL;
	
	int iindex = -1, pindex = -1;
	
	for(int i = pbegin; i < preorder.size(); i++){
		for(int j = ibegin; j <= iend; j++){
			if(preorder[i] == inorder[j]){
				iindex = j;
				pindex = i;
				break;
			}
		}
		if(iindex >= 0)
			break;
	}

	TreeNode* node = new TreeNode(preorder[pindex]);
	node->left = helper(preorder, pindex + 1, inorder, ibegin, iindex - 1);
	node->right = helper(preorder, pindex + 1, inorder, iindex + 1, iend);
	return node;
}


//08/13/2013
TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder) {
	int len = preorder.size();

	if(len <= 0)
		return NULL;

	return helper(preorder, 0, inorder, 0, len - 1);
    
}

//10/29/2013
TreeNode* bhelper(vector<int>& preorder, int pindex, vector<int>& inorder, int ibegin, int iend){
	if (ibegin > iend)
		return NULL;

	TreeNode* root = new TreeNode(preorder[pindex]);

	int mid = -1;
	for (int i = ibegin; i <= iend; i++){
		if (inorder[i] == root->val){
			mid = i;
			break;
		}
	}

	root->left = bhelper(preorder, pindex + 1, inorder, ibegin, mid - 1);
	root->right = bhelper(preorder, pindex + 1 + mid - ibegin, inorder, mid + 1, iend);
	return root;
}

TreeNode *buildTree3(vector<int> &preorder, vector<int> &inorder) {
	int len = preorder.size();

	if (len <= 0 || len != inorder.size())
		return NULL;
	
	return bhelper(preorder, 0, inorder, 0, len - 1);
}



void mainbuildTree2(){
	int a[] = {1, 2};
	int b[]= {2, 1};
	vector<int> vec1(a, a + sizeof(a) / sizeof(int));
	vector<int> vec2(b, b + sizeof(a) / sizeof(int));
	buildTree2(vec1, vec2);

}