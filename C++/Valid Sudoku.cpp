#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i = 0; i < 9; i++){
        	//表示第i行中数字j是否已存在 
        	bool isExistRow[9][10] = {0};
        	//表示第i列中数字j是否已存在 
        	bool isExistColumn[9][10] = {0};
        	for(int j = 0; j < 9; j++){
        		//判断每行是否有效 
        		int valueij = board[i][j] == '.' ? 0 : (board[i][j] - '0');
        		if(valueij != 0 && isExistRow[i][valueij]){
        			return false;
				}
				isExistRow[i][valueij] = true;
				
				//判断每列是否有效 
				int valueji = board[j][i] == '.' ? 0 : (board[j][i] - '0');
        		if(valueji != 0 && isExistColumn[i][valueji]){
        			return false;
				}
				isExistColumn[i][valueji] = true;
				
				//判断子数独是否有效
				if(i % 3 == 0 && j % 3 == 0){
					if(!isValidSub(board, i, j)){
						return false;
					}
				}
			}
		}
		return true;
    }
    
    //判定以i,j为起始点的子数独是否有效 
    bool isValidSub(vector<vector<char> > &board, int i, int j){
    	bool nine[10] = {0};
    	for(int s = i; s < i + 3; s++){
			for(int e = j; e < j + 3; e++){
				int value = board[s][e] == '.' ? 0 : (board[s][e] - '0');
				if(value != 0 && nine[value]){
					return false;
				}
				nine[value] = true;
			}
		}
		return true;
	}
};

int main(){
	char chars1[] = {'.','8','7','6','5','4','3','2','1'};
	vector<char> row1(chars1, chars1 + sizeof(chars1) / sizeof(char));
	
	char chars2[] = {'2','.','.','.','.','.','.','.','.'};
	vector<char> row2(chars2, chars2 + sizeof(chars2) / sizeof(char));
	
	char chars3[] = {'3','.','.','.','.','.','.','.','.'};
	vector<char> row3(chars3, chars3 + sizeof(chars3) / sizeof(char));
	
	char chars4[] = {'4','.','.','.','.','.','.','.','.'};
	vector<char> row4(chars4, chars4 + sizeof(chars4) / sizeof(char));
	
	char chars5[] = {'5','.','.','.','.','.','.','.','.'};
	vector<char> row5(chars5, chars5 + sizeof(chars5) / sizeof(char));
	
	char chars6[] = {'6','.','.','.','.','.','.','.','.'};
	vector<char> row6(chars6, chars6 + sizeof(chars6) / sizeof(char));
	
	char chars7[] = {'7','.','.','.','.','.','.','.','.'};
	vector<char> row7(chars7, chars7 + sizeof(chars7) / sizeof(char));
	
	char chars8[] = {'8','.','.','.','.','.','.','.','.'};
	vector<char> row8(chars8, chars8 + sizeof(chars8) / sizeof(char));
	
	char chars9[] = {'9','.','.','.','.','.','.','.','.'};
	vector<char> row9(chars9, chars9 + sizeof(chars9) / sizeof(char));
	
	vector<vector<char> > board;
	board.push_back(row1);
	board.push_back(row2);
	board.push_back(row3);
	board.push_back(row4);
	board.push_back(row5);
	board.push_back(row6);
	board.push_back(row7);
	board.push_back(row8);
	board.push_back(row9);
	
	Solution sol;
	cout << sol.isValidSudoku(board) << endl;
	
	system("PAUSE");
	return 0;
}
