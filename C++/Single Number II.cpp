#include<iostream>
using namespace std;
 
class Solution {
public:
    int singleNumber(int A[], int n) {
//    	int once = 0, twice = 0, commonMask;
//    	for(int i = 0; i < n; i++) {
//    		twice |= once & A[i];
//    		once ^= A[i];
//			commonMask = once ^ twice;
//    		once &= commonMask;
//    		twice &= commonMask;
//		}
//		return once;
        
		return singleNumber(A, n, 3, 2);
    }
    
    int singleNumber(int A[], int n, int k, int l) {
        if (n <= 0) return 0;
        int t;
        int* x = new int[k];
        for(int i = 0; i < k; i++) {
        	x[i] = 0;
		}
        x[0] = ~0;
        for (int i = 0; i < n; i++) {
            t = x[k-1];
            for (int j = k-1; j > 0; j--) {
                x[j] = (x[j-1] & A[i]) | (x[j] & ~A[i]);
            }
            x[0] = (t & A[i]) | (x[0] & ~A[i]);
        }
        return x[l];
    }

};
 
int main() {
 	int A[] = {2,2,2,6,6};
 	
	Solution sol;
	cout << sol.singleNumber(A, 5) <<endl;
	
 	system("PAUSE");
 	return 0;
}
