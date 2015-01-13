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
		
		//next[i]����needle[0...i-1]�к�׺��ǰ׺��ȵ���Ӵ����� 
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
    
    //KMPԤ����ģʽ�������첿��ƥ���
    void preSearch(char *needle, int *next) {
    	//��ʼ��needle��0λ�Ĳ���ƥ���Ϊ-1
		//��ʾ����0λƥ��ʧ�ܣ���ֻ��򵥵Ľ�ƥ�䴮����һλ 
    	next[0] = -1;
    	//��ʾ��1λʱ��needle[0]�ĺ�׺��ǰ׺��ȵ���Ӵ����ȿ϶�Ϊ0 
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

