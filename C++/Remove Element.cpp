#include<iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
    	if(n <= 0) {
			return 0;
		}
		int count = 0;
		for(int i = 0; i < n; i++) {
			if(A[i] == elem) {
				continue;
			}
			A[count++] = A[i];
		}
		return count;
    }
};

int main(){
	int A[] = {4, 4, 4, 4, 4};
	
    Solution sol;
    cout << sol.removeElement(A, 5, 4) << endl;
    
    system("PAUSE");
    return 0;
}

