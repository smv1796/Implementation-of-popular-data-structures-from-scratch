//Implementing linked list
#include<iostream>
using namespace std;
class ListNode//defines the structure of node of the list
{
public:

    int val;
    ListNode* next;

    ListNode(int x)
    {
        val=x;
        next=NULL;
    }
};
class Llist
{

  public:
    ListNode* head, *tail;

    Llist(int x)
    {
        head=new ListNode(x);
        tail=head;
    }

    Llist()//In case someone wants to create a NULL list. Once created we cannot add further more elements in this list
    {
        head=NULL;
        tail=NULL;
    }

    void addNode(int x);
    void printNode();
    void printReverse(ListNode*);
    void reverseIterative();
    void reverseRecursive(ListNode*,ListNode*);
    void delNode(int x);//Deletes the node with value x. If x is not present, list will remain intact
};

void Llist::addNode(int x)
{

    ListNode* n=new ListNode(x);
    if(!head)
    {
        head=n;
        tail=n;
    }
    else
    {
        tail->next=n;
        tail=n;
    }
}

void Llist::delNode(int x)
{
    if(!head) return;
    ListNode* curr=head,*prev=NULL;
    if(!head->next && head->val==x)//Edge case
    {
        head=NULL;
        tail=NULL;
        return;
    }
    while(curr)
    {
        bool flag1=false;//True if the node to be deleted is the head node.
        bool flag2=false;// True if node to be deleted is the last node.
        if(curr->val==x)
        {
            if(curr==head) flag1=true;
            if(!curr->next) flag2=true;
            ListNode* temp=curr;
            prev->next=curr->next;
            delete temp;

        }

        else
            prev=curr;

        curr=curr->next;//Will run even when if condition is true
        if(flag1)
            head=curr;

        if(flag2) prev;

    }
}

void Llist::printNode()
{
    ListNode* temp=head;
    cout<<"\n";
    while(temp)
    {
        cout<<temp->val<<" ";
        temp=(*(temp)).next;
    }
}

void Llist::printReverse(ListNode* temp)
{
    if(!temp) return;
    printReverse(temp->next);
    cout<<temp->val<<" ";
}

void Llist::reverseIterative()
{
    ListNode* curr=head,*prev=NULL,*next;

    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    head=prev;
}

void Llist::reverseRecursive(ListNode* prev,ListNode* curr)
{
    if(!(curr->next)) {
            curr->next=prev;
            head=curr;
            return;
    }
    reverseRecursive(curr,curr->next);
    curr->next=prev;
}


int main()
{
  Llist L(17);
  L.addNode(109);
  L.addNode(1996);
  L.addNode(76);
  L.addNode(9);
  L.addNode(6576);
  L.addNode(4);
  L.delNode(1996);
  L.printNode();
  cout<<"\n";
  L.printReverse(L.head);
  L.reverseIterative();
  cout<<"\n";
  L.printNode();
  L.reverseRecursive(NULL,L.head);
  cout<<endl;
  L.printNode();
}
