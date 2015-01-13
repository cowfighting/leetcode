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
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1 , n);
    }
    
    vector<TreeNode *> generateTrees(int start, int end){
        vector<TreeNode*> vec;
        if(start == end){
            vec.push_back(new TreeNode(start));
            return vec;
        }
        if(end < start){
            vec.push_back(NULL);
            return vec;
        }
        for(int i = start; i <= end; i++){
            vector<TreeNode*> left = generateTrees(start, i - 1);
            vector<TreeNode*> right = generateTrees(i + 1, end);
            vector<TreeNode*>::iterator itLeft;
            vector<TreeNode*>::iterator itRight;
            for(itLeft = left.begin(); itLeft != left.end(); itLeft++){
                for(itRight = right.begin(); itRight != right.end(); itRight++){
                    //每次需新建此树根节点（防止后面的覆盖前面） 
                    TreeNode* node = new TreeNode(i);
                    node->left = *itLeft;
                    node->right = *itRight;
                    vec.push_back(node);
                }
            }
        }
        return vec;
    }
};

void levelOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* top = q.front();
        q.pop();
        if(top != NULL){
            cout << top->val << " ";
            q.push(top->left);
            q.push(top->right);
        } else {
            cout << "# ";
        }
    }
    cout<<endl;
}

int main(){
    /*TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    n1->left = n2;
    n1->right = n3;
    levelOrder(n1);*/

    Solution s;
    vector<TreeNode*> res = s.generateTrees(3);
    vector<TreeNode*>::iterator it;
    for(it = res.begin(); it != res.end(); it++){
        levelOrder(*it);
    }
    system("PAUSE");
    return 0;
}

