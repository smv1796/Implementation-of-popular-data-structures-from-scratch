#include<iostream>
using namespace std;
class BSTNode
{
    public:
    int data;
    BSTNode* left,*right;

    BSTNode(int d)
    {
        data=d;
        right=NULL;
        left=NULL;
    }
};

class BST
{
    public:
    BSTNode* root;

    BST(int d)
    {
        BSTNode* p=new BSTNode(d);
        root=p;
    }

    BSTNode* addNode(BSTNode*,int);
    BSTNode* delNode(BSTNode*,int);
    BSTNode* searchNode(BSTNode*,int);//If present return its pointer
    void inorder(BSTNode*);
};
void BST::inorder(BSTNode* root)
{
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
BSTNode* BST::addNode(BSTNode* root, int x)
{
    if(!root)
    {
        BSTNode* n=new BSTNode(x);
        return n;
    }

    if(root->data>x)
        root->left=addNode(root->left,x);
    else root->right=addNode(root->right,x);

    return root;
}

BSTNode* BST::searchNode(BSTNode* root,int x)
{
    if(!root) return NULL;

    if(root->data==x)
        return root;
    if(x<root->data)
        return searchNode(root->left,x);
  else return searchNode(root->right,x);
}

int inorderval(BSTNode* root)
{
   while(root->left)
        root=root->left;
   return root->data;
}
BSTNode* BST::delNode(BSTNode* root, int x)
{
    if(!root) return NULL;

    if(x<root->data)
    root->left=delNode(root->left,x);

    else if(x>root->data)
    root->right=delNode(root->right,x);

    else
    {
        //case 1
        if(!root->left && !root->right)
        {
           delete root;
           return NULL;
        }

        //Case 2 Both child
        else if(root->left && root->right)
        {
            int x=inorderval(root->right);
            root->data=x;
            root->right=delNode(root->right,x);
            return root;
        }

        else if(root->right)
        {
            BSTNode* temp=root;
            temp=NULL;
            delete temp;
            return root->right;
        }

        else if(root->left)
        {

            BSTNode* temp=root;
            temp=NULL;
            delete temp;
            return root->left;
        }
    }


    return root;
}

int main()
{
    BST p(10);
    p.inorder(p.root);
    p.root=p.addNode(p.root,5);
    p.root=p.addNode(p.root,25);
    p.root=p.addNode(p.root,8);
    p.root=p.addNode(p.root,78);
    p.root=p.addNode(p.root,43);
    p.root=p.addNode(p.root,3);
    p.root=p.addNode(p.root,9);
    cout<<endl;
    p.inorder(p.root);
    p.root=p.delNode(p.root,5);
    cout<<endl;
    p.inorder(p.root);



}
