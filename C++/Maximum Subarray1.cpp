#include<iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
		if(n <= 0){
			return 0;
		}
		int maxRes = A[0];
		int preMax = A[0]; 
        for(int i = 1; i < n; i++) {
			if(preMax + A[i] > A[i]) {
				preMax += A[i];
			} else {
				preMax = A[i];
			}
			maxRes = max(maxRes, preMax);
		}
		return maxRes;
    }
};

int main() {
	int A[] = {-2,1,-3,4,-1,2,1,-5,4};
	Solution s;
	cout << s.maxSubArray(A, 9) << endl;
	system("PAUSE");
	return 0;
}
