#include<iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
		if(n <= 0){
			return 0;
		}
		if(n == 1){
			return A[0];
		}
		int curMax = 0;
		int maxRes = 0;
        for(int i = 0; i < n; i++) {
			curMax += A[i];
			if(curMax < 0){
				curMax = 0;
			}
			if(curMax > maxRes){
				maxRes = curMax;
			}
		}
		return maxRes;
    }
};

int main() {
	int A[] = {-2, 2, 3, 4, 5};
	Solution s;
	cout << s.maxSubArray(A, 5) << endl;
	system("PAUSE");
	return 0;
}
