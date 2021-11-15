//This program is aimed at calculating the 
//Weighted Path Length of a huffman tree.
#include<iostream>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    ~node(){};
    node(){};
    node(int x):data(x),left(NULL),right(NULL){};
};
void printTree(node* nd)
{
    // if(!nd) return;
    if(nd)
    {
        cout<<nd->data;
        if(nd->left||nd->right)
        {
            cout<<"(";
            printTree(nd->left);
            if(nd->right)
                cout<<",";
            printTree(nd->right);
            cout<<")";
        }
    }
}

node* createTree(int* a,int n)
{
    node* b[n];
    for(int i=0;i<n;i++)
    {
        b[i]=new node(a[i]);
    }
    node* q=new node;
}
