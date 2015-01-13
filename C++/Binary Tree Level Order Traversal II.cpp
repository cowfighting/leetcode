#include<iostream>
#include<vector>
#include<stack>
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > vec;
		if(root == NULL){
			return vec;
		}
		stack<vector<int> > sta;
		queue<TreeNode* > q;
		q.push(root);
		vector<int> top(1, root->val);
		sta.push(top);
		while(!q.empty()){
            int size = q.size();
    		vector<int> level;
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL){
                    q.push(node->left);
                    level.push_back(node->left->val);
                }
                if(node->right != NULL){
                    q.push(node->right);
                    level.push_back(node->right->val);
                }
            }
            if(!level.empty()){
                sta.push(level);
            }
        }
        while(!sta.empty()){
            vec.push_back(sta.top());
            sta.pop();
        }
        return vec;
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
	vector<vector<int> > vec =  s.levelOrderBottom(tree);
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
