#include<iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int cur1 = 0, cur2 = 0;
        while(version1[cur1] && version2[cur2]){
            int pos1 = cur1;
            while(version1[pos1] && version1[pos1] != '.'){
                pos1++;
            }
            int pos2 = cur2;
            while(version2[pos2] && version2[pos2] != '.'){
                pos2++;
            }
            int int1 = strToInt(version1.substr(cur1, pos1 - cur1));
            int int2 = strToInt(version2.substr(cur2, pos2 - cur2));
            if(int1 < int2){
                return -1;
            } else if(int1 > int2){
                return 1;
            }
            if(version1[pos1] == '.'){
                cur1 = pos1 + 1;
            } else {
                cur1 = pos1;
            }
            if(version2[pos2] == '.'){
                cur2 = pos2 + 1;
            } else {
                cur2 = pos2;
            }
        }
        if(!version1[cur1] && !version2[cur2]){
            return 0;
        } else if(version1[cur1]){
            int pos1 = cur1;
            while(version1[pos1] && version1[pos1] != '.'){
                pos1++;
            }
            int int1 = strToInt(version1.substr(cur1, pos1 - cur1));
            if(int1 == 0){
                return 0;
            }
            return 1;
        } else {
            int pos2 = cur2;
            while(version2[pos2] && version2[pos2] != '.'){
                pos2++;
            }
            int int2 = strToInt(version2.substr(cur2, pos2 - cur2));
            if(int2 == 0){
                return 0;
            }
            return -1;
        }
    }
    
    int strToInt(string str){
        int len = str.length();
        int base = 1, sum = 0;
        while(len--){
            sum += (str[len] - '0') * base;
            base *= 10;
        }
        return sum;
    }
};

int main(){
    Solution sol;
    cout << sol.compareVersion("1", "1.00")<< endl;
    
    system("PAUSE");
    return 0;
}
