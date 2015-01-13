#include<iostream>
using namespace std; 

class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length() - 1;
        int len2 = b.length() - 1;
        string c = a;
        int len = len1;
        if(len1 < len2){
            c = b;
            len = len2;
        }
        int carry = 0;
        while(len1 >= 0 && len2 >= 0){
            int sum = a[len1--] - '0' + b[len2--] - '0' + carry;
            c[len--] =  sum % 2 + '0';
            carry = sum / 2;
        }
        while(len >= 0){
            char sum = c[len] - '0' + carry;
            c[len] = sum % 2 + '0';
            carry = sum / 2;
            len--;
        }
        if(carry != 0){
            return "1" + c;
        }
        return c;
    }
};

int main(){    
    string str1 = "0";
    string str2 = "0";
    
    Solution s;
    cout << s.addBinary(str1, str2) << endl;
    system("PAUSE");
    return 0;
}

