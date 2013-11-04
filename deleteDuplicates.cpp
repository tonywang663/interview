#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head) {
	if(head == NULL){
		return NULL;
	}

	ListNode* p = head;

	while(p->next != NULL){
		ListNode* p1 = p->next;
		if(p->val == p1->val){
			p->next = p1->next;
			p1->next = NULL;
		}else{
			p = p->next;
		}
	}
	return head;
    
}


ListNode *deleteDuplicates2(ListNode *head) {
	if(head == NULL){
		return NULL;
	}

	ListNode* p = head;

	ListNode dhead(0);
	dhead.next = head;

	ListNode* pre = &dhead;

	bool dup = false;
	while(p->next != NULL){
		ListNode* p1 = p->next;
		while(p1 != NULL && p->val == p1->val){
			dup = true;
			p->next = p1->next;
			p1->next = NULL;
			p1= p->next;
		}

		if(dup){
			pre->next = p->next;
			p->next = NULL;
			dup = false;
			p = pre->next;
		}else{
			pre = p;
			p = p->next;
		}
		if(p == NULL){
			return dhead.next;
		}
	}

	return dhead.next;
    
}

//08/06/2013
ListNode *deleteDuplicates3(ListNode *head) {
	if(head == NULL)
		return head;

	ListNode* p1 = head;
	ListNode* p2 = p1;

	while(p1 != NULL){
		while(p2 != NULL && p2->val == p1->val)
			p2 = p2->next;

		p1->next = p2;
		p1 = p2;
	}

	return head;
}

//delete duplicates2
ListNode *deleteDuplicates4(ListNode *head) {
	if(head == NULL)
		return head;

	ListNode dummy(0);
	dummy.next = head;
	ListNode* p1 = &dummy;
	ListNode* p2 = p1->next;
	ListNode* p3 = p2;

	while(p2 != NULL){
		while(p3 != NULL && p3->val == p2->val)
			p3 = p3->next;

		if(p2->next == p3){
			p1 = p2;
			p2 = p3;
		}else{
			p1->next = p3;
			p2 = p3;
		}
	}

	return dummy.next;
    
}

void maindeleteDuplicates2(){

}