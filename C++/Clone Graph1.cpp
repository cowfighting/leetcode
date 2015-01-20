#include<iostream>
#include<vector>
#include<map>
using namespace std;


struct UndirectedGraphNode {
 	int label;
 	vector<UndirectedGraphNode *> neighbors;
 	UndirectedGraphNode(int x) : label(x) {};
 };

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if(node == NULL) {
    		return NULL;
		}
		//记录已访问的label和对应的新node 
		map<int, UndirectedGraphNode*> visited;
		return DFS(node, visited);
    }
    
	UndirectedGraphNode *DFS(UndirectedGraphNode *cur, map<int, UndirectedGraphNode*> &visited) {
		UndirectedGraphNode *newNode = new UndirectedGraphNode(cur->label);
		visited[cur->label] = newNode;
		int size = cur->neighbors.size();
		for(int i = 0; i < size; i++) {
			//已访问
			if(visited.count(cur->neighbors[i]->label) > 0) {
				newNode->neighbors.push_back(visited[cur->neighbors[i]->label]);
			} else {
				newNode->neighbors.push_back(DFS(cur->neighbors[i], visited));
			}
		}
		return newNode;
	}
    
};
 
int main() {
	UndirectedGraphNode *node = new UndirectedGraphNode(0);
	node->neighbors.push_back(node);
	node->neighbors.push_back(node);
	
	Solution sol;
	UndirectedGraphNode *newNode = sol.cloneGraph(node);
	cout << newNode->label << endl;
	
 	system("PAUSE");
 	return 0;
}
