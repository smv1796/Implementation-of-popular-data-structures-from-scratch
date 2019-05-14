//Implementing priority queue
#include<iostream>
#include<vector>
using namespace std;

class PQ
{
    vector<int> A;

public:
    int n;//number of elements in the queue.
    void insert_ele(int);
    void remove_max();
    int get_max();
    void heapify(int);
    PQ()
    {
      n=0;//number of elements in the queue.
      A.push_back(0);
    }

};

int PQ::get_max()
{
    if(!n) return -1;  //-1 indicates that no element is present n queue.
    else return A[1];
}

void PQ::insert_ele(int x)
{
    A.push_back(x);
    n++;
    int i=n;
    while((i/2)>=1 && A[i]>A[i/2])
    {
        swap(A[i],A[i/2]);
        i=i/2;
    }
}

void PQ::heapify(int i)
{
    int left=2*i;
    int right=2*i+1;

    int largest=i;
    if(left<n && A[left]>A[largest])
        largest=left;

    if(right<n && A[right]>A[largest])
        largest=right;

    if(largest!=i)
    {
        swap(A[i],A[largest]);
        heapify(largest);
    }

}
void PQ::remove_max()
{
    if(n==0)
    {
        cout<<"Queue is already empty"<<endl;
        return;
    }
    if(n==1)
    {
        A.pop_back();
        n--;
        return;
    }

    else
    {

        swap(A[1],A[n]);
        A.pop_back();
        n--;
        heapify(1);

    }
}

int main()
{
    PQ q;
    q.remove_max();
    q.insert_ele(4);
    cout<<q.get_max()<<endl;
    q.insert_ele(9);
    cout<<q.get_max()<<endl;
    q.insert_ele(42);
    q.insert_ele(9);
    q.insert_ele(17);
    q.insert_ele(24);
    cout<<q.get_max()<<endl;
    q.remove_max();
    cout<<q.get_max()<<endl;
}

