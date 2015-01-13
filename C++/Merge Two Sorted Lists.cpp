#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head){
	while(head){
		cout << head->val << "->";
		head = head->next;
	}
	cout << "NULL" << endl;
}

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if(l1 == NULL && l2 == NULL){
			return NULL;
		}
		if(l1 != NULL ^ l2 != NULL){
			return l1 != NULL ? l1 : l2;
		}
        ListNode* newHead = NULL, *cur1 = l1, *cur2 = l2;
        if(cur1->val < cur2->val){
			newHead = cur1;
			cur1 = cur1->next;
		} else {
			newHead = cur2;
			cur2 = cur2->next;
		}
		ListNode* newList = newHead;
        while(cur1 && cur2){
			if(cur1->val < cur2->val){
				newList->next = cur1;
				cur1 = cur1->next;
			} else {
				newList->next = cur2;
				cur2 = cur2->next;
			}
			newList = newList->next;
		}
		while(cur1){
			newList->next = cur1;
			cur1 = cur1->next;
			newList = newList->next;
		}
		while(cur2){
			newList->next = cur2;
			cur2 = cur2->next;
			newList = newList->next;
		}
		return newHead;
    }
};

int main(){
	ListNode* n1 = new ListNode(1);
	ListNode* n3 = new ListNode(3);
	ListNode* n5 = new ListNode(5);
	//n1->next = n3;
	//n3->next = n5;
	
	
	ListNode* n2 = new ListNode(2);
	ListNode* n4 = new ListNode(4);
	//n2->next = n4;
	
	Solution s;
	printList(s.mergeTwoLists(n1, n2));
	
	system("PAUSE");
	return 0;
}
