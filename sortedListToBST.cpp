#include <cmath>
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//08/13/2013
TreeNode* helper(ListNode* head, int len){
	if(len == 0)
		return NULL;

	ListNode* node = head;

	for(int i = 1; i <= ceil((float)len / 2) - 1; i++)
		node = node->next;

	TreeNode* tnode = new TreeNode(node->val);

	tnode->left = helper(head, ceil((float)len / 2) - 1);
	tnode->right = helper(node->next, len - ceil((float)len / 2));
	return tnode;
}

TreeNode *sortedListToBST(ListNode *head) {
	if(head == NULL)
		return NULL;

	int len = 0;

	ListNode* node  = head;
	
	while(node != NULL){
		len++;
		node = node->next;
	}
	
    return helper(head, len);
}