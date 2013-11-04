#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k) {

	ListNode* p = head;

	if(head == NULL || k == 0){
		return head;
	}

	int len = 0;
	for(; p != NULL; p = p->next){
		len++;
	}

	k = k % len;

	if(k == 0){
		return head;
	}

	int newend = len - k;

	p = head;
	for(int i = 0; i < newend - 1; i++){
		p = p->next;
	}

	ListNode* newhead = p->next;

	p->next = NULL;

	ListNode* subtail = newhead;

	while(subtail->next != NULL){
		subtail = subtail->next;
	}

	subtail->next = head;

	head = newhead;

	return head;
}


ListNode *rotateRight1(ListNode *head, int k) {

	if(head == NULL || k <= 0){
		return head;
	}

	int len = 0;
	
	ListNode* p = head;

	while(p != NULL){
		p = p->next;
		len++;
	}

	k = k % len;

	if(k == 0)
		return head;

	ListNode* ftail = head;

	for(int i = 1; i <= len - k - 1; i++){
		ftail = ftail->next;
	}

	ListNode* shead = ftail->next;

	ListNode* stail = shead;

	while(stail->next != NULL){
		stail = stail->next;
	}

	stail->next = head;

	ftail->next = NULL;

	return shead;
    
}

int mainrotateRight()
{
	return 0; 
}