#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:

    vector<vector<string>> partition(string s) {
    	vector<vector<string>> ans;
    	int len = s.length();
    	if(len == 0) {
    		return ans;
		}
        vector<string> strs;
        partition(s, 0, len - 1, strs, ans);
        return ans;
    }
    
    void partition(string s, int start, int end, vector<string> strs, vector<vector<string>> &ans) {
    	if(start > end) {
    		ans.push_back(strs);
    		strs.clear();
    		return;
		}
		for(int i = start; i <= end; i++) {
			string sub = s.substr(start, i - start + 1);
			if(isPalindrome(sub)) {
				strs.push_back(sub);
				partition(s, i + 1, end, strs, ans);
				strs.pop_back();
			}
		}
	}
    
    bool isPalindrome(string s) {
    	int len = s.length();
    	int mid = len / 2;
    	for(int i = 0; i <= mid; i++) {
    		if(s[len - 1 - i] != s[i]) {
    			return false;
			}
		}
		return true;
	}
};
 
int main() {
	
	string s = "aaaaaa";
	
	Solution sol;
	vector<vector<string>> ans = sol.partition(s);
	for(int i = 0; i < ans.size(); i++) {
		for(int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	
 	system("PAUSE");
 	return 0;
}
