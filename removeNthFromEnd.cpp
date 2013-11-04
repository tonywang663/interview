#include <iostream>
#include <cassert>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

ListNode *removeNthFromEnd(ListNode *head, int n) {
	assert(head != NULL && n > 0);

	int len = 0;
	ListNode* p = head;
	while(p != NULL)
	{
		p = p->next;
		len++;
	}

	int num = len - n + 1;

	p = head;
	if(num == 1)
	{
		head = p->next;
		p->next = NULL;
		delete p;
		return head;
	}

	
	for(int i = 1; i < num - 1; i++)
	{
		p = p->next;
	}

	ListNode* p1 = p->next;

	p->next = p1->next;
	p1->next = NULL;
	delete p1;
	return head;
}

ListNode *removeNthFromEnd1(ListNode *head, int n) {
	if(head == NULL || n <= 0)
		return head;

	int len = 0;

	ListNode* p = head;
	while(p != NULL){
		p = p->next;
		len++;
	}

	if(len < n)
		return head;

	int m = len - n + 1;

	p = head;

	if(m == 1){
		head = head->next;
		return head;
	}

	for(int i = 1; i < m - 1; i++){
		p = p->next;
	}

	p->next = p->next->next;

	return head;
    
}

int mainremoveNthFromEnd1()
{

	system("pause");
	return 0;
}