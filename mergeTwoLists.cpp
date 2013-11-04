#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	if(l1 == NULL){
		return l2;
	}

	if(l2 == NULL){
		return l1;
	}

	ListNode* head;

	if(l1->val < l2->val){
		head = l1;
		l1 = l1->next;
	}else{
		head = l2;
		l2 = l2->next;
	}

	ListNode* p = head;

	while(1){
		if(l1 == NULL){
			p->next = l2;
			break;
		}

		if(l2 == NULL){
			p->next = l1;
			break;
		}

		if(l1->val < l2->val){
			p->next = l1;
			p = p->next;
			l1 = l1->next;
		}else{
			p->next = l2;
			p = p->next;
			l2 = l2->next;
		}

	}

	return head;
    
}


ListNode *mergeTwoLists1(ListNode *l1, ListNode *l2) {
	if(l1 == NULL)
		return l2;

	if(l2 == NULL)
		return l1;

	ListNode head(0);

	ListNode* p = &head;

	while(1){
		if(l1 == NULL && l2 == NULL)
			break;

		if(l1 == NULL){
			p->next = l2;
			break;
		}

		if(l2 == NULL){
			p->next = l1;
			break;
		}

		if(l1->val < l2->val){
			p->next = l1;
			l1 = l1->next;
			p = p->next;
			p->next = NULL;
		}else{
			p->next = l2;
			l2 = l2->next;
			p = p->next;
			p->next = NULL;
		}
	}
    
	return head.next;
}


int mainmergeTwoLists()
{
	ListNode n1(1), n2(2);
	mergeTwoLists(&n1, &n2);
	return 0;

}