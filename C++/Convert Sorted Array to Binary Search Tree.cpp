#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Param{
    int state;
    TreeNode* address;
    Param(TreeNode* node) : address(node), state(1) {}
};

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int size = num.size();
        if(size == 0){
            return NULL;
        }
        return sortedArrayToBST(0, size - 1, num);
    }
    
    TreeNode *sortedArrayToBST(int start, int end, vector<int> &num) {
        if(start > end){
            return NULL;
        }
        int mid = (start + end)/2;
        TreeNode* node = new TreeNode(num[mid]);
        node->left = sortedArrayToBST(start, mid - 1, num);
        node->right = sortedArrayToBST(mid + 1, end, num);
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
                        stk.push(top.address->left);
                    }
                    break;
                case 2:
                    cout << top.address->val << " ";
                    stk.push(top.address->right);
                    break;
            }
        }
        cout << endl;
    }
};

int main(){
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);
    num.push_back(6);
    
    Solution s;
    TreeNode* tree = s.sortedArrayToBST(num);
    s.inOrder(tree); 
    
    system("PAUSE"); 
    return 0;
}
