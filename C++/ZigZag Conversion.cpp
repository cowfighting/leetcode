#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        int len = s.length();
        if(len <= nRows || nRows == 1) {
        	return s;	
		}
		//��Z����������֮�����ַ����� 
		int gap = nRows + nRows - 2;
		string ans = ""; 
		for(int i = 0; i < nRows; i++) {
			int j = i;
			//ÿ�����ַ� 
			ans += s[j];
			j += gap;
			while(true) {
				//ÿ�м��֮���ַ��±� 
				int k = j - 2 * i;
				if(k > len - 1) {
					break;
				}
				//��1�к�nRows-2�����⴦����gap֮���һ���ַ�
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

