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

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        /*if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* cur = head->next;
        head->next = NULL;
        while(cur){
            ListNode* tmpNext = cur->next;
            ListNode* index = NULL;//插入位置
            ListNode* tmpHead = head;
            while(head){
                if(head->val > cur->val){
                    break;
                }
                index = head;
                head = head->next;
            }
            //插入位置在头结点之前 
            if(index == NULL){
                cur->next = tmpHead;
                tmpHead = cur;
            }else{
                cur->next = index->next;
                index->next = cur;
            }           
            head = tmpHead;
            cur = tmpNext;
        }
        return head;
        */
        if((head==NULL)||(head->next==NULL))return head;
        ListNode *old_cur=head->next->next;
        ListNode *new_pre=head;
        ListNode *new_cur=head->next;
        new_cur->next=NULL;
        while(old_cur){
            new_cur=head->next;
            new_pre=head;
            while((new_cur)&&(new_cur->val>old_cur->val)){
                new_pre=new_cur;
                new_cur=new_cur->next;
            }
            new_pre->next=old_cur;
            new_pre=old_cur;
            old_cur=old_cur->next;
            new_pre->next=new_cur;
        }
        return head;
    }
};

int main(){    
    ListNode* head = NULL;
    insertNode(head,3);
    insertNode(head,2);
    
    Solution s;
    s.insertionSortList(head);
    printList(head);
    
    system("PAUSE");
    return 0;
}
