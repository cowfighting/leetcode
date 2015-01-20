#include<iostream>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n == 1) {
        	return A[0];
		}
		//product[i][0]保存当前最大值，product[i][1]保存当前最小值 
		//ans保存结果最大值 
		int product[n][2], ans;
		product[0][0] = A[0];
		product[0][1] = A[0];
		ans = A[0];
		for(int i = 1; i < n; i++) {
			product[i][0] = max(A[i], max(product[i - 1][0] * A[i], product[i - 1][1] * A[i]));
			product[i][1] = min(A[i], min(product[i - 1][0] * A[i], product[i - 1][1] * A[i]));
			//更新最大值
			ans = product[i][0] > ans ? product[i][0] : ans;
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
