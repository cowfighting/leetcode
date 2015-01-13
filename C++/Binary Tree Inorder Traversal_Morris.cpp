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
	//Morris Inorder Traversal
	vector<int> inorderTraversal(TreeNode *root) {
    	vector<int> vec;
    	TreeNode* cur = root;
    	while(cur){
			if(!cur->left){
				vec.push_back(cur->val);
				cur = cur->right;
			}else{
		    	TreeNode* sub = cur->left;
		    	// 寻找cur节点左子树的最右节点 （即当前节点的中序前驱） 
				while(sub->right && sub->right != cur){
					sub = sub->right;
				}
				// 第一次找最右节点 
				if(!sub->right){
					sub->right = cur;
					cur = cur->left;
				}else{//第二次 
					vec.push_back(cur->val);
					sub->right = NULL;
					cur = cur->right;
				}
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
