#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//������ÿ��ȡn���ַ�����1���ַ����бȽϣ�Ч����� 
    string longestCommonPrefix(vector<string> &strs) {
    	int size = strs.size();
    	if(size == 0) {
    		return "";
		}
		if(size == 1) {
			return strs[0];
		}
		
		string prefix = "";
		bool isContinue = true;
		int cur = 0;
		while(isContinue) {
			//ȡÿ���ַ�����curλ���ַ��Ƚ�
			char c = strs[0][cur];
			for(int i = 1; i < size; i++) {
				if(!c || !strs[i][cur] || c != strs[i][cur]) {
					isContinue = false;
					break;
				}
				if(i == size - 1) {
					prefix += c;
				}
			}
			cur++;
		}
		return prefix;
    }
};

int main(){
	string s1 = "";
	string s2 = "";
	
	vector<string> strs;
	strs.push_back(s1);
	strs.push_back(s2);
	
    Solution sol;
    cout << sol.longestCommonPrefix(strs) << endl;
    
    system("PAUSE");
    return 0;
}

