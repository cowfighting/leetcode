#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	int len = s.length();
    	if(len == 0) {
    		return 0;
		}
		map<char, int> roman;
		roman['I'] = 1;
		roman['V'] = 5;
		roman['X'] = 10;
		roman['L'] = 50;
		roman['C'] = 100;
		roman['D'] = 500;
		roman['M'] = 1000;
		
		int ans = roman[s[0]];
		for(int i = 1; i < len; i++) {
			if(roman[s[i]] > roman[s[i - 1]]) {
				ans += roman[s[i]] - 2 * roman[s[i - 1]];
			} else {
				ans += roman[s[i]];
			}
		}
		return ans;
    }
};

int main(){
	string str = "MCMLXXVI";
	
    Solution sol;
    cout << sol.romanToInt(str) << endl;
    
    system("PAUSE");
    return 0;
}

