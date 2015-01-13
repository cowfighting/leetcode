#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    	if(x < 10 && x >= 0) {
        	return true;
		}
		if(x < 0 || x % 10 == 0) {
			return false;
		}
		long long ans = 0;
		long long tmp = x;
		while(x > 0) {
			ans = ans * 10 + (x % 10);
			x /= 10;
		}
		return ans == tmp;
    }
};

int main(){

    Solution sol;
    cout << sol.isPalindrome(0) << endl;
    
    system("PAUSE");
    return 0;
}

