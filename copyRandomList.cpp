#include <vector>

using namespace std;

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
	if(head == NULL)
		return head;

	RandomListNode* p = head;

	while(p != NULL){
		RandomListNode* nnode = new RandomListNode(p->label);
		nnode->next = p->next;
		p->next = nnode;
		p = nnode->next;
	}

	p = head;

	while(p != NULL){
		RandomListNode* nnode = p->next;
		if(p->random)
			nnode->random = p->random->next;
		p = nnode->next;
	}
    
	RandomListNode* nhead = head->next;

	p = head;
	while(1){
		RandomListNode* nnode = p->next;
		p->next = nnode->next;
		if(nnode->next){
			nnode->next = nnode->next->next;
			p = p->next;
		}else
			break;
	}

	return nhead;
}

void maincopyRandomList(){

}