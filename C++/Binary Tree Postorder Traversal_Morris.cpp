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
	//Morris Postorder Traversal
	vector<int> postorderTraversal(TreeNode *root) {
		TreeNode dummy(0);
		dummy.left = root;
		
    	vector<int> vec;
    	TreeNode* cur = &dummy;
    	while(cur){
			if(!cur->left){
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
					addReverse(vec, cur->left, sub);					
					sub->right = NULL;
					cur = cur->right;
				}
			}
		}
		return vec;
    }
    
    void reverse(TreeNode* first, TreeNode* last){
		if(first == last){
			return;
		}
		TreeNode* cur = first->right, *pre = first;
		while(cur != last){
			TreeNode* tmp = cur->right;
			cur->right = pre;
			pre = cur;
			cur = tmp;
		}
		cur->right = pre;
	}
	
	void addReverse(vector<int>& vec, TreeNode* first, TreeNode* last){
		reverse(first, last);
		
		TreeNode* cur = last;
		while(cur != first){
			vec.push_back(cur->val);
			cur = cur->right;
		}
		vec.push_back(cur->val);
		
		reverse(last, first);
	}

};

int main(){
	TreeNode* tree = new TreeNode(1);
	TreeNode* node1 = new TreeNode(2);
	TreeNode* node2 = new TreeNode(3);
	TreeNode* node3 = new TreeNode(4);
	tree->right = node1;
	//node1->right = node2;
	//node1->left = node3;
	
	Solution s;
	vector<int> vec = s.postorderTraversal(tree);
	vector<int>::iterator it;
	for(it = vec.begin(); it != vec.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	
	system("PAUSE");
	return 0;
}
