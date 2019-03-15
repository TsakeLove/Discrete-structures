//
//  main.cpp
//  dvostor
//
//  Created by Игорь on 2/24/19.
//  Copyright © 2019 Игорь. All rights reserved.
//

#include <iostream>
using namespace std;

struct queue {
    int *data;
    int max_size, size;
    int back, front;
    int nom = 0;
    queue (int n = 0) : max_size (n) ,size (0)
    {
        data = new int [max_size];
        for ( int i=0;i<max_size;i++)
            data [i]=0;
        back = front =max_size-1;
      
    }
};

void push_back ( queue&q, const int value)
{
    if (q.size>=q.max_size){
        cout<<"stack overload"<<endl; exit (1);
        
    }

    q.data[q.back]=value;
    q.back=(q.back+q.max_size-1)%q.max_size;
    q.size++;
    
   /* cout << "====================================" << endl;
    cout << "Adding " << value << endl;*/
   /*for (int i = 0; i < q.max_size;i++ ) {
        cout << q.data[i] << " ";
    }
    cout << endl;
    */
   // return q.data[q.back];
}
void push_front ( queue &q, const int value)
{
    if (q.size>=q.max_size) { cout<<"stack overload"<<endl; exit (1);}
    q.front=(q.front+1)%q.max_size;
    q.data[q.front++]=value;
    q.size++;
}
bool pop_back ( queue &q, int &out)
{
    if (!q.size)
        return false;
    q.back=(q.back+1)%q.max_size;
    out=q.data[q.back];
    q.size--;
    return true;
}
bool pop_front ( queue &q, int &out)
{
    if (!q.size) return false;
    out=q.data[q.front];
    q.front = (q.front+q.max_size-1)%q.max_size;
    q.size--;
    return true;
}
void print (queue result)
{
    cout<<"Answer"<<endl;
    int i = result.back;
    for ( int k=1;k<=result.size;k++)
    {
        i=(i+1)%result.max_size;
        cout<<result.data[i]<<endl;
        
    }
   
}
void add (queue qs[], int n, int k)
{
    for (int i = 0; i<n; i++) {
        int nom = i+1;
        cout<<"steck"<<nom<<endl;
        qs[i] = queue(k);
       
        for(int j = 0; j < k; j++) {
             int value = rand() % 100;
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
int main() {
    srand(time(NULL));
    cout<<"enter n ";
    int n;
    cin>>n;
    cout<<"enter rozmir ";
    int k;
    cin>>k;
    queue qs[n] ;
    queue result(n * k);
    add(qs,n,k);
    res(result,qs,n,k);
    print (result);
    return 0;
}
