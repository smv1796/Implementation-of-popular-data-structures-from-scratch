//Implementing stacks class supporting "pop", "push" and "top" functions.
#include<iostream>
#include<vector>
using namespace std;
class stack1//To avoid confusion as there already a stack class in STL
{
    vector<int> A;
 public:
    void pop()
    {
        A.pop_back();
    }

    void push(int x)
    {
        A.push_back(x);
    }

    int top()
    {
      if(!A.size()) return INT_MIN;//If stack is empty.
      else return A[A.size()-1];

    }

    int size()
    {
        return A.size();
    }
};
int main()
{
    stack1 S;
    S.push(2);
    S.push(87);
    S.push(-19);
    S.push(677);
    S.push(7);
    S.push(76);
    S.pop();
    cout<<S.top()<<" "<<S.size();
    return 0;
}
