#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct NewStr {
	//在原数组中下标 
	int index;
	//扩充后字符串 
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
		//将int转换为字符串，并计算最大字符串长度 
		int maxLen = 0;
        for(int i = 0; i < size; i++) {
        	string s = to_string(num[i]);
        	maxLen = maxLen < s.length() ? s.length() : maxLen;
        	strs.push_back(s);
		}
		
		//将每个字符串扩充为最大字符串长度，长度不够以末尾字符填充 
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
			//去掉前导0 
			if(ans == "0") {
				ans = "";
			}
			ans += strs[newStrs[i]->index];
		}
		return ans;
    }
    
    //基数排序：从末尾开始，按照字符从大到小排序字符串 
    void radixSort(vector<NewStr*> &newStrs, int cur) {
    	if(cur < 0) {
    		return;
		}
		insertSort(newStrs, cur);
		cur--;
		radixSort(newStrs, cur);
	}
	
	//插入排序 
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

