#include<iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int cur1 = 0, cur2 = 0;
        while(version1[cur1] || version2[cur2]){
            int int1 = 0;
            while(version1[cur1] && version1[cur1] != '.'){
                int1 = 10 * int1 + version1[cur1] - '0'; 
                cur1++;
            }
            int int2 = 0;
            while(version2[cur2] && version2[cur2] != '.'){
                int2 = 10 * int2 + version2[cur2] - '0';
                cur2++;
            }
            if(int1 < int2){
                return -1;
            } else if(int1 > int2){
                return 1;
            }
            if(version1[cur1] == '.'){
                cur1++;
            }
            if(version2[cur2] == '.'){
                cur2++;
            }
        }
        return 0; 
    }
};

int main(){
    Solution sol;
    cout << sol.compareVersion("1", "1.00")<< endl;
    
    system("PAUSE");
    return 0;
}
