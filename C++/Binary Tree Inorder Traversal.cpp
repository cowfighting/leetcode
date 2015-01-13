#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> vec;
    vector<int> inorderTraversal(TreeNode *root) {
        if(root != NULL){
            inorderTraversal(root->left);
            vec.push_back(root->val);
            inorderTraversal(root->right);
        }
        return vec;
    }
};

int main(){
    TreeNode* root = new TreeNode(10);
    TreeNode* n1 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(15);
    TreeNode* n3 = new TreeNode(6);
    TreeNode* n4 = new TreeNode(20);
    
    root->left = n1;

    Solution s;
    vector<int> res = s.inorderTraversal(root);
    vector<int>::iterator it;
    for(it = res.begin(); it != res.end(); it++){
        cout<<*it<<endl;        
    }    
    system("PAUSE"); 
    return 0;
}
