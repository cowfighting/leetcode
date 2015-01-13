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
    bool isBalanced(TreeNode *root) {
		if(root == NULL){
			return true;
		}
        bool leftIs = isBalanced(root->left);
        if(!leftIs){
			return false;
		}
        bool rightIs = isBalanced(root->right);
        if(!rightIs){
			return false;
		}
		int leftHeight = height(root->left);
		int rightHeight = height(root->right);
		if(leftHeight - rightHeight > 1 || rightHeight - leftHeight > 1){
			return false;
		}
		return true;
    }
    
    int height(TreeNode *root){
		if(root == NULL){
			return 0;
		}
		int leftHeight = height(root->left) + 1;
		int rightHeight = height(root->right) + 1;
		return (leftHeight > rightHeight) ? leftHeight: rightHeight;
	}
};

int main(){
	TreeNode* tree = new TreeNode(1);
	TreeNode* node1 = new TreeNode(2);
	TreeNode* node2 = new TreeNode(3);
	TreeNode* node3 = new TreeNode(4);
	tree->left = node1;
	node1->left = node2;
	node2->left = node3;
	
	Solution s;
	cout << s.isBalanced(tree) << endl;
	
	system("PAUSE");
	return 0;
}
