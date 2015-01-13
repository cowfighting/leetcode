#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    stack<TreeNode*> stk;
public:
    BSTIterator(TreeNode *root) {
        setStack(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return stk.size() > 0;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* top = stk.top();
        stk.pop();
        setStack(top->right);
        return top->val;
    }
    
    void setStack(TreeNode* node){
        while(node){
            stk.push(node);
            node = node->left;
        }
    }
};

int main(){
    TreeNode* root = new TreeNode(2);
    
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(3); 
     
    root->left = node1;
    root->right = node2;
    node2->left = node3;
    
    
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) 
        cout << i.next() << " ";
    cout << endl;
    system("PAUSE");
    return 0;
}
