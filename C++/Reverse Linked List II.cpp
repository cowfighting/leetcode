#include<iostream>
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void insertNode(ListNode* &head, int data){
    ListNode* newNode = new ListNode(data);
    if(head == NULL){
        head = newNode;
    }else{
        ListNode* cur = head;
        while(cur){
            if(cur->next == NULL){
                cur->next = newNode;
                break;
            }else{
                cur = cur->next;
            }
        }
    }
}

void printList(ListNode* head){
    while(head){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

/*ListNode *reverseBetween(ListNode *head, int m, int n) {
    if(m == n){
        return head;
    }
    ListNode* cur = head;
    ListNode* pre = NULL;
    int curNum = 0;
    //ÕÒµ½mµã 
    while(cur){
        curNum++;
        if(curNum == m){
            break;
        }else{
            pre = cur;
            cur = cur->next; 
        }
    }
    while(curNum < n){
        ListNode* curNext = cur->next;
        cur->next = curNext->next;
        if(pre == NULL){
            curNext->next = head;
            head = curNext;
        }else{
            curNext->next = pre->next; 
            pre->next = curNext;
        }
        curNum++;
    }
    return head;
}*/

ListNode *reverseBetween(ListNode *head, int m, int n) {
    if(m>=n) return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    int s = m;
    // get to the start point
    while(--s){ 
        dummy = dummy->next;
        --n;
    }
    ListNode *p1 = dummy->next;
    ListNode *p2 = p1->next;
    ListNode *p3;
    //start reverse
    while(--n){
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    dummy->next->next = p2; //link to the left part
    dummy->next = p1; //link to new beginning
    if(m==1) return dummy->next; // head has changed, reference by dummy
    return head;
}

int main(){    
    ListNode* head = NULL;
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    printList(head);
    reverseBetween(head,1,4);
    printList(head);
    
    getchar();
    return 0;
}
