#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        vector<int>::iterator it = num.begin();
        int label = 1, ans = *it;
        it++;
        while(it != num.end()){
            if(*it != ans){
                label--;
            } else {
                label++;
            }
            if(label == 0){
                label = 1;
                ans = *it;
            }
            it++;
        }
        return ans;
    }    
};

int main(){
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    num.push_back(2);
    
    Solution sol;
    cout << sol.majorityElement(num)<< endl;
    
    system("PAUSE");
    return 0;
}
