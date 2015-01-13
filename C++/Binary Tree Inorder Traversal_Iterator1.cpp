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

struct Param {
	int state;
	TreeNode* address;
	Param(TreeNode* node) : address(node), state(1) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
    	vector<int> vec;
		stack<Param> stk;
    	stk.push(Param(root));
    	while(!stk.empty()){
			Param top = stk.top();
			stk.pop();
			switch(top.state){
				case 1:
					if(top.address != NULL){
						top.state = 2;
						stk.push(top);
						stk.push(Param(top.address->left));
					}
					break;
				case 2:
					vec.push_back(top.address->val);
					stk.push(Param(top.address->right));
					break;
			}
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
	node1->left = node2;
	node2->right = node3;
	
	Solution s;
	vector<int> vec = s.inorderTraversal(tree);
	vector<int>::iterator it;
	for(it = vec.begin(); it != vec.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	
	system("PAUSE");
	return 0;
}
