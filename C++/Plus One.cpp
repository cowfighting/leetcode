#include<iostream>
#include<vector>
using namespace std; 

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size();
        int carry = 1;
        for(int i = size - 1; i >= 0; i--){
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if(carry != 0){
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};

int main(){    
    vector<int> digits;
    digits.push_back(9);
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

