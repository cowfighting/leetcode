#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int size = num.size();
        if(size == 0){
            return -1;
        }
        if(size == 1){
            return 0;
        }
        int left = 0, right = size - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(mid == 0){
                if(num[mid] > num[mid + 1]){
                    return mid;
                } else {
                    left = mid + 1;
                }
            } else if(mid == size - 1){
                if(num[mid] > num[mid - 1]){
                    return mid;
                } else {
                    right = mid - 1;
                }
            } else {
                if(num[mid] > num[mid - 1] && num[mid] > num[mid + 1]){
                    return mid;
                } else if (num[mid] > num[mid - 1]){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<int> num;
    num.push_back(3);
    num.push_back(2);
    num.push_back(1);
    //num.push_back(1);
    
    Solution s;
    cout << s.findPeakElement(num) << endl;
    
    system("PAUSE");
    return 0;
}
