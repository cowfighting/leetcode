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
	//记录已访问的label和对应的新node 
	map<int, UndirectedGraphNode*> visited;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	visited.clear();
    	if(node == NULL) {
    		return NULL;
		}
		UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
		DFS(node, newNode);
		return newNode;
    }
    
	void DFS(UndirectedGraphNode *cur, UndirectedGraphNode *&newNode) {
		visited[cur->label] = newNode;
		int size = cur->neighbors.size();
		vector<UndirectedGraphNode *> newNeighbors;
		for(int i = 0; i < size; i++) {
			map<int, UndirectedGraphNode*>::iterator it = visited.find(cur->neighbors[i]->label);
			//已访问
			if(it != visited.end()) {
				newNeighbors.push_back(it->second);
			} else {
				UndirectedGraphNode *node = new UndirectedGraphNode(cur->neighbors[i]->label);
				newNeighbors.push_back(node);
				DFS(cur->neighbors[i], node);
			}
		}
		newNode->neighbors = newNeighbors;
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
