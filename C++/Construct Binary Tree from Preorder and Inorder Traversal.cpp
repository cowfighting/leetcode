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
	int preorderCur;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		preorderCur = 0;
		return buildTree(inorder, 0,inorder.size() - 1, preorder);
    }
    
    TreeNode *buildTree(vector<int> &inorder, int inorderStart, int inorderEnd, vector<int> &preorder){
		if(inorderStart > inorderEnd){
			return NULL;
		}
		int val = preorder[preorderCur];
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
        TreeNode* node = new TreeNode(val); 
        ++preorderCur;
		node->left = buildTree(inorder, inorderStart, rootIndex - 1, preorder);
		node->right = buildTree(inorder, rootIndex + 1, inorderEnd, preorder);
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
					cout << cur->val << " ";
					pre->right = cur;
					cur = cur->left;
				} else {
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
	inorder.push_back(2);
	inorder.push_back(3);
	inorder.push_back(4);
		
	vector<int> preorder;
	preorder.push_back(3);
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(4);
		
	Solution s;
	TreeNode* tree = s.buildTree(preorder, inorder);
	s.preOrder(tree);
	cout << endl;
	
	system("PAUSE");
	return 0;
}
