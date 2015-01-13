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
		//�������� 
		ans += to_string(num / denum);
		//���� 
		if(num % denum == 0){
			return ans;
		}
		ans += ".";
		//���� 
		num %= denum;
		//����������������Ϊkey����ǰ������λ��Ϊvalue�� 
		map<int, int> cache;
		while(num > 0){
			//�ж������Ƿ���ֹ������򷵻� 
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

