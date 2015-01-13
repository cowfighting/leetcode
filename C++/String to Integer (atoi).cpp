#include<iostream>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
    	//�մ� 
    	if(!*str) {
    		return 0; 
		}
		int start = 0;
		//�����ַ�����ʼ�ո� 
		while(str[start] == ' ') {
			start++;
		}
		//���������ж� 
		int sign = 1;
		if(str[start] == '-') {
			sign = -1;
			start++; 
		} else if (str[start] == '+') {
			start++; 
		}
		int ans = 0;
		while(str[start] <= '9' && str[start] >= '0') {
			int num =  str[start] - '0';
			//�ж��Ƿ�Խ�� 
			if(ans >= (INT_MAX / 10) && num >= 8 || ans > (INT_MAX / 10)) {
				if(sign == 1) {
					return INT_MAX;	
				} else {
					return INT_MIN;
				}
			}
			ans = ans * 10 + num;
			start++;
		}
		return ans * sign;
    }
};

int main(){
	
	char str[] = {'-', '1', '1', '9', '1', '9', '7', '3', '0', '3', '5', '6', 'x', '\0'};

    Solution sol;
    
	cout << sol.atoi(str) << endl;
    
    system("PAUSE");
    return 0;
}

