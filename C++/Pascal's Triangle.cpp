#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vec;
        vector<int> vecI;
        for(int i = 0;i < numRows; i++){
            vecI.push_back(1);
            for(int j = i - 1; j > 0; j--){
                vecI[j] = vecI[j] + vecI[j - 1];
            }
            vec.push_back(vecI);
        }
        return vec;
    }
};

int main(){
    Solution s;
    vector<vector<int> > vec = s.generate(0);
    
    vector<vector<int> >::iterator it;
    for(it = vec.begin(); it != vec.end(); it++){
        vector<int> sub = *it;
        vector<int>::iterator subIt;
        for(subIt = sub.begin(); subIt != sub.end(); subIt++){
            cout<<*subIt<<" ";
        }
        cout<<endl;
	}
    cout << endl;
    system("PAUSE");
    return 0;
}
