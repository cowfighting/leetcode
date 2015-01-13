#include<iostream>
#include<cstring>
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
		
		//next[i]代表needle[0...i-1]中后缀和前缀相等的最长子串长度 
		int *next = new int[lenNeedle];
		preSearch(needle, next);
		
		int cur = 0, index = 0;
		while(haystack[cur]) {
			while(needle[index] == haystack[cur + index]) {
				index++;
				if(!needle[index]) {
					return cur;
				}
				if(!haystack[cur + index]){
					return -1;
				}
			}
			cur = cur + index - next[index];
			index = index == 0 ? 0 : next[index];
		}
		
		delete[] next;
		return -1;
    }
    
    //KMP预处理模式串（构造部分匹配表）
    void preSearch(char *needle, int *next) {
    	//初始化needle第0位的部分匹配表为-1
		//表示如在0位匹配失败，则只需简单的将匹配串后移一位 
    	next[0] = -1;
    	//表示第1位时，needle[0]的后缀和前缀相等的最长子串长度肯定为0 
    	next[1] = 0;
    	int cur = 2;
    	while(needle[cur]) {
    		if(needle[cur - 1] == needle[next[cur - 1]]) {
    			next[cur] = next[cur - 1] + 1;
			} else {
				next[cur] = 0;
			}
			cur++;
		}
	}
};

int main(){
	char haystack[] = {'a', 'b', 'c', ' ', 'a', 'b', 'c', 'd', 'a', 'b', ' ', 'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'a', 'b', 'd', 'e', '\0'};
	char needle[] = {'a','b', 'c', 'd', 'a', 'b', 'd', '\0'};
	
    Solution sol;
    cout << sol.strStr(haystack, needle) << endl;
    
    system("PAUSE");
    return 0;
}

