#include<iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n > 0){
            char c = 'A' + (n - 1) % 26;
            ans = c + ans;
            n = (n - 1) / 26;
        }
        return ans;
    } 
};

int main(){
    Solution sol;
    cout << sol.convertToTitle(26)<< endl;
    
    system("PAUSE");
    return 0;
}
