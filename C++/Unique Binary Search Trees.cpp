#include<iostream>
using namespace std; 

class Solution {
public:
    int cache[100];
    Solution(){
        memset(cache, 0 ,sizeof(int)*100);
    }
    int numTrees(int n) {
        /*
        if(n <= 1){
            return 1;
        }
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += numTrees(i - 1) * numTrees(n - i);
        }
        return sum;
        */
        
        /*
        if(n <= 1){
            return 1;
        }
        int sum = 0;
        for(int i = 1; i <= n/2; i++){
            sum += numTrees(i - 1) * numTrees(n - i);
        }
        sum = sum << 1;
        if( n & 1){
            sum += numTrees(n/2) * numTrees(n/2);
        }
        return sum;
        */
        
        /*
        if(cache[n] > 0){
            return cache[n];
        }
        if(n <= 1){
            cache[n] = 1;
            return 1;
        }
        for(int i = 1; i <= n/2; i++){
            int& a = cache[i - 1];
            int& b = cache[n - i];
            if(a <= 0){
                a = numTrees(i - 1);
            }
            if(b <= 0){
                b = numTrees(n - i);
            }
            cache[n] += a * b;
        }
        cache[n] = cache[n] << 1;
        if( n & 1){
            if(cache[n/2] <= 0){
                cache[n] += cache[n/2] * cache[n/2];
            } else {
                int res = numTrees(n/2);
                cache[n] += res * res;
            }
        }
        return cache[n];
        */
        
        if(n <= 1){
            return 1;
        }
        if(cache[n] > 0){
            return cache[n];
        }
        int sum = 0;
        for(int i = 1; i <= n/2; i++){
            sum += numTrees(i - 1) * numTrees(n - i);
        }
        sum = sum << 1;
        if( n & 1){
            sum += numTrees(n/2) * numTrees(n/2);
        }
        cache[n] = sum;
        return sum;
    }
};

int main(){    
    Solution s;
    cout << s.numTrees(10) << endl;
    
    system("PAUSE");
    return 0;
}

