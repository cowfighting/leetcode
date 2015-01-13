#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        if(len == 0 || len == 1){
			return true;
		}
		int start = 0, end = len - 1;
		while(start <= end){
			char charStart = s.at(start);
			char charEnd = s.at(end);
			//ÅÐ¶Ï×Ö·ûÊÇ·ñÕýÈ· 
			if(!isAlphanumeric(charStart)){
				start++;
				continue; 
			}
			if(!isAlphanumeric(charEnd)){
				end--;
				continue; 
			}
			if(isEqual(charStart, charEnd)){
				start++;
				end--;
			}else{
				return false;
			} 
		}
        return true;
    }
    bool isAlphanumeric(char c){
		if(c >= 'A' && c <= 'Z' ){
			return true;
		}
		if(c >= 'a' && c <= 'z' ){
			return true;
		}
		if(c >= '0' && c <= '9' ){
			return true;
		}
		return false;
	}
	
	bool isEqual(char x, char y){
		if(x == y){
			return true;
		}
		if(x - 32 == y){
			return true;
		}
		if(x + 32 == y){
			return true;
		}
		return false;
	}
};

int main(){
	string str = "ab";
    
    Solution s;
    cout<<s.isPalindrome(str)<<endl;
    
    system("PAUSE");
    return 0;
}
