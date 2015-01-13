#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL){
            return false;
        }
        sum -= root->val;
        //如果为叶子节点 
        if(root->left == NULL && root->right == NULL){
            return sum == 0;
        }
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};

int main(){
    TreeNode* root = new TreeNode(5);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n8 = new TreeNode(8);
    TreeNode* n11 = new TreeNode(11);
    TreeNode* n13 = new TreeNode(13);
    TreeNode* n4a = new TreeNode(4);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n1 = new TreeNode(1);
    
    root->left = n4;
    root->right = n8;
    n4->left = n11;
    n8->left = n13;
    n8->right = n4a;
    //n11->left = n7;
    n11->right = n2;
    n4a->right = n1;

    Solution s;
    cout<<s.hasPathSum(root,22)<<endl;
    
    system("PAUSE"); 
    return 0;
}
