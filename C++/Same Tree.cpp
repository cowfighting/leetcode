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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL && q == NULL){
			return true;
		}
		if((p == NULL ^ q == NULL) || (p->val != q->val)){
			return false;
		}
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(){
	TreeNode* tree = new TreeNode(1);
	TreeNode* node1 = new TreeNode(2);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(3);
	tree->left = node1;
	tree->right = node2;
	node1->right = node3;
	node2->right = node4;
	
	TreeNode* tree1 = new TreeNode(1);
	TreeNode* node5 = new TreeNode(2);
	TreeNode* node6 = new TreeNode(2);
	TreeNode* node7 = new TreeNode(3);
	TreeNode* node8 = new TreeNode(3);
	tree1->left = node5;
	tree1->right = node6;
	node5->right = node7;
	node6->right = node8;
	
	
	Solution s;
	cout << s.isSameTree(tree, tree1) << endl;
	
	system("PAUSE");
	return 0;
}
