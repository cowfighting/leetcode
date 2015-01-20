#include<iostream>
#include<vector>
#include<map>
using namespace std;
 
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> ans;
		int size = numbers.size();
    	if(size <= 1) {
    		return ans;
		}
		//记录number[i]所在下标 
		map<int, int> mapIndex;
		for(int i = 0; i < size; i++) {
			int diff = target - numbers[i];
			if(mapIndex.find(diff) != mapIndex.end()) {
				ans.push_back(mapIndex.find(diff)->second + 1);
				ans.push_back(i + 1);
				return ans;
			}
			mapIndex[numbers[i]] = i;
		}
		return ans;
    }
};
 
int main() {
	int num[] = {1,2,10,8,9};
 	vector<int> numbers(num, num + sizeof(num) / sizeof(int));
 	
	Solution sol;
	vector<int> ans = sol.twoSum(numbers, 9);
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	
 	system("PAUSE");
 	return 0;
}
