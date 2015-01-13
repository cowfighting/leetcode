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
        //countT������ַ����ִ�����nΪ�ַ���ͬ���� 
        for(int i = 0; i < lenT; i++){
            if(countT[T[i]] == 0){
                n++;
            }
            countT[T[i]]++;
        }
        
        int lenS = S.length();
        //minLen������С���ڳ��ȣ���ʼ��ΪlenS+1�� 
        //start������С������ʵλ��
        //number��¼��ǰ��ƥ���ַ��� 
        int minLen = lenS + 1, start = 0, number = 0;
        for(int l = 0, r = 0; r < lenS; r++){
            countS[S[r]]++;
            //��ǰ�ַ�����ƥ�� 
            if(countS[S[r]] == countT[S[r]]){
                number++; 
            }
            //�������Ҽ��ٴ��ڳ���
            while(number == n){
                //������С���Ⱥ���ʼλ�� 
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
