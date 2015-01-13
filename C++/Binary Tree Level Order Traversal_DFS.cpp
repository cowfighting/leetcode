#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int> > res;
    vector<vector<int> > levelOrder(TreeNode *root) {
	    DFS(root, 0);
		return res;
    }
    
    void DFS(TreeNode* root, int level){
		if(root == NULL){
			return;
		}
		//表示当前层还没创建vector 
		if(res.size() == level){
			res.push_back(vector<int>());
		}
		res[level].push_back(root->val);
		DFS(root->left, level + 1);
		DFS(root->right, level + 1);
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
