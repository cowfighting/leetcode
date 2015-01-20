#include<iostream>
#include<vector>
using namespace std;

struct Number {
	int value;//值
	int index;//原始下标
	Number(int v, int i) : value(v), index(i) {}
};

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> ans;
		int size = numbers.size();
    	if(size <= 1) {
    		return ans;
		}
		vector<Number*> nums;
		for(int i = 0; i < size; i++) {
			nums.push_back(new Number(numbers[i], i));
		}
		quickSort(nums, 0, size - 1);
		int left = 0, right = size - 1;
		while(left < right) {
			int sum = nums[left]->value + nums[right] ->value;
			if(sum == target) {
				int index1 = nums[left]->index;
				int index2 = nums[right]->index;
				if(index1 > index2) {
					index1 = index1 + index2;
					index2 = index1 - index2;
					index1 = index1 - index2;
				}
				ans.push_back(index1 + 1);
				ans.push_back(index2 + 1);
				return ans;
			}
			if(sum > target) {
				right--;
			} else {
				left++;
			}
		}
		cout << endl;
		return ans;
    }
    
    void quickSort(vector<Number*> &numbers, int start, int end) {
    	if(start < end) {
    		int pivotPos = partition(numbers, start, end);
    		quickSort(numbers, start, pivotPos - 1);
    		quickSort(numbers, pivotPos + 1, end);
		}
	}
	
	int partition(vector<Number*> &numbers, int start, int end) {
		int left = start, right = end;
		Number *pivot = numbers[start];
		while(left < right) {
			while(left < end && compare(numbers[left], pivot) <= 0) {
				left++;
			}
			while(right > start && compare(numbers[right], pivot) >= 0) {
				right--;
			}
			if(left < right) {
				Number *tmp = numbers[left];
				numbers[left] = numbers[right];
				numbers[right] = tmp;
			}
		}
		numbers[start] = numbers[right];
		numbers[right] = pivot;
		return right;
	}
    
    int compare(Number *x, Number *y) {
    	if(x->value == y->value) {
    		return 0;
		} else if(x->value > y->value) {
			return 1;
		} else {
			return -1;
		}
	}
};
 
int main() {
	int num[] = {1,2,10,8,9};
 	vector<int> numbers(num, num + sizeof(num) / sizeof(int));
 	
	Solution sol;
	vector<int> ans = sol.twoSum(numbers, 9);
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	
 	system("PAUSE");
 	return 0;
}
