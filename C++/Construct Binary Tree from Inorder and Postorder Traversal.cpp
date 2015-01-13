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
	//当前根节点下标 
	int postorderCur;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		postorderCur = postorder.size() - 1;
		return buildTree(inorder, 0 ,inorder.size() - 1, postorder);
    }
    
    TreeNode *buildTree(vector<int> &inorder, int inorderStart, int inorderEnd, vector<int> &postorder){
		if(inorderStart > inorderEnd){
			return NULL;
		}
		int val = postorder[postorderCur];
		int rootIndex = -1;
		for(int i = inorderStart; i <= inorderEnd; i++){
			if(inorder[i] == val){
				rootIndex = i;
				break;
			}
		}
		if(rootIndex == -1){
			return NULL;
		}
		--postorderCur;
        TreeNode* node = new TreeNode(val); 
		node->right = buildTree(inorder, rootIndex + 1, inorderEnd, postorder);
		node->left = buildTree(inorder, inorderStart, rootIndex - 1, postorder);
		return node;
	}
    
    void preOrder(TreeNode* root){
		TreeNode* cur = root;
		while(cur){
			if(cur->left == NULL){
				cout << cur->val << " ";
				cur = cur->right;
			} else {
				TreeNode* pre = cur->left;
				while(pre->right != NULL && pre->right != cur){
					pre = pre->right;
				}
				if(pre->right == NULL){	
					pre->right = cur;
					cur = cur->left;
				} else {
					cout << cur->val << " ";
					pre->right = NULL;
					cur = cur->right;
				}
			}
		}
	}
};

int main(){
	vector<int> inorder;
	inorder.push_back(1);
	inorder.push_back(3);
	inorder.push_back(2);
		
	vector<int> postorder;
	postorder.push_back(3);
	postorder.push_back(2);
	postorder.push_back(1);
	
	Solution s;
	TreeNode* tree = s.buildTree(inorder, postorder);
	s.preOrder(tree);
	cout << endl;
	
	system("PAUSE");
	return 0;
}
