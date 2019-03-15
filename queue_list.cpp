//
//  main.cpp
//  dvolist
//
//  Created by Игорь on 2/27/19.
//  Copyright © 2019 Игорь. All rights reserved.
//

#include <iostream>
using namespace std;
struct elem
{
    int data;
    elem *prev;
    elem *next;
};
struct queue
{
    elem *back;
    elem *front;
    queue (void):back(NULL), front (NULL){}
};
void push_back (queue &q, const int value)
{
    elem *temp =new elem;
    temp->data=value;
    temp->prev=NULL;
    if (!q.back)
    {
        q.back = q.front = temp;
        temp -> next = NULL;
        
    }
    else
    {
        temp -> next =q.back;
        q.back->prev=temp;
        q.back=temp;
    }
    
}
void push_front ( queue &q, const int value)
{
    elem *temp=new elem;
    temp->data=value;
    temp->next=NULL;
    if (!q.front)
    {
        q.front = q.back = temp;
        temp -> prev = NULL;
    }
    else
    {
        temp->prev=q.front;
        q.front->next=temp;
        q.front = temp;
    }
}
bool pop_back ( queue &q, int &out)
{
    if (!q.back)
        return false;
    if (!q.back->next)
    {
        out = q.back ->data;
        delete q.back;
        q.back=q.front=NULL;
        return true;
    }
    elem *del = q.back;
    out = q.back->data;
    q.back = q.back->next;
    delete del;
    q.back->prev=NULL;
    return true;
}
bool pop_front ( queue &q, int &out)
{
    if (!q.front)
        return false;
    if (!q.front->prev)
    {
        out = q.front ->data;
        delete q.front;
        q.back=q.front=NULL;
        return true;
    }
    elem *del = q.front;
    out = q.front->data;
    q.front = q.front -> prev;
    delete del;
    q.front -> next= NULL;
    return true;
}
void add (queue qs[], int n, int k)
{
    int num = 1;
    for (int i=0;i<n;i++){
        cout<<"stack"<<num+i<<endl;
        for(int j = 0; j < k; j++) {
            
            int value = rand() % 10+1;
            push_back(qs[i],value);
            cout<<value<<" "<<endl;
    }
    }
    }
void res ( queue &result, queue qs[], int n, int k)
{
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            int x;
            pop_front(qs[i], x);
            push_back(result, x);
        }
    }
}
void print (queue &result)
{
    cout<<"Answer"<<endl;
    elem *cursor = result.back;
    while (cursor)
    {
        cout<<cursor -> data<<endl;
        cursor = cursor->next;
    }
    cout<<endl;
}
int main()
{
    srand(time(NULL));
    cout<<"enter n ";
    int n;
    cin>>n;
    cout<<"enter rozmir ";
    int k;
    cin>>k;
    queue q;
    queue qs[n] ;
    queue result;
    add(qs,n,k);
    res (result, qs,n,k);
    print (result);
}
