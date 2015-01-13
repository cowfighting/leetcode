#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if(haystack == NULL || needle == NULL){
        	return -1;
		}
		if(!*needle){
			return 0;
		}
		int i = 0;
		while(haystack[i]){
			int k = i, j = 0;
			while(needle[j++] == haystack[k++]){
				if(!needle[j]){
					return i;
				}
				if(!haystack[k]){
					return -1;
				}
			}
			i++;
		}
		return -1;
    }
};

int main(){
	char haystack[] = {'\0'};
	char needle[] = {'\0'};
	
    Solution sol;
    cout << sol.strStr(haystack, needle) << endl;
    
    system("PAUSE");
    return 0;
}

