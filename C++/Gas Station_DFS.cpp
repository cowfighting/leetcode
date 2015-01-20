#include<iostream>
#include<vector>
using namespace std;
 
class Solution {
public:
	//注意：本题DFS方法不适用，会造成TLE 
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int gasSize = gas.size();
        int costSize = cost.size();
        if(gasSize != costSize || gasSize == 0) {
        	return -1;
		}
		//记录节点是否访问 
		bool* visited = new bool[gasSize];
		//依次判定起始站点 
		for(int i = 0; i < gasSize; i++) {
			initVisited(visited, gasSize);
			visited[i] = true;
			if(DFS(gas, cost, visited, i, i, 1, gas[i])) {
				return i;
			}
		}
		delete[] visited;
		return -1;
    }
    
    void initVisited(bool *visited, int gasSize) {
    	for(int i = 0; i < gasSize; i++) {
			visited[i] = false;
		}
	}
    
    //深度搜索，start起始节点，cur当前访问节点，visitedCount已访问节点数，curGas当前剩余 
    bool DFS(vector<int> &gas, vector<int> &cost, bool *visited, int start, int cur, int visitedCount, int curGas) {
    	int gasSize = gas.size();
    	if(visitedCount == gasSize) {
    		//最后能否回到起始点 
    		if(curGas - cost[cur] >= 0) {
    			return true; 
			} else {
				return false;
			}
		}
    	for(int i = 0; i < gasSize; i++) {
    		if(!visited[i] && (curGas - cost[cur] >= 0)) {
    			visited[i] = true;
    			visitedCount++;
    			if (DFS(gas, cost, visited, start, i, visitedCount, curGas - cost[cur] + gas[i])) {
    				return true;
				}
				visited[i] = false;
    			visitedCount--;
			}
		}
		return false;
	}
    
};
 
int main() {
 	vector<int> gas;
 	gas.push_back(5);
 	
 	vector<int> cost;
 	cost.push_back(4);
 	
	Solution sol;
	cout << sol.canCompleteCircuit(gas, cost) << endl;
	
 	system("PAUSE");
 	return 0;
}
