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

class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
    	vector<int> vec;
    	stack<TreeNode*> stk;
    	if(root != NULL){
			stk.push(root);
		}
		TreeNode* pre = NULL, *cur = root;
    	while(!stk.empty()){
			cur = stk.top();
			if(pre == NULL || pre->left == cur || pre->right == cur){
				vec.push_back(cur->val);
				if(cur->left != NULL){
					stk.push(cur->left);
				} else if(cur->right != NULL){
					stk.push(cur->right);
				} else {
					stk.pop();
				}
			} else if(cur->left == pre){
				if(cur->right != NULL){
					stk.push(cur->right);
				} else {
					stk.pop();
				}
			} else if(cur->right == pre){
				stk.pop();
			}
			pre = cur;
		}
		return vec;
    }
};

int main(){
	TreeNode* tree = new TreeNode(0);
	TreeNode* node1 = new TreeNode(-1);
	TreeNode* node2 = new TreeNode(3);
	TreeNode* node3 = new TreeNode(4);
	tree->left = node1;
	node1->right = node2;
	node1->left = node3;
	
	Solution s;
	vector<int> vec = s.preorderTraversal(tree);
	vector<int>::iterator it;
	for(it = vec.begin(); it != vec.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	
	system("PAUSE");
	return 0;
}
