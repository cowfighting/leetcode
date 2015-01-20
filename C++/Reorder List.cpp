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
		//Ѱ���е㣬��ָ�뼴Ϊ�е� 
		ListNode *slow = head->next, *fast = head->next;
		while(fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next; 
		}
		
		//���е��Ժ�Ľ��е��� 
		ListNode *post = slow->next;
		slow->next = NULL;
		while(post) {
			ListNode *tmp = post;
			post = post->next;
			
			tmp->next = slow->next;
			slow->next = tmp;
		}
		
		//����ʼ����е����ν���ȡ�ڵ�
		ListNode *cur = head;
		//�������ε���ʼ�� 
		ListNode *curLeft = head->next, *curRight = slow->next;
		//�ֳ����� 
		slow->next = NULL;
		while(curLeft != NULL || curRight != NULL) {
			//�ڵ���Ϊ����ʱ 
			if(curRight == NULL) {
				cur->next = curLeft;
				break;
			} else if (curLeft == NULL) {
				cur->next = curRight;
				break;
			}
			
			//��ȡ�Ҷ� 
			cur->next = curRight;
			curRight = curRight->next;
			//��ȡ��� 
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
