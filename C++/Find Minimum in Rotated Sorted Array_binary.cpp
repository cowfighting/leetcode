#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int size = num.size();
        int left = 0, right = size - 1;
        
        while(left < right) {
        	int mid = (left + right) / 2;
        	//升序 
	        if(num[left] <= num[right]) {
	        	return num[left];
			}
			//恰为最小值 
			if(num[mid] < num[mid - 1]) {
				return num[mid];
			}
			if(num[mid] >= num[left] && num[mid] > num[right]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return num[left];
    }
};

int main() {
	
	vector<int> num;
	num.push_back(3);
	num.push_back(1);
	num.push_back(2);
	
	Solution sol;
	cout << sol.findMin(num) << endl;
	
	system("PAUSE");
	return 0;
}
