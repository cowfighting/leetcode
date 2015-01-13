#include<iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
		if(n <= 0){
			return 0;
		}
		//curMax保存以A[i]结尾的当前最大值 
		int* curMax = new int[n];
		for(int i = 0; i < n; i++){
			curMax[i] = A[i];
		}
		int maxRes = curMax[0];
        for(int i = 1; i < n; i++){
			if(curMax[i - 1] + A[i] > curMax[i]) {
				curMax[i] = curMax[i - 1] + A[i];
			}
			maxRes = max(maxRes, curMax[i]);
		}
		delete[] curMax;
		return maxRes;
    }
};

int main() {
	int A[] = {-2,1};
	Solution s;
	cout << s.maxSubArray(A, 2) << endl;
	system("PAUSE");
	return 0;
}
