#include<iostream>
using namespace std;
 
class Solution {
public:
    int singleNumber(int A[], int n) {
    	if(n == 0) {
    		return -1;
		}
        int ans = A[0];
        for(int i = 1; i < n; i++) {
        	ans ^= A[i];
		}
		return ans;
    }
};
 
int main() {
 	int A[] = {1,2,3,1,2,3,4};
 	
	Solution sol;
	cout << sol.singleNumber(A, 7) <<endl;
	
 	system("PAUSE");
 	return 0;
}
