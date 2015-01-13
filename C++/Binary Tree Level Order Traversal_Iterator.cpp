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
	int level;
	int state;
	TreeNode* address;
	Param(int level, TreeNode* node) : level(level), state(1), address(node) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > res;
	    if(root == NULL){
			return res;
		}
		stack<Param> stk;
		stk.push(Param(0, root));
		while(!stk.empty()){
			Param top = stk.top();
			stk.pop();
			switch(top.state){
				case 1:
					if(top.address != NULL){
						if(res.size() == top.level){
							res.push_back(vector<int>());
						}
						res[top.level].push_back(top.address->val);
						top.state = 2;
						stk.push(top);
						stk.push(Param(top.level + 1, top.address->left));
					}
					break;
				case 2:
					stk.push(Param(top.level + 1, top.address->right));
					break;
			}
		} 
		return res;
    }
};

int main(){
	TreeNode* tree = new TreeNode(3);
	TreeNode* node1 = new TreeNode(9);
	TreeNode* node2 = new TreeNode(20);
	TreeNode* node3 = new TreeNode(15);
	TreeNode* node4 = new TreeNode(7);
	tree->left = node1;
	tree->right = node2;
	node2->left = node3;
	node2->right = node4;
	
	Solution s;
	vector<vector<int> > vec =  s.levelOrder(tree);
	vector<vector<int> >::iterator it;
	for(it=vec.begin();it!=vec.end();it++){
		vector<int>::iterator iter;
		for(iter=(*it).begin();iter!=(*it).end();iter++){
			cout << " " << *iter;
		}
		cout << endl;
	}
	
	system("PAUSE");
	return 0;
}
