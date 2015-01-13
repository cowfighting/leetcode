#include<iostream>
#include<stack>
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
 struct Param{
    int state;
    TreeNode* address;
    Param(TreeNode* node) : state(1), address(node){}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* fast = head, *slow = head, *pre = NULL;
        while(fast->next != NULL && fast->next->next != NULL){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //×ó±ßÁ´±í 
        ListNode* left = NULL;
        if(pre != NULL){
            left = head;
            pre->next = NULL;
        }
        //ÓÒ±ßÁ´±í 
        ListNode* right = slow->next;
        TreeNode* node = new TreeNode(slow->val);
        node->left = sortedListToBST(left);
        node->right = sortedListToBST(right);
        return node;
    }
    
    void inOrder(TreeNode* tree){
        if(tree == NULL){
            return;
        }
        stack<Param> stk;
        stk.push(Param(tree));
        while(!stk.empty()){
            Param top = stk.top();
            stk.pop();
            switch(top.state){
                case 1:
                    if(top.address != NULL){
                        top.state = 2;
                        stk.push(top);
                        stk.push(Param(top.address->left));
                    }
                    break;
                case 2:
                    cout << top.address->val << " ";
                    top.state = 3;
                    stk.push(top);
                    stk.push(Param(top.address->right));
                    break;
                case 3:
                    break;
            }
        }
        cout << endl;       
    }
};

int main(){    
    ListNode* head = new ListNode(-10);
    ListNode* node1 = new ListNode(-3);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(5);
    ListNode* node4 = new ListNode(9);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    Solution s;
    s.inOrder(s.sortedListToBST(head));
    system("PAUSE");
    return 0;
}

