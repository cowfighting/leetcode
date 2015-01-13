#include<iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        int num = 0, base = 1;
        while(len--){
            int cur = s[len] - 'A';
            num += base * (cur + 1);
            base *= 26;
        }
        return num;
    }
};

int main(){
    Solution sol;
    cout << sol.titleToNumber("Z")<< endl;
    
    system("PAUSE");
    return 0;
}
