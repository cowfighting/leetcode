#include<iostream>
using namespace std;

struct ListNode {
 	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if(headA == NULL || headB == NULL){
    		return NULL;
		}
		ListNode *tmpA = headA, *tmpB = headB;
		int lenA = 0, lenB = 0;
		while(tmpA){
			lenA++;
			tmpA = tmpA->next;
		}
		while(tmpB){
			lenB++;
			tmpB = tmpB->next;
		}
		tmpA = headA;
		tmpB = headB;
		if(lenA < lenB){
			int tmp = lenB - lenA;
			while(tmp--){
				tmpB = tmpB->next;
			}
		} else {
			int tmp = lenA - lenB;
			while(tmp--){
				tmpA = tmpA->next;
			}
		}
		while(tmpA != tmpB){
			tmpA = tmpA->next;
			tmpB = tmpB->next;
		}
		return tmpA;
    }
};

int main(){
	ListNode *headA = new ListNode(1);
	
	ListNode *head1 = new ListNode(2);
	ListNode *head2 = new ListNode(3);
	ListNode *head3 = new ListNode(4);
	
	ListNode *headB = new ListNode(5);
	
	headA->next = head1;
	//head1->next = head2;
	//head2->next = head3;
	
	headB->next = head2;
	
	
	
    Solution sol;
    cout << sol.getIntersectionNode(headA, headB) << endl;
    
    system("PAUSE");
    return 0;
}

