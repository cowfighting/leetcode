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
    bool isSymmetric(TreeNode *root) {
		if(root == NULL){
			return true;
		}
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* left, TreeNode* right){
		if(left == NULL && right == NULL){
			return true;
		}
		if((left == NULL) ^ (right == NULL)){
			return false;
		}
		if(left != NULL && right != NULL && left->val != right->val){
			return false;
		}
		bool isLeft = isSymmetric(left->left, right->right);
		bool isRight = isSymmetric(left->right, right->left);
		if(!(isLeft && isRight)){
			return false;
		}
		return true;
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
	
	Solution s;
	cout << s.isSymmetric(tree) << endl;
	
	system("PAUSE");
	return 0;
}
