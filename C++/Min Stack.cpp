#include<iostream>
#include<stack>
using namespace std;

class MinStack {
    stack<int> s;
    stack<int> minS;
public:
    void push(int x) {
        if(minS.empty() || x <= minS.top()){
            minS.push(x);
        }
        s.push(x);
    }

    void pop() {
        if(!s.empty()){
            if(s.top() == minS.top()){
                minS.pop();
            }
            s.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minS.top();
    }
};

int main()
{
    MinStack ms;
    ms.push(-1);
    ms.push(-3);
    ms.push(-3);
    ms.pop();
    ms.pop();
    cout<<ms.getMin()<<endl;

    system("PAUSE");
	return 0;
}
