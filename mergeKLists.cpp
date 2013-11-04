#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
	vector<ListNode*>::iterator it = lists.begin();

	ListNode* head = NULL;
	ListNode* tail = NULL;


	int len = lists.size();
	
	bool isallNULL = false;
	while(1){
		int index;
		int numNULL = 0;
		bool dosappear = false;
		int min;
		for(int i = 0; i <= len - 1; i++){
			if(lists[i] == NULL){
				numNULL++;
				continue;
			}else{
				if(dosappear == false){
					dosappear = true;
					min = lists[i]->val;
					index = i;
				}else{
					if(min >  lists[i]->val){
						min =  lists[i]->val;
						index = i;
					}
				}
			}

		}
//		res.push_back(lists[index]);

		if(numNULL == len){
			break;
		}

		if(head == NULL){
			head = lists[index];
			lists[index] = lists[index]->next;
			head->next = NULL;
			tail = head;
		}else{
			tail->next = lists[index];
			lists[index] = lists[index]->next;
			tail = tail->next;
			tail->next = NULL;
		}
	}
	return head;
}


ListNode *mergeKLists1(vector<ListNode *> &lists) {
	int len = lists.size();

	if(len <= 0)
		return NULL;

	ListNode head(0);

	ListNode *p = &head;

	while(1){
		int index = -1;
		for(int i = 0; i < len; i++){
			if(lists[i] == NULL){
				continue;
			}else{
				if(index == -1){
					index = i;
				}else if(lists[i]->val < lists[index]->val){
					index = i;
				}
			}
		}

		if(index == -1)
			break;
		else{
			p->next = lists[index];
			lists[index] = lists[index]->next;
			p = p->next;
		}

	}

	return head.next;

}

int mainmergeKLists1()
{
	ListNode n1(1);
ListNode n2(2);
ListNode n3(3);
ListNode n4(4);
n1.next = &n3;
//n2.next = &n4;

vector<ListNode *> list;
vector<ListNode *> list1;
list.push_back(&n1);
list.push_back(&n2);
ListNode *node = mergeKLists(list1);

	system("pause");
	return 0;
}