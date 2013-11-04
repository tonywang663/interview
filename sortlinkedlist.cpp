#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


void swap(ListNode* p1){
	ListNode* p2 = p1->next;

	if(p2 == NULL)
		return;

	ListNode* p3 = p2->next;

	if(p3 == NULL)
		return;

	if(p2->val <= p3->val)
		return;

	ListNode* p4 = p3->next;

	p1->next = p3;
	p3->next = p2;
	p2->next = p4;
}

ListNode* sortlinkedlist(ListNode* head){
	if(head == NULL)
		return NULL;

	ListNode dummy(0);

	dummy.next = head;

	ListNode *p2 = head;

	int len = 0;
	while(p2 != NULL){
		p2 = p2->next;
		len++;
	}

	for(int i = 1; i <= len; i++){
		ListNode* p1 = &dummy;
		
		for(int j = 1; j <= len - i; j++){
			swap(p1);
			p1=p1->next;
		}
	}
	return dummy.next;
}

ListNode* merge(ListNode* p1, ListNode* p2, int scale){
	ListNode dummy(0);
	ListNode *p = &dummy;

	int num1 = 0;
	int num2 = 0;
	while (1){
		if (num1 == scale && num2 == scale)
			break;
		else if (num1 < scale && (num2 == scale || p2 == NULL)){
			p->next = p1;
			break;
		}
		else if (num1 == scale && num2 < scale){
			p->next = p2;
			break;
		}
		else{
			if (p1->val < p2->val){
				p->next = p1;
				p1 = p1->next;
				num1++;
			}
			else{
				p->next = p2;
				p2 = p2->next;
				num2++;
			}
			p = p->next;
		}
	}
	return dummy.next;
}

//O(nlgn) solution 10/31/2013
ListNode* sortlinkedlist1(ListNode* head){
	if (head == NULL)
		return NULL;

	ListNode* p = head;
	int len = 0;
	while (p){
		len++;
		p = p->next;
	}

	ListNode dummy(0);
	dummy.next = head;

	int scale = 1;

	while (scale < len){
		ListNode* pre = &dummy;
		ListNode* post = NULL;

		while (1){
			ListNode* p1 = pre->next;
			if (!p1)
				break;

			int tlen = 0;
			post = p1;
			for (int i = 1; i <= 2 * scale; i++){
				tlen++;
				post = post->next;
				if (!post)
					break;
			}

			ListNode* p2 = p1;
	
			for (int i = 1; i <= scale; i++){
				p2 = p2->next;
				if (!p2)
					break;
			}

			if (p2){
				pre->next = merge(p1, p2, scale);
				for (int i = 1; i <= tlen; i++){
					pre = pre->next;
					if (!pre)
						break;
				}

				pre->next = post;

			}
			else{
				break;
			}
		}

		scale *= 2;
	}
	return dummy.next;
}

void mainsortlinkedlist1(){
	ListNode n1(5), n2(4), n3(3), n4(2);
	n1.next = &n2;
	n2.next = &n3;
//	n3.next = &n4;
	ListNode* node = sortlinkedlist1(&n1);
	system("pause");
}