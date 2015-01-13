#include<iostream>
using namespace std; 

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        int init1 = 1, init2 = 2;
        int ans = 0;
        for(int i = 3; i <= n; i++){
            ans = init1 + init2;
            init1 = init2;
            init2 = ans;
        }
        return ans;
    }
};

int main(){    
   
    Solution s;
    cout << s.climbStairs(4) << endl;
    system("PAUSE");
    return 0;
}

