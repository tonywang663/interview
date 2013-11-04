#include <iostream>
#include <cassert>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

 ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	 assert(l1 != NULL && l2 != NULL);

	 ListNode* p1 = l1;
	 ListNode* p2 = l2;

	 ListNode* head;

	 int flow = 0;
	 if(p1->val + p2->val >= 10)
	 {
		flow = 1;
		head = new ListNode(p1->val+p2->val - 10);
		
	 }else
	 {
		head = new ListNode(p1->val+p2->val);
	 }
	 ListNode* prenode = head;
	 p1 = p1->next;
	 p2 = p2->next;

	 while(p1 != NULL && p2 != NULL)
	 {
		ListNode *node;
		if(p1->val+p2->val + flow >= 10)
		{
			node = new ListNode(p1->val+p2->val + flow - 10);
			flow = 1;
		}else
		{
			node = new ListNode(p1->val+p2->val + flow);
			flow = 0;
		}
		prenode->next = node;
		prenode = node;
		 p1 = p1->next;
		 p2 = p2->next;
	 }


	while(p1 != NULL)
	{
		ListNode *node;
		if(p1->val + flow >= 10)
		{
			node = new ListNode(p1->val + flow - 10);
			flow = 1;
		}else
		{
			node = new ListNode(p1->val + flow);
			flow = 0;
		}
		prenode->next = node;
		prenode = node;
		p1 = p1->next;
	}


	while(p2 != NULL)
	{
		ListNode *node;
		if(p2->val + flow >= 10)
		{
			node = new ListNode(p2->val + flow - 10);
			flow = 1;
		}else
		{
			node = new ListNode(p2->val + flow);
			flow = 0;
		}
		prenode->next = node;
		prenode = node;
		p2 = p2->next;
	}

	 if(flow == 1)
	 {
		ListNode *node = new ListNode(1);
		prenode->next = node;
		prenode = node;
	 }

	return head;
 }
//typedef struct ListNode ListNode;



ListNode *addTwoNumbers1(ListNode *l1, ListNode *l2) {
	if(l1 == NULL)
		return l2;

	if(l2 == NULL)
		return l1;

	int overflow = 0;
	ListNode* p1 = l1;
	ListNode* p2 = l2;
	ListNode* head = new ListNode(0);
	ListNode* q = head;
	while(1){
		if(p1 != NULL && p2 != NULL){
			int t = p1->val + p2->val + overflow;
			if(t >= 10){
				t -= 10;
				overflow = 1;
			}else{
				overflow = 0;
			}
			p1 = p1->next;
			p2 = p2->next;
			ListNode* q1 = new ListNode(t);
			q->next = q1;
			q = q->next;
			continue;
		}
	

		if(p1 == NULL && p2 == NULL){
			if(overflow > 0){
				ListNode* q1 = new ListNode(overflow);
				q->next = q1;
			}
			break;
		}

		if(p1 != NULL && p2 == NULL){
			int t = p1->val + overflow;
			if(t >= 10){
				t -= 10;
				overflow = 1;
			}else{
				overflow = 0;
			}
			ListNode* q1 = new ListNode(t);
			q->next = q1;
			q = q->next;
			p1 = p1->next;
			continue;
		}

		if(p1 == NULL && p2 != NULL){
			int t = p2->val + overflow;
			if(t >= 10){
				t -= 10;
				overflow = 1;
			}else{
				overflow = 0;
			}
			ListNode* q1 = new ListNode(t);
			q->next = q1;
			q = q->next;
			p2 = p2->next;
			continue;
		}
	}
	return head->next;
}


//09/08/2013
ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
	if(l1 == NULL)
		return l2;

	if(l2 == NULL)
		return l1;


	ListNode* p1 = l1, *p2 = l2;
	ListNode head(0);
	ListNode* p = &head;
	int of = 0;
	while(1){
		if(p1 == NULL && p2 == NULL){
			if(of > 0){
				ListNode* node = new ListNode(of);
				p->next = node;
			}
			break;
		}
			

		if(p1 == NULL){
			int t = of + p2->val;
			if(t == 10){
				t = 0;
				of = 1;
			}else
				of = 0;

			ListNode* node = new ListNode(t);
			p->next = node;
			p2 = p2->next;
			p = p->next;
			continue;
		}

		if(p2 == NULL){
			int t = of + p1->val;
			if(t == 10){
				t = 0;
				of = 1;
			}else
				of = 0;

			ListNode* node = new ListNode(t);
			p->next = node;
			p1 = p1->next;
			p = p->next;
			continue;
		}	

		int t = of + p1->val + p2->val;
		if(t >= 10){
			t = t % 10;
			of = 1;
		}else
			of = 0;

		ListNode * node = new ListNode(t);
		p->next = node;
		p1 = p1->next;
		p2 = p2->next;
		p = p->next;
	}
    return head.next;
}

int mainaddTwoNumbers1()
{
	ListNode* n11 = new ListNode(3);
	ListNode* n12 = new ListNode(4);
	ListNode* n13 = new ListNode(2);
	n13->next = n12;
	n12->next = n11;

	ListNode* n21 = new ListNode(4);
	ListNode* n22 = new ListNode(6);
	ListNode* n23 = new ListNode(5);
	n23->next = n12;
	n22->next = n11;

	struct ListNode * n24;
	//ListNode* res = addTwoNumbers(n13, n23);
	system("pause");
	return 0;
}