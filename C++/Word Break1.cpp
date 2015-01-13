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
        //cache[i]记录s[i..end]是否满足条件，0不满足，1满足，-1未处理 
        int* cache = new int[lenS + 1]; 
        for(int i = 0; i <= lenS; i++){
            cache[i] = -1;
        } 
        return wordBreak(s, dict, 0, lenS - 1, cache);
    }
    
    bool wordBreak(string s, set<string> &dict, int start, int end, int *cache){
        if(start > end){
            return true;
        }
        for(int i = start; i <= end; i++){
            string str = s.substr(start, i - start + 1);
            if(dict.find(str) != dict.end()){
                if(cache[i + 1] == -1){
                    cache[i + 1] = wordBreak(s, dict, i + 1, end, cache);
                }
                if(cache[i + 1]){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    string s = "aa";
    set<string> dict;
    dict.insert("ab");
    
    Solution sol;
    cout << sol.wordBreak(s, dict) << endl;
    
    system("PAUSE");
    return 0;
}
