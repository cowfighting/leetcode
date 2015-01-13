#include<iostream>
using namespace std;

struct ListNode {
 	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	if(head == NULL) {
    		return NULL;
		}
		ListNode *p = head, *q = head;
		int count = 0;
		while(q) {
			count++;
			if(count == n) {
				break;
			}
			q = q->next;
		}
		//链表长度不够
		if(q == NULL) {
			return head;
		}
		//链表长度刚好和n相等
		if(q->next == NULL) {
			ListNode *tmp = head;
			head = head->next;
			delete tmp;
			return head;
		}
		ListNode *pre;
		while(p->next && q->next) {
			pre = p;
			p = p->next;
			q = q->next;
		}
		pre->next = p->next;
		delete p;
		return head;
    }
};

int main(){
	ListNode *head = new ListNode(1);
	ListNode *n1 = new ListNode(2);
	ListNode *n2 = new ListNode(3);
	ListNode *n3 = new ListNode(4);
	//head->next = n1;
	//n1->next = n2;
	//n2->next = n3;
	
    Solution sol;
    ListNode *head1 = sol.removeNthFromEnd(head, 2);
    
    while(head1) {
    	cout << head1->val << "->";
    	head1 = head1->next;
	}
	cout << endl;
    
    system("PAUSE");
    return 0;
}

