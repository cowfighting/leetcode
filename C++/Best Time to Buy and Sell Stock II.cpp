#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if(size == 0 || size == 1){
			return 0;
		}
        int sum = 0;
        for(int i = 1; i < size; i++){
			if(prices[i] > prices[i - 1]){
				sum += prices[i] - prices[i - 1];
			}
		}
        return sum;
    }
};

int main(){
    vector<int> prices;
    prices.push_back(2);
    prices.push_back(5);
    prices.push_back(4);
    prices.push_back(7);
    
    Solution s;
    cout<<s.maxProfit(prices)<<endl;
    
    system("PAUSE");
    return 0;
}
