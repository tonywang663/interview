#include <iostream>
#include <cassert>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head) {
	if(head == NULL){
		return NULL;
	}
	
	ListNode* p = head;
	ListNode* p1 = p->next;
	ListNode* p2 = NULL;
	ListNode* pre = NULL;
	ListNode* temp = NULL;

	if(p1 == NULL){
		return head;
	}else{
		p2 = p1->next;
		p1->next = p;
		p->next = p2;
		temp = p;
		p = p1;
		p1 = temp;
		head = p;
		pre = p1;
	}

	p = p2;
	if(p == NULL){
		return head;
	}else{
		p1 = p->next;
	}

	while(1){
		if(p1 == NULL){
			break;
		}
		p2 = p1->next;
		p1->next = p;
		p->next = p2;
		pre->next = p1;
		temp = p;
		p = p1;
		p1 = temp;
		if(p2 == NULL || p2->next == NULL){
			break;
		}else{
			pre = p1;
			p = p2;
			p1 = p2->next;
		}
	}

	return head;
}

ListNode *swapPairs1(ListNode *head) {
	if(head == NULL)
		return head;

	ListNode* p = head;

	ListNode *dhead = new ListNode(0);


	dhead->next = head;

	ListNode* pre = dhead;

	while(1){
		ListNode* phead = p;

		if(phead == NULL)
			break;

		ListNode* pend = p->next;

		if(pend == NULL)
			break;

		ListNode* nhead = pend->next;

		
		pre->next = pend;

		pend->next = phead;

		phead->next = nhead;

		pre = phead;

		p = nhead;
	}

	return dhead->next;
    
}


int mainswapPairs1()
{
	ListNode n1(1), n2(2), n3(3), n4(4);
	n1.next = &n2;
//	n2.next = &n3;
//	n3.next = &n4;

	ListNode* node =  swapPairs1(&n1);
	system("pause");
	return 0;
}