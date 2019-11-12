#include <iostream>

using namespace std;
void Printforward();
void Printprevious();
void Insert(int m,int x,int n);

class Node
{
public:
    Node *next, *prev;
    int data;
};
Node *head=NULL, *tail=NULL;
int main()
{
    int n,i,x;
    cin>>n;
    Node *ptr;
    for(i=0; i<n; i++)
    {
        Node *newnode=new Node;
        cin>>x;
        if(head==NULL)
        {
            newnode->data=x;
            newnode->next=NULL;
            newnode->prev=NULL;
            head=newnode;
            ptr=newnode;
        }
        else
        {
            newnode->data=x;
            newnode->next=NULL;
            newnode->prev=ptr;
            if(i==n-1)tail=newnode;
            ptr->next=newnode;
            ptr=ptr->next;
        }
    }
    Printforward();
    Printprevious();
    int m;
    cin>>m>>x;
    Insert(m,x,n);
    Printforward();
    Printprevious();
    return 0;
}
void Printforward(){
    cout<<"Forward=> ";
    Node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
void Printprevious()
{
    cout<<"Backward=> ";
    Node *ptr=tail;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->prev;
    }
    cout<<endl;
}
void Insert(int m,int x,int n)
{
    int i=1;
    Node *ptr=head;
    while(i<m-1)
    {
        ptr=ptr->next;
        i++;
    }
    Node *newnode=new Node;
    newnode->data=x;
    newnode->prev=ptr;
    newnode->next=ptr->next;
    ptr->next=newnode;
    ptr=ptr->next->next;
    ptr->prev=newnode;
}
