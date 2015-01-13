#include<iostream>
using namespace std; 

class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length() - 1;
        int len2 = b.length() - 1;
        string res;
        int carry = 0, aCur, bCur;
        while(len1 >= 0 || len2 >= 0 || carry != 0){
            aCur = bCur = 0;
            if(len1 >= 0){
                aCur = (a[len1--] == '1');
            }
            if(len2 >= 0){
                bCur = (b[len2--] == '1');
            }
            char sum = aCur ^ bCur ^ carry + '0';
            res = sum + res;
            carry = (aCur + bCur + carry) >> 1;
        }
        return res;
    }
};

int main(){    
    string str1 = "11111";
    string str2 = "1";
    
    Solution s;
    cout << s.addBinary(str1, str2) << endl;
    system("PAUSE");
    return 0;
}

