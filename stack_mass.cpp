//
//  main.cpp
//  stak
//
//  Created by Игорь on 2/16/19.
//  Copyright © 2019 Игорь. All rights reserved.
//

#include <iostream>
using namespace std;
struct stack
{
    int size;
    int last;
    int *data;
    
    stack(int n )
    {
        
        size = n;
        last = 0;
        data = new int [size];
        
    }
    
    
};
bool isEmpty (stack &s)
{
    if (s.last<1)
        return true;
    return false;
}
void push ( stack &s, const int value )
{
    if (s.last==s.size)
    {
        cout<<"stack overload"<<endl;
        exit (1);
    }
    
    s.data[s.last++]=value;
    
    
}
bool pop ( stack &s, int &out)
{
    if (s.last<1)
        return false;
    
    
    out = s.data[--s.last];
    
    
    return true;
    
}
void vvod (stack &s, int &average)
{
  
    for (int i=0;i<s.size;i++)
    {
        
        int value = 0;
        cin>>value;
        push(s, value );
        average+=value;
    }
      if(isEmpty(s)) {cout<<"stack is empty"<<endl; exit(1);}
    
}
void vivod (stack &s1, stack &s2)
{
    
    
   while(!isEmpty(s1))
    {
        
        
        if (pop(s1,s1.data[s1.last]))
        {
            cout<<s1.data[s1.last]<<endl;
            push(s2,s1.data[s1.last]);
        }
    }
      if(isEmpty(s2)) {cout<<"stack is empty"<<endl; exit(1);}
    
}
void del (stack &s1, stack &s2, int average)
{
    
    while(!isEmpty(s2))
    {
        if (pop(s2,s2.data[s2.last]))
        {
            if (s2.data[s2.last]==average)
            {
                s2.size--;
            }
                else push(s1,s2.data[s2.last]);
        }
        
    }
}
void clear (stack &s)
{
     while(!isEmpty(s))
     {
         pop(s,s.data[s.last]);
     }
}
int main ()
{
    int average = 0;
    int n;
    cout<<"n = ";
    cin>>n;
    stack s1(n);
    stack s2(n);
    vvod(s1,average);
    cout<<"stack items"<<endl;
    vivod(s1,s2);
    cout<<"sum is ";
    cout<<average<<endl;
    average/=s2.size;
    cout<<"average is ";
    cout<<average<<endl;
    del(s1,s2,average);
    cout<<"new stack size is "<<s2.size<<endl;
    vivod(s1,s2);
    clear(s2);
    delete s1.data;
    delete s2.data;
}
