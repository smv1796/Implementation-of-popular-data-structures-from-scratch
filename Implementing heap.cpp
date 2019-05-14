//Implementing heap class from scratch.

#include<iostream>
#include<vector>
using namespace std;
using namespace std;
class Heap
{
    vector<int> A;
    int heapSize;
    public:
    Heap()
    {
        A.push_back(0);//Implementing a heap which is basically a vector where the first element of heap is stored at index 1
        heapSize=0;
    }

    void maxHeapify(int i);
    void insertHeap(int x);
    void popHeap();//Pops max element(root element) from the heap
    int maxElement();//As we are implementing max heap.
    int sizeofHeap();
};

void Heap::maxHeapify(int i)
{
    int largest=i;
    int left=2*i, right=(2*i)+1;

    if(left<heapSize && A[largest]<A[left])
        largest=left;

    if(right<heapSize && A[largest]<A[right])
        largest=right;

    if(largest!=i)
    {
        swap(A[largest],A[i]);
        maxHeapify(largest);
    }
}

void Heap::insertHeap(int x)
{
    A.push_back(x);
    heapSize++;
    int child=heapSize;

    while((child/2)>=1 &&A[child/2]<A[child])
    {
        swap(A[child/2],A[child]);
        child=child/2;
    }

}

void Heap::popHeap()
{
    swap(A[1],A[heapSize]);
    heapSize--;
    A.pop_back();
    maxHeapify(1);
}

int Heap::maxElement()
{
    return A[1];
}

int Heap::sizeofHeap()
{
    return heapSize;
}
int main()
{
   Heap H;
   H.insertHeap(1);
   H.insertHeap(2);
   H.insertHeap(3);
   cout<<H.sizeofHeap();
   H.popHeap();
   cout<<endl<<H.sizeofHeap();
   cout<<endl<<H.maxElement();
}
