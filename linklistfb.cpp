#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val_) :val(val_), next(NULL){}
};

void linklistfb(ListNode* head){
	if (!head)
		return;

	ListNode* cur = head;

	int len = 0;

	while (cur){
		cur = cur->next;
		len++;
	}

	if (len <= 2)
		return;

	cur = head;

	for (int i = 1; i <= (len - 1) / 2; i++){
		ListNode* prelast = head;
		for (int j = 1; j <= len - 2; j++)
			prelast = prelast->next;

		ListNode* last = prelast->next;
		last->next = cur->next;
		cur->next = last;
		prelast->next = NULL;
		cur = last->next;
	}
}


void reorderList(ListNode *head) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	if (!head)
		return;

	ListNode* cur = head;

	int len = 0;

	while (cur){
		cur = cur->next;
		len++;
	}

	if (len <= 2)
		return;

	cur = head;

	for (int i = 1; i <= (len - 1) / 2; i++){
		cur = cur->next;
	}

	ListNode* nhead = cur->next;
	cur->next = NULL;

	ListNode* p1 = NULL, *p2 = nhead;

	while (p2 != NULL){
		ListNode* p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}

	nhead = p1;

	cur = head;

	ListNode dummy(0);

	ListNode* q = &dummy;

	while (1){
		if (cur == NULL)
			break;
		if (nhead != NULL){
			q->next = cur;
			cur = cur->next;
			q = q->next;
			q->next = nhead;
			nhead = nhead->next;
			q = q->next;
		}
		else if (cur != NULL){
			q->next = cur;
			cur = cur->next;
		}
	}

}

void main(){
	ListNode n1(1), n2(2), n3(3), n4(4);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	//n4.next = &n5;
//	linklistfb(&n1);
	reorderList(&n1);
	system("pause");
}