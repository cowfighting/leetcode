#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, set<string> &dict) {
        int lenS = s.length();
        int sizeDict = dict.size();
        if(sizeDict == 0 ^ lenS == 0){
            return false;
        }
        //dp[i]��ʾs[0...i]�Ƿ����� 
        bool* dp = new bool[lenS];
        for(int i = 0; i < lenS; i++){
            dp[i] = false;
        }
        //cur��ʾ��ǰɨ��ָ�� 
        int cur = 0;
        while(s[cur]){
            //��ǰѰ���ϸ����������Ľ����� 
            int pre = cur;
            while(pre != -1){
                pre--;
                if(pre == -1 || dp[pre]){
                    string str = s.substr(pre + 1, cur - pre);
                    if(dict.find(str) != dict.end()){
                        dp[cur] = true;
                        break;
                    }
                }
            }
            cur++;
        }
        return dp[lenS - 1];
    }
};

int main(){
    string s = "aaa";
    set<string> dict;
    dict.insert("a");
    dict.insert("a");
    
    Solution sol;
    cout << sol.wordBreak(s, dict) << endl;
    
    system("PAUSE");
    return 0;
}
