#include<iostream>
using namespace std;


class Solution {
public:
    int search(int A[], int n, int target) {
        int start = 0, end = n - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(A[mid] == target){
                return mid;
            }
            if(isPossible(A, start, mid, target)){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return -1; 
    }
    
    bool isPossible(int A[], int start, int end, int target){
        if(start >= end){
            return false;
        }
        if(A[start] <= target && target <= A[end]){
            return true;
        }
        if(A[start] >= A[end] && (A[start] <= target || target <= A[end])){
            return true;
        }
        return false;
    }
};

int main(){
    int A[] = {5,1,2,3,4};
    Solution s;
    cout<<s.search(A,5,1)<<endl;
    
    system("PAUSE");
    return 0;
}
