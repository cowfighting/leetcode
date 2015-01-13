#include<iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        n--;
        while(n--){
        	string tmp = "";
        	int count = 0, cur = 0;
        	while(str[cur]){
        		count++;
        		if((!str[cur + 1]) || str[cur] != str[cur + 1]){
					tmp += to_string(count) + str[cur];
					count = 0;
				}
				cur++;
			}
			str = tmp;
		}
        return str;
    }
};

int main(){
	Solution sol;
    cout << sol.countAndSay(5) << endl;
	
    system("PAUSE");
    return 0;
}
