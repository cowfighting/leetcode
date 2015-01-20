#include<iostream>
#include<vector>
using namespace std;
 
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int gasSize = gas.size();
        int costSize = cost.size();
        if(gasSize != costSize || gasSize == 0) {
        	return -1;
		}
		int sumGas = 0, sumCost = 0, tank = 0, start = 0;
		for(int i = 0; i < gasSize; i++) {
			sumGas += gas[i];
			sumCost += cost[i];
			tank += gas[i] - cost[i];
			if(tank < 0) {
				start = i + 1;
				tank = 0;
			}
		}
		if(sumGas < sumCost) {
			return -1;
		} else {
			return start;
		}
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
