#include<iostream>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if(n == 0){
			return;
		}
		int i = m - 1, j = n - 1, k = m + n - 1;
		while(i >= 0 && j >= 0){
            if(A[i] > B[j]){
                A[k--] = A[i--];
            } else {
                A[k--] = B[j--];
            }
        }
        while(j >= 0){
            A[k--] = B[j--];
        }
    }
};

int main(){
	int A[] = {1,2,5,7,9,0,0,0,0,0};
	int B[] = {2,4,6,8,10};
	
	Solution s;
	s.merge(A, 5, B, 5);
	for(int i = 0; i < 10; i++){
		cout << A[i] << " ";
	}
	cout << endl;
	
	system("PAUSE");
	return 0;
}
