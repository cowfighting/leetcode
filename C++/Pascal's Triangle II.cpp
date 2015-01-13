#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /*vector<int> getRow(int rowIndex) {
		int** arr = new int*[rowIndex + 1];
		for(int i = 0; i <= rowIndex; i++ ){
			arr[i] = new int[rowIndex + 1];
			for(int j = 0; j <= i; j++ ){
				if( j == 0 || j == i){
					arr[i][j] = 1;
				}else{
					arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
				}
			}			
		}
		vector<int> vec;
		for(int i = 0; i <= rowIndex; i++ ){
			vec.push_back(arr[rowIndex][i]);
		}
        return vec;
    }*/
    vector<int> getRow(int rowIndex) {
        vector<int> vec(rowIndex + 1,1);
        for(int i = 1; i <= rowIndex; i++){
            vec[i] = 1;
            for(int k = i - 1; k > 0; k--){
                vec[k] = vec[k] + vec[k - 1];
            }
        }
        return vec;
    } 
};

int main(){
    Solution s;
    vector<int> vec = s.getRow(13);
    
    vector<int>::iterator it;
    for(it = vec.begin(); it != vec.end(); it++){
		cout << *it << " ";
	}
    cout << endl;
    system("PAUSE");
    return 0;
}
