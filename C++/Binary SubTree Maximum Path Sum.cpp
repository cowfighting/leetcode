#include<iostream>
#include<vector>
#include<map>
using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*map<TreeNode*, int> cache;
    int maxPathSum(TreeNode* root) {
        if(root == NULL){
            return INT_MIN;
        }
        if(root->left == NULL && root->right == NULL){
            return root->val;
        }
        int leftSum = maxPathSum(root->left);
        int rightSum = maxPathSum(root->right);
        map<TreeNode*, int>::iterator it = cache.find(root);
        int curSum;
        if(it != cache.end()){
            curSum = it->second;
        } else {
            curSum = treeSum(root);
            cache.insert(pair<TreeNode*, int>(root, curSum));
        }
        int tmp = leftSum;
        if(tmp < rightSum ){
            tmp = rightSum;
        }
        if(tmp < curSum ){
            tmp = curSum;
        }
        return tmp;
    }
    
    int treeSum(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return treeSum(root->left) + treeSum(root->right) + root->val;
    }*/
    
    int maxPathSum(TreeNode* root){
        int max = INT_MIN;
        MaxSumOfSubtree(root, max);
        return max;
    }
    void MaxSumOfSubtree(TreeNode* root, int& max){
        if(NULL == root){
            return;
        }
        MaxSumOfSubtree(root->left, max);
        MaxSumOfSubtree(root->right, max);
    	if(NULL != root->left)
        {
            max = Max(root->left->val, max);
            root->val += root->left->val;
	    }
	
	    if(NULL != root->right)
	    {
            max = Max(root->right->val, max);
            root->val += root->right->val;
        }
        max = Max(root->val, max);
    }
    
    int Max(int lhs, int rhs) {
	   return lhs > rhs ? lhs : rhs;
    }
};

int main(){
    TreeNode* root = new TreeNode(18);
    TreeNode* n2 = new TreeNode(-3);
    TreeNode* n3 = new TreeNode(-10);
    TreeNode* n4 = new TreeNode(100);
    root->left = n2;
    root->right = n3;
    n3->left = n4;
    
    /*TreeNode* cur = root;
    int res = 1;
    for(int i = 2; i < 3000; i++){
        res += i;
        TreeNode* node = new TreeNode(i);
        cur->left = node;
        cur = node;
    }
    cout << res << endl;
    */
    Solution s;
    cout << s.maxPathSum(root) << endl;
    system("PAUSE");
    return 0;
}

