#include<iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int len = s.length();
        string ans = "";
        for(int i = len - 1; i >= 0; i--) {
        	string word = "";
        	while(s[i] != ' ' && i >= 0) {
        		word = s[i] + word;
        		i--;
			}
			if(ans != "" && word != "") {
				ans += " ";
			}
			ans += word;
		}
		s = ans;
    }
};

int main() {
	
	string s = "    a b  ";
	
	Solution sol;
	sol.reverseWords(s);
	
	cout << s << endl; 
	
	system("PAUSE");
	return 0;
}
