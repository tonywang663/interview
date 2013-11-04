#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n) {
	if(head == NULL){
		return NULL;
	}

	ListNode* q1 = head;
	for(int i = 1; i < m; i++)
		q1 = q1->next;

	ListNode* pre;
	if(m == 1)
		pre = NULL;
	else{
		pre = head;
		for(int i = 1; i < m - 1; i++)
			pre = pre->next;
	}

	ListNode* q2 = head;
	for(int i = 1; i < n; i++)
		q2 = q2->next;
	ListNode* post = q2->next;

	ListNode* qpre = q1;
	ListNode* q3 = qpre->next;
	while(q3 != post){
		ListNode* q4 = q3->next;
		q3->next = qpre;
		qpre = q3;
		q3 = q4;
	}

	if(pre != NULL){
		pre->next = q2;
	}else{
		head = q2;
	}

	q1->next = post;

	return head;
}


//08/07/2013
ListNode *reverseBetween1(ListNode *head, int m, int n) {
	if(head == NULL)
		return NULL;

	ListNode dummy(0);
	dummy.next = head;

	ListNode* pre = &dummy;

	for(int i = 1; i <= m - 1; i++)
		pre = pre->next;

	ListNode* end = head;
	for(int i = 1; i <= n - 1; i++)
		end = end->next;

	ListNode* begin = pre->next;
	ListNode* p = begin;
	ListNode* post = end->next;

	ListNode* p0 = pre;
	ListNode* p1 = p->next;

	while(p != post){
		p1 = p->next;
		p->next = p0;
		p0 = p;
		p = p1;
	}

	pre->next = end;
	begin->next = post;

	return dummy.next;
}

void mainreverseBetween(){

}