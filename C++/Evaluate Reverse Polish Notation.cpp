#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int size = tokens.size();
        stack<int> stk;
        for(int i = 0; i < size; i++) {
        	string cur = tokens[i];
        	if(cur == "+" || cur == "-" || cur == "*" || cur == "/") {
        		int num1 = stk.top();
        		stk.pop();
        		int num2 = stk.top();
        		stk.pop();
        		int ans;
        		if(cur == "+") {
        			ans = num2 + num1;
				}
				if(cur == "-") {
        			ans = num2 - num1;
				}
				if(cur == "*") {
        			ans = num2 * num1;
				}
				if(cur == "/") {
        			ans = num2 / num1;
				}
        		stk.push(ans);	
        		continue;
			}
			stk.push(strToInt(cur));
		}
		return stk.top();
    }
    
    int strToInt(string s) {
    	int i = 0, ans = 0, sign = 1;
    	if(s[i] == '-') {
    		sign = -1;
    		i++;
		}
    	while(s[i]) {
    		ans = ans * 10 + s[i] - '0';
    		i++;
		}
		return ans * sign;
	}
};

int main() {
	vector<string> tokens;
	tokens.push_back("2");
	tokens.push_back("1");
	tokens.push_back("+");
	tokens.push_back("3");
	tokens.push_back("*");
	
	Solution sol;
	cout << sol.evalRPN(tokens) << endl;
	
	system("PAUSE");
	return 0;
}
