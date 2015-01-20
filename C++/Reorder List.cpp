#include<iostream>
using namespace std;

struct ListNode {
	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL) {
        	return;
		}
		//寻找中点，慢指针即为中点 
		ListNode *slow = head->next, *fast = head->next;
		while(fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next; 
		}
		
		//将中点以后的进行倒序 
		ListNode *post = slow->next;
		slow->next = NULL;
		while(post) {
			ListNode *tmp = post;
			post = post->next;
			
			tmp->next = slow->next;
			slow->next = tmp;
		}
		
		//从起始点和中点依次交叉取节点
		ListNode *cur = head;
		//左右两段的起始点 
		ListNode *curLeft = head->next, *curRight = slow->next;
		//分成两段 
		slow->next = NULL;
		while(curLeft != NULL || curRight != NULL) {
			//节点数为奇数时 
			if(curRight == NULL) {
				cur->next = curLeft;
				break;
			} else if (curLeft == NULL) {
				cur->next = curRight;
				break;
			}
			
			//先取右段 
			cur->next = curRight;
			curRight = curRight->next;
			//再取左段 
			cur->next->next = curLeft;
			curLeft = curLeft->next;
			
			cur = cur->next->next;
		}
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
	n3->next = n4; 
 	
	Solution sol;
	sol.reorderList(head);
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	  	
 	system("PAUSE");
 	return 0;
}
