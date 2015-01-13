#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//һ�����ַ����Ƚϣ�����ֻ�������ַ�����ͬ�����˷ѽ϶�ʱ�䣩 
    string longestCommonPrefix(vector<string> &strs) {
    	int size = strs.size();
    	if(size == 0) {
    		return "";
		}
		if(size == 1) {
			return strs[0];
		}
        vector<string>::iterator it =  strs.begin();
        string prefix = *it;
        it++;
        while(it != strs.end()) {
        	string cur = *it;
        	int pos = 0;
        	while(prefix[pos] == cur[pos]) {
        		pos++;
			}
			prefix = prefix.substr(0, pos);
        	it++;
		}
		return prefix;
    }
};

int main(){
	string s1 = "abcd";
	string s2 = "";
	
	vector<string> strs;
	strs.push_back(s1);
	strs.push_back(s2);
	
    Solution sol;
    cout << sol.longestCommonPrefix(strs) << endl;
    
    system("PAUSE");
    return 0;
}

