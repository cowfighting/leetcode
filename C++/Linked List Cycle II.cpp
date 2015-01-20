#include<iostream>
using namespace std;

struct ListNode {
	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
		if(head == NULL || head->next == NULL) {
			return NULL;
		}
		ListNode *slow = head, *fast = head;
		while(fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
			if(fast == slow) {
				slow = head;
				while(slow != fast) {
					slow = slow->next;
					fast = fast->next;
				}
				return slow;
			}
		}
        return NULL; 
    }
};
 
int main() {
 	
 	ListNode* head = new ListNode(1);
 	ListNode* n1 = new ListNode(2);
 	ListNode* n2 = new ListNode(3);
 	ListNode* n3 = new ListNode(4);
 	ListNode* n4 = new ListNode(5);
 	head->next = n1;
 	n1->next = n2;
 	n2->next = n3;
	n3->next = n2; 
 	
	Solution sol;
	ListNode *begin = sol.detectCycle(head);
	if(begin != NULL) {
		cout << begin->val;
	}
	cout << endl;
 	system("PAUSE");
 	return 0;
}
