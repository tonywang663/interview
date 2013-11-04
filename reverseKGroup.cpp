#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


ListNode *reverseKGroup(ListNode *head, int k) {
	if(head == NULL || k <= 1){
		return head;
	}

	ListNode *p = head;
	ListNode *p1;
	
	for(int i = 1; i <= k - 1; i++){
		if(p->next == NULL){
			return head;
		}else{
			p = p->next;
		}
	}

	//handle first k
	ListNode* temp = p;
	p = head;
	head = temp;
	ListNode* tail = p;
	p1 = p->next;
	ListNode *p2 = NULL, *pre = NULL;
	
	for(int i = 1; i <= k - 1; i++){
		p2 = p1->next;
		p1->next = p;
		p->next = pre;
		pre = p;
		p = p1;
		p1 = p2;
	}


//handle rest nodes;

	ListNode* newhead, *newtail;
	while(1){
		newhead = p1;
		newtail = p1;
		p = p1;
		if(p == NULL){
			return head;
		}
		for(int i = 1; i <= k - 1; i++){
			if(p->next == NULL){
				tail->next = newhead;
				return head;
			}else{
				p = p->next;
			}
		}
		
		temp = newhead;
		newhead = p;
		p = temp;

		p1 = p->next;
		
		
		for(int i = 1; i <= k - 1; i++){
			p2 = p1->next;
			p1->next = p;
			p->next = pre;
			pre = p;
			p = p1;
			p1 = p2;
		}
		tail->next = newhead;
		tail = newtail;

	}
	return head;

    
}

ListNode* rk(ListNode *head, int k){
	ListNode* p = head;

	if(p == NULL)
		return NULL;

	for(int i = 1; i <= k - 1; i++){
		p = p->next;
		if(p == NULL){
			return NULL;
		}
	}

	ListNode* end = p->next;

	ListNode* p1 = NULL;
	ListNode* p2 = head;
	ListNode* p3 = NULL;

	while(p2 != end){
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}

	head->next = p3;
	return p1;

}


ListNode *reverseKGroup1(ListNode *head, int k) {
	if(head == NULL || k <= 1)
		return head;

	ListNode* p = rk(head, k);

	if(p == NULL)
		return head;
	else
		head = p;
	
	while(1){
		for(int i = 1; i <= k - 1; i++){
			p = p->next;
		}
		ListNode* newhead = p->next;
		ListNode* newhead1 =  rk(newhead, k);
		if(newhead1 == NULL)
			break;
		else
			p->next = newhead1;
		
		p = p->next;
	}   
	return head;
}


int mainreverseKGroup1()
{
	ListNode n1(1), n2(2), n3(3), n4(4);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	ListNode *n = reverseKGroup1(&n1, 2);
	system("pause");
	return 0;
}