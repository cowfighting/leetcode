#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
    	int len = s.length();
    	if(len == 0) {
    		return true;
		}
		if(len == 1) {
    		return false;
		}
        stack<char> stk;
        for(int i = 0; i < len; i++) {
        	if(stk.empty() || s[i] == '{' || s[i] == '(' || s[i] == '[') {
        		stk.push(s[i]);
			} else {
				char top = stk.top();
				stk.pop();
				switch(top) {
					case '{':
						if(s[i] != '}') {
							return false;
						}
						break;
					case '(':
						if(s[i] != ')') {
							return false;
						}
						break;
					case '[':
						if(s[i] != ']') {
							return false;
						}
						break;
				}
			}
		}
		return stk.empty();		
    }
};

int main(){
	string s = "[";
	
    Solution sol;
    cout << sol.isValid(s) << endl;
    
    system("PAUSE");
    return 0;
}

