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
	TreeNode* leftAddress;
	TreeNode* rightAddress;
	Param(TreeNode* left, TreeNode* right) : state(1), leftAddress(left), rightAddress(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
		if(root == NULL){
			return true;
		}
		stack<Param> stk;
		stk.push(Param(root->left, root->right));
		while(!stk.empty()){
			Param top = stk.top();
			stk.pop();
			TreeNode* left = top.leftAddress;
			TreeNode* right = top.rightAddress;
			switch(top.state){
				case 1:
					if((left == NULL) ^ (right == NULL)){
						return false;
					}
					if(left != NULL && right != NULL && left->val != right->val){
						return false;
					}
					if(left != NULL && right != NULL){
						top.state = 2;
						stk.push(top);
						stk.push(Param(left->left, right->right));
					}
					break;
				case 2:
					stk.push(Param(left->right, right->left));
					break;
			}
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
	node1->left = node3;
	node2->right = node4;
	
	Solution s;
	cout << s.isSymmetric(tree) << endl;
	
	system("PAUSE");
	return 0;
}
