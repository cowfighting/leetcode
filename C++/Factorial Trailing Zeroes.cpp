#include<iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        while(n / 5 > 0){
            sum += n / 5;
            n /= 5;
        }
        return sum;
    }
};

int main(){
    
    Solution sol;
    cout << sol.trailingZeroes(4617) << endl;
    
    system("PAUSE");
    return 0;
}
