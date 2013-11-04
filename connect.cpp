#include <queue>

using namespace std;


struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };


void connect(TreeLinkNode *root) {
	if(!root)
		return;

	queue<TreeLinkNode*> que;
	que.push(root);
	que.push(NULL);

	while(!que.empty()){
		TreeLinkNode* node = que.front();
		que.pop();

		if(!node && que.empty()){
			break;
		}
		
		if(!node){
			que.push(NULL);
			continue;
		}

		TreeLinkNode* next = que.front();
		node->next = next;
		

		if(node->left)
			que.push(node->left);

		if(node->right)
			que.push(node->right);
	}
    
}

//08/10/2013 populate II
void connect1(TreeLinkNode *root) {
	if(root == NULL)
		return;

	queue<TreeLinkNode*> que;
	que.push(root);
	que.push(NULL);

	TreeLinkNode* pre = NULL;

	while(1){
		TreeLinkNode* node = que.front();
		que.pop();

		if(node == NULL){
			pre->next = NULL;
			if(que.empty())
				break;
			else{
				pre = NULL;
				que.push(NULL);
			}
		}else{
			if(pre != NULL)
				pre->next = node;

			pre = node;

			if(node->left)
				que.push(node->left);
			if(node->right)
				que.push(node->right);
		}

	}
    
}

void mainconnect(){

}