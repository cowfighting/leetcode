#include<iostream>
using namespace std; 

class Solution {
public:
    int cache[100];
    Solution(){
        memset(cache, -1, sizeof(int)*100);
    }
    int climbStairs(int n) {
        if(n <= 1){
            return 1;
        }
        if(cache[n] > 0){
            return cache[n];
        }
        cache[n] = climbStairs(n-1) + climbStairs(n-2);
        return cache[n];
    }
};

int main(){    
   
    Solution s;
    cout << s.climbStairs(4) << endl;
    system("PAUSE");
    return 0;
}

