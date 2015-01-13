#include<iostream>
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head){
    while(head){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* cur = head, *pre = NULL;
        while(cur){
            pre = cur;
            ListNode* curNext = cur->next;
            while(curNext){
                if(curNext->val == cur->val){
                    pre->next  = curNext->next;
                    delete curNext;
                    curNext = pre->next;
                } else {
                    pre = curNext;
                    curNext = curNext->next;
                }
            }
            cur = cur->next;
        }
        return head;
    }
};

int main(){    
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(3);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    Solution s;
    s.deleteDuplicates(head);
    printList(head);
    
    system("PAUSE");
    return 0;
}

