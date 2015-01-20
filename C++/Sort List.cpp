#include<iostream>
using namespace std;

struct ListNode {
	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return mergeSort(head);
    }
    
    ListNode *mergeSort(ListNode *head) {
    	if(head == NULL || head->next == NULL) {
    		return head;
		}
    	ListNode *slow = head, *fast = head;
    	while(fast->next && fast->next->next) {
    		slow = slow->next;
    		fast = fast->next->next;
		}
		ListNode *mid = slow->next;
		slow->next = NULL;
		head = mergeSort(head);
		mid = mergeSort(mid);
		
		//¹é²¢ 
		ListNode* dummy = new ListNode(-1);
		ListNode* tmp = dummy;
		while(head != NULL || mid != NULL)	{
			if(head == NULL) {
				tmp->next = mid;
				break;
			} else if (mid == NULL) {
				tmp->next = head;
				break;
			}
			
			if(head->val > mid->val) {
				tmp->next = mid;
				mid = mid->next;
			} else {
				tmp->next = head;
				head = head->next;
			}
			tmp = tmp -> next;
		}
		return dummy->next;
	}
    
};
 
int main() {
 	
 	ListNode* head = new ListNode(2);
 	ListNode* n1 = new ListNode(1);
 	ListNode* n2 = new ListNode(14);
 	ListNode* n3 = new ListNode(11);
 	ListNode* n4 = new ListNode(111);
 	head->next = n1;
 	n1->next = n2;
 	
	Solution sol;
	ListNode* newHead = sol.sortList(head);
	while(newHead) {
		cout << newHead->val << " ";
		newHead = newHead->next;
	}
	cout << endl;
	  	
 	system("PAUSE");
 	return 0;
}
