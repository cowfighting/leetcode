#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        if(S.empty() || T.empty()){
            return "";
        } 
        map<char, int> countS, countT;
        int lenT = T.length();
        int n = 0; 
        //countT保存各字符出现次数，n为字符不同个数 
        for(int i = 0; i < lenT; i++){
            if(countT[T[i]] == 0){
                n++;
            }
            countT[T[i]]++;
        }
        
        int lenS = S.length();
        //minLen保存最小窗口长度（初始化为lenS+1） 
        //start保存最小窗口其实位置
        //number记录当前已匹配字符数 
        int minLen = lenS + 1, start = 0, number = 0;
        for(int l = 0, r = 0; r < lenS; r++){
            countS[S[r]]++;
            //当前字符数已匹配 
            if(countS[S[r]] == countT[S[r]]){
                number++; 
            }
            //从左至右减少窗口长度
            while(number == n){
                //更新最小长度和起始位置 
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    start = l;
                }
                if(countS[S[l]] == countT[S[l]]){
                    number--;
                }
                countS[S[l]]--;
                l++;
            }
        }
        if(minLen <= lenS){
            return S.substr(start, minLen);
        }
        return "";
    }
};

int main(){
    string S = "ADOBECODEBANC";
    string T = "ABC";
   
    Solution sol;
    cout << sol.minWindow(S, T) << endl;
    
    system("PAUSE");
    return 0;    
}
