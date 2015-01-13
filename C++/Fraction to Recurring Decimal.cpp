#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    	int64_t num = numerator;
    	int64_t denum = denominator;
    	if(denum == 0){
        	return "";
		}
        if(num == 0){
        	return "0";
		}
		string ans = "";
		if(num < 0 ^ denum < 0){
			ans += "-";
		}
		if(num < 0){
			num = -num;
		}
		if(denum < 0){
			denum = -denum;
		}
		//整数部分 
		ans += to_string(num / denum);
		//整除 
		if(num % denum == 0){
			return ans;
		}
		ans += ".";
		//余数 
		num %= denum;
		//保存余数，（余数为key，当前所得商位置为value） 
		map<int, int> cache;
		while(num > 0){
			//判断余数是否出现过，是则返回 
			if(cache.find(num) != cache.end()){
				ans.insert(cache[num], "(");
				ans += ")";
				break;
			}
			cache[num] = ans.size();
			
			num *= 10;
			ans += to_string(num / denum);
			num %= denum;
		}
		return ans;
    }
};

int main(){
    Solution sol;
    cout << sol.fractionToDecimal(-1, -99)<< endl;
    
    system("PAUSE");
    return 0;
}

