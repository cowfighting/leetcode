#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int size = num.size();
        qSort(num, 0, size - 1);
        return num[size / 2];
    }
    
    int qSort(vector<int> &num, int start, int end){
        if(start < end){
            int pivotPos = partition(num, start, end);
            qSort(num, start, pivotPos - 1);
            qSort(num, pivotPos + 1, end);
        }
    }
    
    int partition(vector<int> &num, int start, int end){
        int pivot = num[start];
        int left = start, right = end;
        while(left < right){
            while(left < end && num[left] <= pivot){
                left++;
            }
            while(right > start && num[right] >= pivot){
                right--;
            }
            if(left < right){
                int tmp = num[left];
                num[left] = num[right];
                num[right] = tmp;
            }
        }
        num[start] = num[right];
        num[right] = pivot;
        return right;
    }
    
};

int main(){
    vector<int> num;
    num.push_back(1);
    num.push_back(3);
    num.push_back(2);
    num.push_back(43);
    num.push_back(23);
    num.push_back(31);
    num.push_back(11);
    num.push_back(3);
    
    Solution sol;
    cout << sol.majorityElement(num)<< endl;
    
    system("PAUSE");
    return 0;
}
