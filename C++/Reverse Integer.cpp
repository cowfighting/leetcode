#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
    	//·ûºÅ 
    	int sign = x > 0 ? 1 : -1;
    	//È¡¾ø¶ÔÖµ 
    	x = x > 0 ? x : -x;
        if(x >= 0 && x <= 9) {
        	return x * sign;
		}
		int ans = 0;
		while(x > 0) {
			if(ans > INT_MAX / 10 || (ans == INT_MAX && x >= 8)) {
				return 0;
			}
			ans = ans * 10 + x % 10;
			x /= 10;
		}
		return ans * sign;
    }
};

int main(){
	
    Solution sol;
    
	cout << sol.reverse(-12300) << endl;
    
    system("PAUSE");
    return 0;
}

