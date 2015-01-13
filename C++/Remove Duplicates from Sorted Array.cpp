#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 0) {
        	return 0;
		}
		if(n == 1) {
			return 1;
		}
		int count = 1;
		for(int i = 1; i < n; i++) {
			if(A[i] == A[count - 1]) {
				continue;
			} else {
				A[count++] = A[i];
			}
		}
		return count;
    }
};

int main(){
	int A[] = {3, 4, 4, 4, 5};
	
    Solution sol;
    int count = sol.removeDuplicates(A, 5);
    cout << count << endl;
    
    for(int i = 0; i < count; i++){
    	cout << A[i] << " ";
	}
    cout << endl;
    
    system("PAUSE");
    return 0;
}

