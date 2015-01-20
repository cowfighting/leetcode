#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct NewStr {
	//��ԭ�������±� 
	int index;
	//������ַ��� 
	string str; 
	NewStr(int i, string s) : index(i), str(s) {}
};

class Solution {
public:
    string largestNumber(vector<int> &num) {
        int size = num.size();
        if(size == 0) {
        	return "";
		}
		vector<string> strs;
		//��intת��Ϊ�ַ���������������ַ������� 
		int maxLen = 0;
        for(int i = 0; i < size; i++) {
        	string s = to_string(num[i]);
        	maxLen = maxLen < s.length() ? s.length() : maxLen;
        	strs.push_back(s);
		}
		
		//��ÿ���ַ�������Ϊ����ַ������ȣ����Ȳ�����ĩβ�ַ���� 
		vector<NewStr*> newStrs;
		for(int i = 0; i < size; i++) {
        	int len = strs[i].length();
        	string newStr = strs[i];
        	if(len < maxLen) {
        		int diff = maxLen - len;
        		while(diff--) {
        			newStr += (newStr[0] > newStr[len - 1] ? newStr[0] : newStr[len - 1]);
				}
			}
			newStrs.push_back(new NewStr(i, newStr));
		}
		
		radixSort(newStrs, maxLen - 1);

		string ans = "";
		for(int i = 0; i < size; i++) {
			//ȥ��ǰ��0 
			if(ans == "0") {
				ans = "";
			}
			ans += strs[newStrs[i]->index];
		}
		return ans;
    }
    
    //�������򣺴�ĩβ��ʼ�������ַ��Ӵ�С�����ַ��� 
    void radixSort(vector<NewStr*> &newStrs, int cur) {
    	if(cur < 0) {
    		return;
		}
		insertSort(newStrs, cur);
		cur--;
		radixSort(newStrs, cur);
	}
	
	//�������� 
	void insertSort(vector<NewStr*> &newStrs, int cur) {
		int size = newStrs.size();
		for(int i = 0; i < size; i++) {
			NewStr* iStr = newStrs[i];
			for(int j = i - 1; j >= 0; j--) {
				NewStr* jStr = newStrs[j];
				if(iStr->str[cur] > jStr->str[cur]) {
					newStrs[j + 1] = jStr;
					newStrs[j] = iStr;
				} else {
					newStrs[j + 1] = iStr;
					break;
				}
			}
		}
	}
    
};

int main(){
	
	vector<int> num;
	num.push_back(323);
	num.push_back(32);
	
    Solution sol;
    cout << sol.largestNumber(num) << endl;
    
    system("PAUSE");
    return 0;
}

