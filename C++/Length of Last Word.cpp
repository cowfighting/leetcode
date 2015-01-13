#include<iostream>
using namespace std; 

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        /*if(s == NULL){
			return 0;
		}
		int i = 0;
		int len = 0;
        while(s[i] != '\0'){
			while(s[i] == ' '){
                i++;
            }
            if(s[i] == '\0' ){
                break;
            }
            if(s[i-1] == ' ' && s[i] != '\0'){
                len = 0;
            }
            if(s[i] != '\0'){
                len++;   
            }
			i++;
		}
		return len;*/
        
        int len = 0;
        while(*s){
            if(*s != ' '){
                len++;
            } else if(*(s+1) && *(s+1) != ' '){
                len = 0;
            }
            s++;
        }
        return len;
    }
};

int main(){    
    char* str = "ba   ";
    
    Solution s;
    cout << s.lengthOfLastWord(str) << endl;
    
    system("PAUSE");
    return 0;
}

