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
		map<char, int> badChar;
		preSearch(needle, lenNeedle, next, badChar);

		
		delete[] next;
		return -1;
    }
    
    //BMԤ����ģʽ���������׺����ƥ���next�����ַ�������λ��badChar��
    void preSearch(char *needle, int len, int *next, map<char, int> &badChar) {
    	int cur = len - 1;
    	next[cur] = 0;
    	badChar[needle[cur]] = cur;
    	cur--;
    	//���ҵ��󹹽����ַ��ͺú�׺ 
    	while(cur--) {
    		//���ι������ַ���һ�γ���λ�� 
    		if(badChar.find(needle[cur]) == badChar.end()) { 
    			badChar[needle[cur]] = cur; 
			}
			//���ι����ú�׺ 
			
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

