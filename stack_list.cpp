#include <iostream>
using namespace std;
struct elem
{
    int data;
    elem *next;
};
struct stack
{
    elem *top;
    stack( void ):top(NULL){}
};
bool isEmpty ( stack &s)
{
    if (s.top!=NULL) return false;
    return true;
}
void push ( stack &s, const int value)
{
    elem *temp = new elem;
    temp ->data = value;
    temp->next = s.top;
    s.top = temp;
}
void add ( stack &s, int n, int &average)
{
    srand(time(NULL));
    int value = 0;
    for (int i=0;i<n;i++)
    {
        value = rand()%10 +1;
        push (s,value);
        average+=value;
    }
    
}
bool pop(stack &s, int &out)
{
    if(!s.top)
        return false;
    if (!s.top->next)
    {
        out = s.top->data; delete s.top; s.top = NULL;
        return true;
    }
    elem*del=s.top;
    out = s.top->data;
    s.top = s.top->next;
    delete del;
    return true;
}
void vivod ( stack &s1, stack &s2)
{
    int value = 0;
    while (!isEmpty(s1))
        if (pop(s1,value))
        {
            cout<<value<<endl;
            push (s2,value);
        }
    
}
void del (stack &s1, stack &s2, int average)
{
    int value =0 ;
    while (!isEmpty(s2))
        
        if (pop(s2,value))
        {
            if (average!=value) push (s1,value);
        }
}
void clear ( stack &s)
{
    elem *del;
    while (s.top)
    {
        del =s.top;
        s.top = s.top -> next;
        delete s.top;
    }
}

int main() {
    stack s1;
    stack s2;
    int average = 0;
    int n ;
    cout<<"length of stack is ";
    cin>>n;
    add(s1,n,average);
    if(isEmpty(s1)) {cout<<"stack is empty"<<endl; exit(1);}
    cout<<"your stack"<<endl;
    vivod(s1, s2);
    cout<<"sum is ";
    cout<<average<<endl;
    average/=n;
    cout<<"average is ";
    cout<<average<<endl;
    del (s1,s2,average);
    if(isEmpty(s1)) {cout<<"stack is empty"<<endl; exit(1);}
    cout<<"new stack is"<<endl;
    vivod(s1,s2);
    clear (s1);
    clear (s2);
    return 0;
}

