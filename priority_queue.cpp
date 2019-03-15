//
//  main.cpp
//  приоритет
//
//  Created by Игорь on 3/11/19.
//  Copyright © 2019 Игорь. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct elem
{
    int data;
    unsigned int priority;
    elem *next;
};
struct priority_queue
{
    elem *back;
    priority_queue(void):back(NULL){}
};

bool compare (elem *prev, elem *next)
{
    return prev->priority>next->priority;
}
void push (priority_queue &q, const int value, const unsigned int &priority_value )
{
    elem *temp = new elem;
    temp ->data = value;
    temp -> priority = priority_value;
    temp ->next = NULL;
    if (!q.back)
    {
        q.back=temp;
        return;
    }
    elem *p = q.back,*prev = NULL;
    for ( ;p && compare(temp,p);prev=p,p=p->next);
    if (p==q.back)
    {
        temp->next=q.back;
        q.back=temp;
        return;
    }
    prev ->next =temp;
    if (!p)return;
    temp ->next = p;
    
    
    
}
void add (priority_queue &q, int n)
{
    int prior = 0;
    for (int i=0;i<n;i++)
    {
        int value = 0;
        value = rand ()%3+1;
        prior = rand ()%3+1;
            push(q, value, prior);
        cout<<value<<"("<<prior<<")"<<endl;
    }
}

priority_queue intersection(priority_queue &q1, priority_queue &q2, int n) {
    elem *first = q1.back;
    elem* second = q2.back;
    priority_queue result;
    while(first && second) {
        if (second->data == first->data && second->priority == first->priority) {
            push(result, first->data, first->priority);
            second = second->next;
            first = first->next;
        } else if (second->priority < first->priority) {
            second = second->next;
        } else {
            first = first->next;
        }
    }
    
    return result;
}
            
void print (priority_queue &result)
{
    cout<<"Answer"<<endl;
    elem *cursor = result.back;
    elem* prior = result.back;
    while (cursor)
    {
        cout<<cursor -> data;
        cout<<"("<<prior->priority<<")"<<endl;
        cursor = cursor->next;
        prior = prior->next;
        
    }
    cout<<endl;
}

int main()
{
    srand(time(NULL));
    int n;
    cout<<"Enter"<<endl;
    cout<<"n = ";
    cin>>n;
    priority_queue q1;
    priority_queue q2;
    priority_queue result;
    cout<<"queue1"<<endl;
    add(q1,n);
    cout<<"queue2"<<endl;
    add(q2,n);
    result =  intersection(q1, q2, n);
    print(result);
    
}
