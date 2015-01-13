#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > cache;
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        for(int i = 0; i < len1; i++){
            cache.push_back(vector<int>(len2, -1));
        }
        return dfs(len1 - 1, len2 - 1, word1, word2);
    }
    
    int dfs(int i, int j, string word1, string word2){
        //word1为null，则至少需1 + j步 
        if(i == -1){
            return 1 + j;
        }
        if(j == -1){
            return 1 + i;
        }
        if(cache[i][j] != -1){
            return cache[i][j];
        }
        int steps = dfs(i - 1, j, word1, word2) + 1;//删除 
        steps = min(steps, dfs(i, j - 1, word1, word2) + 1);//插入
        steps = min(steps, dfs(i - 1, j - 1, word1, word2) + (word1[i] != word2[j]));//替换
        return cache[i][j] = steps;
    }
};

int main(){
    string word1 = "prosperity";
    string word2 = "properties";
    Solution s;
    cout << s.minDistance(word1, word2) << endl;
    system("PAUSE");
    return 0;
}
