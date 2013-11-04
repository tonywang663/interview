#include <iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function

	if(head == NULL)
		return NULL;

	ListNode* lhead  = new ListNode(0);
	ListNode* rhead = new ListNode(0);
	ListNode* lp = lhead;
	ListNode* rp = rhead;

	ListNode* p = head;

	while(p != NULL){
		ListNode* p1 = p->next;
		if(p->val < x){
			lp->next = p;
			p->next = NULL;
			lp = lp->next;
		}else{
			rp->next = p;
			p->next = NULL;
			rp = rp->next;
		}
		p = p1;
	}

	if(lp == lhead){
		return rhead->next;
	}else{
		lp->next = rhead->next;
		return lhead->next;
	}
    
}




//08/07/2013
ListNode *partition1(ListNode *head, int x) {
	if(head == NULL)
		return head;

	ListNode dummy1(0);
	ListNode dummy2(0);

	dummy1.next = head;
	
	ListNode* p = &dummy1;
	ListNode* p1 = p->next;

	ListNode* q = &dummy2;

	while(p->next != NULL){
		while(p1 != NULL && p1->val < x){
			p = p1;	
			p1 = p1->next;
		}

		if(p1 == NULL)
			break;
		else{
			p->next = p1->next;
			q->next = p1;
			q = p1;
			q->next = NULL;
			p1 = p->next;
		}
	}

	p->next = dummy2.next;
	return dummy1.next;
}

void mainpartition(){

}