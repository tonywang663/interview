#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* ressort(vector<int>& num, int left, int right){
	if(left > right)
		return NULL;

	int mid = (left + right) / 2;

	TreeNode* p = new TreeNode(num[mid]);

	p->left = ressort(num, left, mid - 1);

	p->right = ressort(num, mid + 1, right);

	return p;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
	if(num.empty())
		return NULL;

	return ressort(num, 0, num.size() - 1);   
}

void mainsortedArrayToBST(){

}