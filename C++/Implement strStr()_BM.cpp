#include<iostream>
#include<cstring>
#include<map>
using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) { 
    	if(haystack == NULL || needle == NULL) {
        	return -1;
		}
		//needle为空串 
		if(!*needle){
			return 0;
		}
		int lenHaystack = strlen(haystack);
		int lenNeedle = strlen(needle);
		if(lenNeedle > lenHaystack) {
			return -1;
		}
		
		//next[i]代表needle[0...i]中后缀和前缀相等的最长子串长度 
		int *next = new int[lenNeedle];
		map<char, int> badChar;
		preSearch(needle, lenNeedle, next, badChar);

		
		delete[] next;
		return -1;
    }
    
    //BM预处理模式串（构造后缀部分匹配表next、坏字符最后出现位置badChar）
    void preSearch(char *needle, int len, int *next, map<char, int> &badChar) {
    	int cur = len - 1;
    	next[cur] = 0;
    	badChar[needle[cur]] = cur;
    	cur--;
    	//从右到左构建坏字符和好后缀 
    	while(cur--) {
    		//依次构建坏字符第一次出现位置 
    		if(badChar.find(needle[cur]) == badChar.end()) { 
    			badChar[needle[cur]] = cur; 
			}
			//依次构建好后缀 
			
		}
    	
	}
};

int main(){
	//char haystack[] = {'m', 'i', 's', 's', 'i', 's', 's', 'i', 'p', 'p', 'i', '\0'};
	//char needle[] = {'i', 's', 's', 'i', 'p', '\0'};
	char haystack[] = {'a', 'b', 'c', ' ', 'a', 'b', 'c', 'd', 'a', 'b', ' ', 'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'a', 'b', 'd', 'e', '\0'};
	char needle[] = {'a','b', 'c', 'd', 'a', 'b', 'd', '\0'};
	
    Solution sol;
    cout << sol.strStr(haystack, needle) << endl;
    
    system("PAUSE");
    return 0;
}

