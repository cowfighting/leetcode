#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) { 
    	if(haystack == NULL || needle == NULL) {
        	return -1;
		}
		//needleΪ�մ� 
		if(!*needle){
			return 0;
		}
		int lenHaystack = strlen(haystack);
		int lenNeedle = strlen(needle);
		if(lenNeedle > lenHaystack) {
			return -1;
		}
		
		//next[i]����needle[0...i]�к�׺��ǰ׺��ȵ���Ӵ����� 
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
			if(index > 0) {
				cur = cur + index - next[index - 1];
				index = next[index - 1];
			} else {
				cur++;
				index = 0;
			}
		}
		
		delete[] next;
		return -1;
    }
    
    //KMPԤ����ģʽ�������첿��ƥ���
    void preSearch(char *needle, int *next) {
    	//��ʼ��needle��0λ�Ĳ���ƥ���Ϊ0
    	next[0] = 0;
    	int cur = 1;
    	while(needle[cur]) {
    		if(needle[cur] == needle[next[cur - 1]]) {
    			next[cur] = next[cur - 1] + 1;
			} else {
				next[cur] = 0;
			}
			cur++;
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

