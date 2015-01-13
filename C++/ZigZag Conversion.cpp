#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        int len = s.length();
        if(len <= nRows || nRows == 1) {
        	return s;	
		}
		//“Z”字形竖线之间间隔字符个数 
		int gap = nRows + nRows - 2;
		string ans = ""; 
		for(int i = 0; i < nRows; i++) {
			int j = i;
			//每行首字符 
			ans += s[j];
			j += gap;
			while(true) {
				//每行间隔之间字符下标 
				int k = j - 2 * i;
				if(k > len - 1) {
					break;
				}
				//第1行和nRows-2行特殊处理，因gap之间多一个字符
				if(i > 0 && i < nRows - 1) {
					ans += s[k]; 
				}
				if(j > len - 1) {
					break;
				}
				ans += s[j];
				j += gap;
			}
		}
		return ans;
    }
};

int main(){
	string s = "ABC";
	
    Solution sol;
	cout << sol.convert(s,2) << endl;
    
    system("PAUSE");
    return 0;
}

