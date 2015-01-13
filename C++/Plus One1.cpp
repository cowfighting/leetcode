#include<iostream>
#include<vector>
using namespace std; 

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size();
        for(int i = size - 1; i >= 0; i--){
            if(digits[i] == 9){
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

int main(){    
    vector<int> digits;
    digits.push_back(8);
    digits.push_back(9);
    digits.push_back(9);
    
    Solution s;
    vector<int> res = s.plusOne(digits);
    vector<int>::iterator it;
    for(it = res.begin(); it != res.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    system("PAUSE");
    return 0;
}

