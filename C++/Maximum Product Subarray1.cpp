#include<iostream>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n == 1) {
        	return A[0];
		}
		int curMax = A[0];
		int curMin = A[0];
		int ans = A[0];
		for(int i = 1; i < n; i++) {
			int tmp = curMax;
			curMax = max(A[i], max(tmp * A[i], curMin * A[i]));
			curMin = min(A[i], min(tmp * A[i], curMin * A[i]));
			//更新最大值
			ans = curMax > ans ? curMax : ans;
		}
		return ans;
    }
};

int main() {
	int A[] = {1,-2,3,-4,-3,-4,-3};
	
	Solution sol;
	cout << sol.maxProduct(A, 7) << endl;
	
	system("PAUSE");
	return 0;
}
