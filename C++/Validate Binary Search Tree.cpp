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
    bool isValidBST(TreeNode *root) {
        if(root == NULL){
            return true;
        }
        if(root->left != NULL && root->val <= root->left->val){
            return false;
        }
        if(root->right != NULL && root->val >= root->right->val){
            return false;
        }
        bool leftIs = isValidBST(root->left);
        bool rightIs = isValidBST(root->right);
        if(!leftIs || !rightIs){
            return false;
        }
        TreeNode* pre = inOrderPre(root);
        TreeNode* suc = inOrderSuccessor(root);
        if(pre != NULL && root->val <= pre->val){
            return false;
        }
        if(suc != NULL && root->val >= suc->val){
            return false;
        }
        return true;
    }
    //寻找节点node的中序遍历直接后继
    TreeNode* inOrderSuccessor(TreeNode* node){
        if(node->right == NULL){
            return NULL;
        }else{
            TreeNode* cur = node->right;
            while(cur->left != NULL){
                cur = cur->left;
            }
            return cur;
        }
    } 
    //寻找节点node的中序遍历直接前驱
    TreeNode* inOrderPre(TreeNode* node){
        if(node->left == NULL){
            return NULL;
        }else{
            TreeNode* cur = node->left;
            while(cur->right != NULL){
                cur = cur->right;
            }
            return cur;
        }
    }
};

int main(){
    TreeNode* root = new TreeNode(10);
    TreeNode* n1 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(15);
    TreeNode* n3 = new TreeNode(6);
    TreeNode* n4 = new TreeNode(20);
    
    root->left = n1;
    root->right = n2;
    n2->left = n3;
    n2->right = n4;

    Solution s;
    cout<<s.isValidBST(root)<<endl;
    
    system("PAUSE"); 
    return 0;
}
