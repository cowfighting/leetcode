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
		ListNode *tmpA = headA; 
		while(tmpA->next){
			tmpA = tmpA->next;
		}
		//将问题转化为求环入口点 
		tmpA->next = headA;
		ListNode *one = headB, *two = headB;
		while(two->next && two->next->next){
			one = one->next;
			two = two->next->next;
			//环存在 
			if(one == two){
				//一个指针从head开始，一个指针从相遇点开始，再次相遇即为入口点 
				ListNode *start1 = one, *start2 = headB;
				while(start1 != start2){
					start1 = start1->next;
					start2 = start2->next;
				}
				return start1;
			}
		}
		//恢复结构 
		tmpA->next = NULL;
		return NULL;
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
	
	headB->next = head1;
	
	
	
    Solution sol;
    cout << sol.getIntersectionNode(headA, headA)->val << endl;
    
    system("PAUSE");
    return 0;
}

